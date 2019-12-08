#ifndef __convenience__
#define __convenience__

//std
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <stack>
#include <sstream>
#include <memory>
#include <thread>
#include <mutex>

//boost
#include <boost/filesystem.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/format.hpp>
#include <boost/assign.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/phoenix.hpp>
#include <boost/regex.hpp>
#include <boost/hof.hpp>
#include <boost/mem_fn.hpp>
#include <boost/any.hpp>
#include <boost/chrono.hpp>
#include <boost/date_time.hpp>

#include <boost/date_time.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/program_options.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>
#include <boost/accumulators/statistics/rolling_sum.hpp>
#include <boost/accumulators/statistics/rolling_mean.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/thread.hpp>
#include <boost/circular_buffer.hpp>
#include <boost/lockfree/spsc_queue.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/signals2.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/karma.hpp>
#include <boost/fusion/adapted.hpp>
#include <boost/random.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/uniform_01.hpp>
#include <boost/random/uniform_real_distribution.hpp>
#include <boost/optional.hpp>

namespace convenience
{
inline boost::regex operator "" _r(char const* c_str, size_t)
{
    return boost::regex(c_str);
}

inline boost::format operator "" _f(char const* c_str, size_t)
{
    return boost::format(c_str);
}

static auto path_iterator(boost::filesystem::path p)
{
    using boost::filesystem::directory_iterator;
    using boost::adaptors::transformed;
    return
        directory_iterator(p) |
        transformed([](auto& e){return e.path();})
        ;
}

static auto recursive_path_iterator(boost::filesystem::path p)
{
    using boost::filesystem::recursive_directory_iterator;
    using boost::adaptors::transformed;
    return
        recursive_directory_iterator(p) |
        transformed([](auto& e){return e.path();})
        ;
}

inline bool regex_match_str(std::string s, boost::regex r)
{
    return boost::regex_match(s, r);
}

inline bool regex_match_str(boost::filesystem::path s, boost::regex r)
{
    return boost::regex_match(s.generic_string(), r);
}

BOOST_PHOENIX_ADAPT_FUNCTION(bool, regex_match, regex_match_str, 2);

BOOST_PHOENIX_ADAPT_FUNCTION(bool, is_regular_file,
	boost::filesystem::is_regular_file, 1);

inline std::string slurp(boost::filesystem::path file)
{
    boost::filesystem::ifstream in(file);
    std::stringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}

static auto istream_range(std::istream& is)
{
	return boost::make_iterator_range(
		boost::spirit::istream_iterator(is),
		boost::spirit::istream_iterator()
	);
}

template<class T = char>
static auto istreambuf_range(std::istream& is)
{
	return boost::make_iterator_range(
		std::istreambuf_iterator<T>(is),
		std::istreambuf_iterator<T>()
	);
}

template<class Range, class Expr, class Skipper>
inline bool phrase_parse(Range range, Expr& parser, Skipper const& skipper)
{
	return boost::spirit::qi::phrase_parse(std::begin(range), std::end(range),
		parser, skipper);
}

template<class Expr, class Skipper>
inline bool phrase_parse(boost::filesystem::path path, Expr& parser,
	Skipper const& skipper)
{
	boost::filesystem::ifstream ifs(path);
	return phrase_parse(istream_range(ifs), parser, skipper);
}

template<class Expr>
inline bool phrase_parse(boost::filesystem::path path, Expr& parser)
{
	boost::filesystem::ifstream ifs(path);
	return phrase_parse(istream_range(ifs), parser,
			boost::spirit::qi::blank);
}

BOOST_HOF_STATIC_LAMBDA_FUNCTION(auto_make_tuple) = [](auto... as)
{
	return make_tuple(as...);
};

class unwinder : public std::stack<boost::function<void()>>
{
public:
	typedef std::stack<boost::function<void()>> base;
	typedef base::container_type container_type;

	unwinder()
    {
    }

	explicit unwinder(const container_type& ctnr) : base(ctnr)
    {
    	while (!empty())
    	{
    		top()();
    		pop();
    	}
    }

	~unwinder()
    {
    }
};

// class glob_iterator : boost::iterator_facade<glob_iterator, directory_entry, boost::forward_traversal_tag>
// {
// private:
// 	regex expression;
// 	recursive_directory_iterator iterator;

// public:
// 	glob_iterator()
// 	{
// 	}

// 	glob_iterator(glob_iterator& other) : expression(other.expression),
// 		iterator(other.iterator)
// 	{
// 	}

// 	glob_iterator(regex expression) : expression(expression)
// 	{
// 		path root(expression.str());
// 		root = absolute(root).root_name().generic_string() + '/';
// 		iterator = recursive_directory_iterator(root);
// 	}

// 	directory_entry dereference()
// 	{
// 		return *iterator;
// 	}

// 	bool equal(glob_iterator const& other) const
// 	{
// 		return iterator == other.iterator && expression == other.expression;
// 	}

// 	void increment()
// 	{
// 		do
// 		{
// 			if (!iterator.no_push_pending())
// 			{
// 				if (!regex_match(dereference().path().generic_string(),
// 					expression, match_partial))
// 					iterator.no_push();
// 			}

// 			++iterator;
// 		}
// 		while (iterator != recursive_directory_iterator() && 
// 			regex_match(dereference().path().generic_string(), expression));
// 	}
// };
}

#endif
