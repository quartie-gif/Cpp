#pragma once 

#include <iostream>

struct MyInt {
  MyInt(int i) : i_(i) {}
  ~MyInt() {
    std::cout << "Good bye from " << i_ << std::endl;
  }
  int i_;
};
