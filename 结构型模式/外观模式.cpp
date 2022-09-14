/**
 * @file 外观模式.cpp
 * @author your name (you@domain.com)
 * @brief
 * 通过一个外观类来隔离外部与子系统的通信，其实就是提供的一个功能涉及多个类，但对外只暴露一个接口
 * @version 0.1
 * @date 2022-09-14
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <memory>
class FunctionA {
 public:
  FunctionA() = default;
  ~FunctionA() = default;
  void func() { std::cout << "FunctionA::func do something\n"; }
};

class FunctionB {
 public:
  FunctionB() = default;
  ~FunctionB() = default;
  void func() { std::cout << "FunctionB::func do something\n"; }
};

class FunctionC {
 public:
  FunctionC() = default;
  ~FunctionC() = default;
  void func() { std::cout << "FunctionC::func do something\n"; }
};

typedef std::unique_ptr<FunctionA> SmartFunctionA;
typedef std::unique_ptr<FunctionB> SmartFunctionB;
typedef std::unique_ptr<FunctionC> SmartFunctionC;
class Facade {
 public:
  Facade() {
    fa_ = std::make_unique<FunctionA>();
    fb_ = std::make_unique<FunctionB>();
    fc_ = std::make_unique<FunctionC>();
  }
  ~Facade() = default;
  void func() {
    fa_->func();
    fb_->func();
    fc_->func();
  }

 private:
  SmartFunctionA fa_;
  SmartFunctionB fb_;
  SmartFunctionC fc_;
};

int main() {
  Facade facade;
  facade.func();
  return 0;
}
