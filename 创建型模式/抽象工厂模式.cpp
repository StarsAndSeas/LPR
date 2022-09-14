/**
 * @file 简单工厂模式.cpp
 * @author your name (you@domain.com)
 * @brief
 * 该模式有抽象工厂、具体工厂、抽象产品、具体产品四个角色，具体工厂生产同属一个产品族的产品，抽象工厂作为约束具体工厂可生产产品种类的公开接口，抽象产品作为约束具体产品规范的公开接口
 * @version 0.1
 * @date 2022-09-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
class Product {
 public:
  Product() = default;
  ~Product() = default;
  virtual void consume() = 0;
};

class ProductA : public Product {
 public:
  ProductA() = default;
  ~ProductA() = default;
  void consume() { std::cout << "消费产品A\n"; }
};

class ProductB : public Product {
 public:
  ProductB() = default;
  ~ProductB() = default;
  virtual void consume() { std::cout << "消费产品B\n"; }
};

class IntelProductA : public ProductA {
 public:
  IntelProductA() = default;
  ~IntelProductA() = default;
  void consume() {
    ProductA::consume();
    std::cout << "Intel生产的产品A\n";
  }
};

class IntelProductB : public ProductB {
 public:
  IntelProductB() = default;
  ~IntelProductB() = default;
  void consume() {
    ProductB::consume();
    std::cout << "Intel生产的产品B\n";
  }
};

class NavidaProductA : public ProductA {
 public:
  NavidaProductA() = default;
  ~NavidaProductA() = default;
  void consume() {
    ProductA::consume();
    std::cout << "Navida生产的产品A\n";
  }
};

class NavidaProductB : public ProductB {
 public:
  NavidaProductB() = default;
  ~NavidaProductB() = default;
  void consume() {
    ProductB::consume();
    std::cout << "Navida生产的产品B\n";
  }
};

class Factory {
 public:
  Factory() = default;
  ~Factory() = default;
  virtual Product *createProductA() = 0;
  virtual Product *createProductB() = 0;
};

class IntelFactory : public Factory {
 public:
  IntelFactory() = default;
  ~IntelFactory() = default;
  Product *createProductA() { return new IntelProductA(); }
  Product *createProductB() { return new IntelProductB(); }
};

class NavidaFactory : public Factory {
 public:
  NavidaFactory() = default;
  Product *createProductA() { return new NavidaProductA(); }
  Product *createProductB() { return new NavidaProductB(); }
};

int main() {
  Factory *factory = new IntelFactory();  // 创建Intel产品工厂
  Product *product = factory->createProductA();
  product->consume();  // 生产Intel的产品A
  return 0;
}