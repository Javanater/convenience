#include "convenience.hpp"

using std::vector;
using std::map;
using std::set;
using std::deque;
using std::list;
using std::cout;
using std::endl;
using std::cerr;
using std::cin;

using boost::filesystem::path;
using boost::filesystem::exists;
using boost::filesystem::remove;
using boost::filesystem::directory_iterator;
using boost::filesystem::directory_entry;
using boost::filesystem::ifstream;
using boost::filesystem::ofstream;

using boost::adaptors::adjacent_filtered;
using boost::adaptors::copied;
using boost::adaptors::filtered;
using boost::adaptors::indexed;
using boost::adaptors::indirected;
using boost::adaptors::map_keys;
using boost::adaptors::map_values;
using boost::adaptors::replaced;
using boost::adaptors::replaced_if;
using boost::adaptors::reversed;
using boost::adaptors::sliced;
using boost::adaptors::strided;
//using boost::adaptors::type_erased;
using boost::adaptors::tokenized;
using boost::adaptors::transformed;
using boost::adaptors::uniqued;

using boost::copy;
using boost::copy_backward;
using boost::fill;
using boost::fill_n;
using boost::generate;
using boost::inplace_merge;
using boost::merge;
using boost::nth_element;
using boost::partial_sort;
using boost::partition;
using boost::random_shuffle;
using boost::remove;
using boost::remove_copy;
using boost::remove_copy_if;
using boost::remove_if;
using boost::replace;
using boost::replace_copy;
using boost::replace_copy_if;
using boost::replace_if;
using boost::reverse;
using boost::reverse_copy;
using boost::rotate;
using boost::rotate_copy;
using boost::sort;
using boost::stable_partition;
using boost::stable_sort;
//using boost::swap_ranges;
using boost::transform;
using boost::unique;
using boost::unique_copy;

using boost::range::adjacent_find;
using boost::range::binary_search;
using boost::range::count;
using boost::range::count_if;
using boost::range::equal;
using boost::range::equal_range;
using boost::range::for_each;
using boost::range::find;
using boost::range::find_end;
using boost::range::find_first_of;
using boost::range::find_if;
using boost::range::lexicographical_compare;
using boost::range::lower_bound;
using boost::range::max_element;
using boost::range::min_element;
using boost::range::mismatch;
using boost::range::search;
using boost::range::search_n;
using boost::range::upper_bound;

using boost::regex;
using boost::regex_match;

using boost::irange;
using boost::format;
using boost::str;
using boost::tuple;
using boost::tie;
using boost::mem_fn;
using boost::any;

using boost::trim;
using boost::trim_copy;
using boost::trim_left;
using boost::trim_left_copy;
using boost::trim_right;
using boost::trim_right_copy;
using boost::starts_with;
using boost::ends_with;
using boost::contains;
using boost::to_upper;
using boost::to_lower;
using boost::to_upper_copy;
using boost::to_lower_copy;

using namespace boost::assign;
using namespace convenience;
using namespace boost::phoenix::placeholders;
using namespace boost::chrono;

namespace phx = boost::phoenix;
