#define BOOST_BIND_NO_PLACEHOLDERS

#include "convenience.hpp"

using std::vector;
using std::map;
using std::multimap;
using std::set;
using std::multiset;
using std::deque;
using std::list;
using std::cout;
using std::endl;
using std::cerr;
using std::cin;
using std::istream;
using std::array;
using std::min;
using std::max;
using std::abs;
using std::shuffle;
using std::random_device;
using std::mt19937;
using std::string;
using std::ostream;
using std::exception;
using std::runtime_error;
//using std::experimental::string_view;
using std::ios;

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
using boost::lexical_cast;
using boost::optional;
using boost::replace_all;
using boost::get;

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

using boost::algorithm::join;

using boost::filesystem::path;
using boost::filesystem::filesystem_error;
using boost::filesystem::file_status;
using boost::filesystem::directory_entry;
using boost::filesystem::directory_iterator;
using boost::filesystem::recursive_directory_iterator;
using boost::filesystem::ifstream;
using boost::filesystem::ofstream;
using boost::filesystem::exists;
using boost::filesystem::absolute;
using boost::filesystem::canonical;
//using boost::filesystem::copy;
using boost::filesystem::copy_directory;
using boost::filesystem::copy_file;
using boost::filesystem::copy_symlink;
using boost::filesystem::create_directories;
using boost::filesystem::create_directory;
using boost::filesystem::create_hard_link;
using boost::filesystem::create_symlink;
using boost::filesystem::current_path;
using boost::filesystem::exists;
using boost::filesystem::equivalent;
using boost::filesystem::file_size;
using boost::filesystem::hard_link_count;
using boost::filesystem::initial_path;
using boost::filesystem::is_directory;
using boost::filesystem::is_empty;
using boost::filesystem::is_other;
using boost::filesystem::is_regular_file;
using boost::filesystem::is_symlink;
using boost::filesystem::last_write_time;
using boost::filesystem::permissions;
using boost::filesystem::read_symlink;
using boost::filesystem::relative;
using boost::filesystem::remove;
using boost::filesystem::remove_all;
using boost::filesystem::rename;
using boost::filesystem::resize_file;
using boost::filesystem::space;
using boost::filesystem::status;
using boost::filesystem::status_known;
using boost::filesystem::symlink_status;
using boost::filesystem::system_complete;
using boost::filesystem::temp_directory_path;
using boost::filesystem::unique_path;
using boost::filesystem::weakly_canonical;

using boost::phoenix::placeholders::_1;
using boost::phoenix::placeholders::_2;
using boost::phoenix::placeholders::_3;
using boost::phoenix::placeholders::_4;
using boost::phoenix::placeholders::_5;
using boost::phoenix::placeholders::_6;
using boost::phoenix::placeholders::_7;
using boost::phoenix::placeholders::_8;
using boost::phoenix::placeholders::_9;
using boost::phoenix::at_c;

using boost::gregorian::date;
using boost::gregorian::weeks;
using boost::gregorian::days;
using boost::gregorian::months;
using boost::gregorian::years;
using boost::gregorian::day_clock;
using boost::gregorian::date_period;
using boost::gregorian::day_iterator;

using boost::random::uniform_int_distribution;
using boost::random::uniform_01;

//using ranges::view::enumerate;

using boost::program_options::options_description;
using boost::program_options::positional_options_description;
using boost::program_options::variables_map;

using boost::hof::unpack;

using boost::process::system;
using boost::process::search_path;

using boost::this_thread::sleep_for;
using boost::this_thread::sleep_until;
using boost::scoped_thread;
using boost::interrupt_and_join_if_joinable;

using namespace boost::assign;
using namespace convenience;
using namespace boost::chrono;

using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

namespace phx = boost::phoenix;
namespace fs = boost::filesystem;
namespace mpl = boost::mpl;
namespace beast = boost::beast; // from <boost/beast.hpp>
namespace http = beast::http;   // from <boost/beast/http.hpp>
namespace net = boost::asio;    // from <boost/asio.hpp>
namespace ssl = net::ssl;       // from <boost/asio/ssl.hpp>
namespace po = boost::program_options;
namespace fusion = boost::fusion;
namespace bp = boost::process;
