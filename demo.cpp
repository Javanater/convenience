#include "using_convenience.hpp"

int main()
{
    cout << "wow, such convenience!!" << endl;

    for (auto e : directory_iterator(".") | indexed())
        cout << format("%1$02d") % e.index() << e.value().path() << endl;

    //for (auto p : path_iterator("."))
    //    cout << p << endl;

    for (auto i : irange(3))
        cout << format("%1$02d") % i << endl;

    vector<int> ints;
    ints += 3,5,9;

    for_each(ints, cout << _1 << endl);
}
