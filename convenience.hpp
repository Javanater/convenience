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

    auto _to_path(::boost::filesystem::directory_entry& entry)
    {
        return entry.path();
    }
    
    BOOST_PHOENIX_ADAPT_FUNCTION(::boost::filesystem::path, to_path, _to_path, 1);    

    auto path_iterator(::boost::filesystem::path p)
    {
        using ::boost::filesystem::directory_iterator;
        using ::boost::adaptors::transformed;
        using ::boost::phoenix::placeholders::_1;
        return directory_iterator(p) | transformed(to_path(_1));
    }
}

#endif
