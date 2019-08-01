#include "using_convenience.hpp"

int main()
{
    cout << "wow, such convenience!!" << endl;

    for (auto e : path_iterator(".") | indexed())
        cout << "%02d"_f % e.index() << e.value() << endl;

    vector<int> v;
    v += 3,5,9;

    for_each(v | enumerate, [](const auto& t)
    {
        cout << "hello" << endl;
    });

    size_t i;
    int e;
    RANGES_FOR(tie(i, e), v | enumerate)
        cout << i << ',' << e << endl;

    for_each(v, cout << _1 << endl);

    for_each(ints(1,3), cout << _1 << endl);
    
    cout << steady_clock::now() << endl;
}
