/**
 * @file 装饰器模式.cpp
 * @author your name (you@domain.com)
 * @brief
 * 将一个类A嵌入另一个类B，A和B派生自同一个类，有相同的接口，由B调用A的方法并添加一些行为如调用前记录日志
 * @version 0.1
 * @date 2022-09-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <memory>
class Component {
 public:
  Component() = default;
  ~Component() = default;
  virtual void showName() = 0;
};

class ConcretComponent : public Component {
 public:
  ConcretComponent() = default;
  ~ConcretComponent() = default;
  void showName() { std::cout << "ConcretComponent\n"; }
};

typedef std::unique_ptr<Component> SmartComponent;

class Decorater : public Component {
 public:
  Decorater(SmartComponent s_com) : s_com_(std::move(s_com)) {}
  ~Decorater() = default;
  void showName() {
    std::cout << "Call Component::showName\n";
    s_com_->showName();
  }

 private:
  SmartComponent s_com_;
};

int main() {
  Decorater wrapper(std::make_unique<ConcretComponent>());
  wrapper.showName();
  return 0;
}
