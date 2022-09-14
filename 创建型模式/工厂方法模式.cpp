/**
 * @file 简单工厂模式.cpp
 * @author your name (you@domain.com)
 * @brief
 * 该模式有抽象工厂、具体工厂、抽象产品、具体产品四个角色，具体工厂生产产品，抽象工厂作为约束具体工厂行为的公开接口，抽象产品作为约束具体产品规范的公开接口
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
  void consume() { std::cout << "消费产品B\n"; }
};

class Factory {
 public:
  Factory() = default;
  ~Factory() = default;
  /**
   * @brief
   *     -  优点: 每次新增产品时只要定义相应的工厂派生类 (具体工厂) 即可
   *     -  缺点: 每个工厂只能生产一个产品
   * @return Product*
   */
  virtual Product *createProduct() = 0;
};

class ProductAFactory : public Factory {
 public:
  ProductAFactory() = default;
  ~ProductAFactory() = default;
  Product *createProduct() { return new ProductA(); }
};

class ProductBFactory : public Factory {
 public:
  ProductBFactory() = default;
  ~ProductBFactory() = default;
  Product *createProduct() { return new ProductB(); }
};

int main() {
  Factory *factory = new ProductAFactory();  // 创建生产产品A的工厂
  Product *product = factory->createProduct();
  product->consume();  // 消费产品A
  return 0;
}