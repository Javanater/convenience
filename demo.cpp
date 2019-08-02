#include "using_convenience.hpp"

int main()
{
    cout << "wow, such convenience!!" << endl;

    for (auto e : path_iterator(".") | indexed())
        cout << "%02d"_f % e.index() << e.value() << endl;

    vector<int> v;
    v += 3,5,9;

    for_each(v, cout << _1 << endl);

    cout << steady_clock::now() << endl;
}
