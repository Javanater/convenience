#include "using_convenience.hpp"

int main()
{
    cout << "wow, such convenience!!" << endl;

    for (auto e : directory_iterator(".") | indexed())
        cout << "%1$02d"_f % e.index() << e.value().path() << endl;

    //for (auto p : path_iterator("."))
    //    cout << p << endl;

    for (auto i : irange(3))
        cout << "%1$02d"_f % i << endl;

    vector<int> ints;
    ints += 3,5,9;

    for_each(ints, cout << _1 << endl);
}
