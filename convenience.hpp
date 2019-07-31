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

#define nullary_mem(_fn_) [](auto& a){return a._fn_();}

    auto path_iterator(::boost::filesystem::path p)
    {
        using ::boost::filesystem::directory_iterator;
        using ::boost::adaptors::transformed;
        return directory_iterator(p) | transformed(nullary_mem(path));
    }
}

#endif
