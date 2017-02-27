//============================================================================
// Name        : cpp_copy_constructor.cpp
// Author      : Urmila Shinde
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Example5 {
    string* ptr;
  public:
    Example5 (const string& str) {
    	ptr = new string;
    	*ptr = str;
    }
    ~Example5 () {delete ptr;}
    // copy constructor:
    Example5 (const Example5& x) {
    	ptr = new string;
    	*ptr = x.content();
    }
    // access content:
    const string& content() const {return *ptr;}
};

int main () {
  Example5 foo ("Example");
  Example5 bar = foo;

  cout << "bar's content: " << bar.content() << '\n';
  return 0;
}
