#include "../include/MemoryResource.h"
#include "../include/Stack.h"
#include <iostream>

struct ComplexType {
    int a;
    double b;
    std::string c;

    ComplexType(int a, double b, const std::string& c) : a(a), b(b), c(c) {}
};

int main() {
    MemoryResource memRes(1024);
    Stack<int> intStack(&memRes);

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    for (auto it = intStack.begin(); it != intStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    Stack<ComplexType> complexStack(&memRes);
    complexStack.push({1, 2.5, "Hello"});
    complexStack.push({2, 3.5, "World"});

    for (auto it = complexStack.begin(); it != complexStack.end(); ++it) {
        std::cout << it->a << " " << it->b << " " << it->c << std::endl;
    }

    return 0;
}
