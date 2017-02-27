//============================================================================
// Name        : cpp_virtual_destructor.cpp
// Author      : Urmila Shinde
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//
//  main.cpp
//  inherit
//
//  Created by Urmila shinde on 11/16/16.
//  Copyright © 2016 Urmila shinde. All rights reserved.
//

#include <iostream>

using namespace std;

class A {
public:
    A() { cout << "A constructor" <<endl; }

   // virtual ~A() { cout << "A desstructor" <<endl; }

    ~A() { cout << "A desstructor" <<endl; } // this wont be overridden by baseptr to derived obj destructor
};

class B: public A {
public:
    B() { cout << "B constructor" <<endl; }

    ~B() { cout << "B desstructor" <<endl; }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    {
        std::cout << "============\nInside scope!\n";
        B b;
        std::cout << "Time to destroy it!\n";
    }

    {
        std::cout << "============\nInside scope!\n";
        A a;
        std::cout << "Time to destroy it!\n";
    }

    A *baseptr;
    {
        std::cout << "============\nInside scope!\n";
        baseptr = new B;

        std::cout << "Time to destroy it!\n";
        delete baseptr;
    }

    std::cout << "============\nOutside scope!\n";


    return 0;
}

