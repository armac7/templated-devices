#include <iostream>
#include "LinkedList.h"
#include "../Node.h"
#define NEWLINE std::cout << std::endl

int main() {
    LinkedList<int> test;
    test.insert(2);
    test.insert(5);
    test.insert(1);
    test.insert(-5);

    std::cout << "LinkedList:\n";
    test.print();
    NEWLINE;

    // **********remove() TESTS**********
    // test.remove();
    // test.print();
    // NEWLINE;
    // test.remove();
    // test.print();
    // NEWLINE;
    // test.remove();
    // test.print();
    // NEWLINE;
    // test.remove();
    // test.print();
    // NEWLINE;
    // test.remove();
    // test.print();
    // NEWLINE;

    // **********removeFront() TESTS**********
    // test.removeFront();
    // test.print();
    // NEWLINE;
    // test.removeFront();
    // test.print();
    // NEWLINE;
    // test.removeFront();
    // test.print();
    // NEWLINE;
    // test.removeFront();
    // test.print();
    // NEWLINE;
    // test.removeFront();
    // test.print();
    // NEWLINE;

    int place;
    std::cin >> place;
    return 0;
}