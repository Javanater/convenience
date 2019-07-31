#include "using_convenience.hpp"

int main()
{
    cout << "wow, such convenience!!" << endl;

    for (auto e : path_iterator(".") | indexed())
        cout << "%02d"_f % e.index() << e.value() << endl;

    for (auto i : irange(3))
        cout << "%02d"_f % i << endl;

    vector<int> ints;
    ints += 3,5,9;

    for_each(ints, cout << _1 << endl);

    cout << steady_clock::now() << endl;
}
