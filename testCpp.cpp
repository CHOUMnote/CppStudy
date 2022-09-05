#include <iostream>
#include <typeinfo>
#include <initializer_list>
#include <tuple>
#include <string>

enum class Color
    {
        RED,   // RED is placed in the same scope as Color
        BLUE
    };

int main() { 
    std::cout << typeid(Color::BLUE).name();
}