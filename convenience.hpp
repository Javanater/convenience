#ifndef __convenience__
#define __convenience__

//std
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <list>

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
#include <boost/lexical_cast.hpp>
#include <boost/gil.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>

// range-v3
#include <range/v3/all.hpp>

namespace convenience
{
    boost::regex operator "" _r(char const* c_str, size_t)
    {
        return boost::regex(c_str);
    }

    boost::format operator "" _f(char const* c_str, size_t)
    {
        return boost::format(c_str);
    }

    auto path_iterator(boost::filesystem::path p)
    {
        using boost::filesystem::directory_iterator;
        using boost::adaptors::transformed;
        return
            directory_iterator(p) |
            transformed([](auto& e){return e.path();})
            ;
    }

    bool regex_match_str(std::string s, boost::regex r)
    {
        return boost::regex_match(s, r);
    }

    bool regex_match_str(boost::filesystem::path s, boost::regex r)
    {
        return boost::regex_match(s.generic_string(), r);
    }

    BOOST_PHOENIX_ADAPT_FUNCTION(bool, regex_match, regex_match_str, 2);

    auto path_range(boost::filesystem::path p)
    {
        using boost::filesystem::directory_iterator;
        using ranges::view::transform;
        using ranges::make_iterator_range;
        return
            make_iterator_range(directory_iterator(p), directory_iterator()) |
            transform([](auto& e){return e.path();})
            ;
    }
}

#endif
