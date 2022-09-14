/**
 * @file 桥接模式.cpp
 * @author your name (you@domain.com)
 * @brief 将类间继承关系转换为关联关系 (组合或聚合)
 * ，这样用一个类可以组合出具有不同特点、不同行为的对象，而不用具现化每一个特例
 * @version 0.1
 * @date 2022-09-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <memory>

class Animal {
 public:
  Animal() = default;
  ~Animal() = default;
  virtual void sound() = 0;
};

class Bird : public Animal {
 public:
  Bird() = default;
  ~Bird() = default;
  void sound() { std::cout << "唧唧\n"; }
};

class Sheep : public Animal {
 public:
  Sheep() = default;
  ~Sheep() = default;
  void sound() { std::cout << "咩咩\n"; }
};

class Color {
 public:
  enum { Yellow, Blue };
  Color(int color = Blue) : color_(color) {}
  ~Color() = default;
  void showColor() { std::cout << color_; }

 private:
  int color_;
};
typedef std::unique_ptr<Animal> SmartAnimal;
typedef std::unique_ptr<Color> SmartColor;

class Bridge {
 public:
  Bridge() = default;
  ~Bridge() = default;
  void setTarget(SmartAnimal animal, SmartColor color) {
    animal_ = std::move(animal);
    color_ = std::move(color);
  }
  void sound() {
    color_->showColor();
    animal_->sound();
  }

 private:
  SmartAnimal animal_;
  SmartColor color_;
};

int main() {
  Bridge bridge;
  bridge.setTarget(std::make_unique<Bird>(),
                   std::make_unique<Color>(Color::Yellow));
  bridge.sound();
  return 0;
}