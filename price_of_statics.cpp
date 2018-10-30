#include <string>
#include <algorithm>

// -std=c++14 -Wall

struct C {
    static const std::string &magic_static(){
        static const std::string s = "bob";
        return s;
    }
    // reference copy
    const std::string &s = magic_static();
    // used for returning reference back
    const std::string &magic_static_ref(){
        return s;
    }
};

auto main() -> int
{
    /*
    C::magic_static().size();
    C::magic_static().size();
    C::magic_static().size();
    return C::magic_static().size();
    */
    C c;
    c.magic_static_ref().size();
    c.magic_static_ref().size();
    c.magic_static_ref().size();
    return c.magic_static_ref().size();
}
