#include <iostream>
#include <string>
#include <deque>

#include <type_traits>
#include <typeinfo>

template <class T>
std::string type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::string r = typeid(TR).name();
    if (std::is_const<TR>::value)
        r = "const " + r;
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}

template<typename T>
void f(T& val) {
    std::cout << type_name<T>() << std::endl;
    std::cout << type_name<decltype(val)>() << std::endl;
}




int main()
{
    int i = 1;
    f(i);
    return 0;
}