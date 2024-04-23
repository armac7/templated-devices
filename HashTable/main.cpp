#include <iostream>
#include <functional>

int main() 
{
    std::hash<int> intHash;
    int value = 40;
    std::size_t hashedInt = intHash(value);

    std::cout << hashedInt % 10 << std::endl;
    int placeholder;
    std::cin >> placeholder;
}