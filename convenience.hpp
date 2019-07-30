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

    //boost::filesystem::path _to_path(boost::filesystem::directory_entry entry)
    //{
    //    return entry.path();
    //}

    //BOOST_PHOENIX_ADAPT_FUNCTION(path, to_path, _to_path, 1);

    auto path_iterator(::boost::filesystem::path p)
    {
        using ::boost::filesystem::directory_iterator;
        using ::boost::filesystem::directory_entry;
        using ::boost::adaptors::transformed;
        using ::boost::phoenix::placeholders::_1;
        auto const mem = static_cast<const ::boost::filesystem::path& (directory_entry::*)() const>(&directory_entry::path);
        return directory_iterator(p) | transformed((_1->*mem)());
    }
}

#endif
