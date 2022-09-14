/**
 * @file 享元模式.cpp
 * @author your name (you@domain.com)
 * @brief 由享元工厂存储享元对象
 * (可复用的细粒度对象)，减少频繁创建销毁对象的开销
 * @version 0.1
 * @date 2022-09-14
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <memory>
#include <unordered_map>
class FlyWeight {
 public:
  FlyWeight() = default;
  ~FlyWeight() = default;
  virtual void func() = 0;
};

class FlyWeightA : public FlyWeight {
 public:
  FlyWeightA(const std::string &internal_state = "")
      : internal_state_(internal_state) {}
  ~FlyWeightA() = default;
  void func() { std::cout << "FlyWeightA::func do something\n"; }

 private:
  std::string internal_state_;
};

typedef std::shared_ptr<FlyWeight> SmartFlyWeight;
typedef std::unordered_map<std::string, SmartFlyWeight>::iterator
    FlyWeightPoolIterator;

class FlyWeightFactory {
 public:
  FlyWeightFactory() {}
  ~FlyWeightFactory() = default;
  SmartFlyWeight getFlyWeight(const std::string &internal_state) {
    FlyWeightPoolIterator it = flyweight_pool.find(internal_state);
    if (it == flyweight_pool.end()) {
      std::cout << internal_state << " is not existed\n";
      flyweight_pool.insert(
          {internal_state, std::make_shared<FlyWeightA>(internal_state)});
    } else {
      std::cout << internal_state << " is existed\n";
    }
    return flyweight_pool[internal_state];
  }

 private:
  std::unordered_map<std::string, SmartFlyWeight> flyweight_pool;
};

int main() {
  FlyWeightFactory flyweight_factory;
  flyweight_factory.getFlyWeight("car");       // "car is not existed"
  flyweight_factory.getFlyWeight("umbrella");  // "umbrella is not existed"
  flyweight_factory.getFlyWeight("car");       // "car is existed"
  return 0;
}