#ifndef INCLUDE_DEBUG_HPP
#define INCLUDE_DEBUG_HPP

class debug
{
public:
    template<typename T> void vdeb(T vec);
    template<typename T1, typename T2> void adeb(T1 *arr, T2 n);
    template<typename T> void mdeb(T mp);
};

#endif //INCLUDE_DEBUG_HPP

template<typename T> void debug::vdeb(T vec)
{
    cout << "#vector set debug" << endl;
    for(auto vv : vec) cout << vv << " ";
    cout << endl;
}

template<typename T1, typename T2> void debug::adeb(T1 *arr, T2 n)
{
    cout << "#adebug" << endl;
    for(int i=0; i<=n; i++) cout << arr[i] << " ";
    cout << endl;
}

template<typename T> void debug::mdeb(T mp)
{
    cout << "#map pair debug" << endl;
    for(auto const& m : mp) cout << m.first sp m.second << endl;
}