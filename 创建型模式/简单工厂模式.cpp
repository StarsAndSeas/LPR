/**
 * @file 简单工厂模式.cpp
 * @author your name (you@domain.com)
 * @brief
 * 该模式有具体工厂、抽象产品、具体产品三个角色，工厂角色根据约定的命令生成产品，抽象产品作为约束具体产品规范的公开接口
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
   *     -  缺点:
   * 每次添加新产品时都要修改工厂的生产产品代码，不符合只扩展禁修改的开闭原则
   * @param type
   * @return Product*
   */
  Product *createProduct(std::string type) {
    if (type.compare("ProductA") == 0) {
      return new ProductA();
    } else if (type.compare("ProductB") == 0) {
      return new ProductB();
    }
  }
};

int main() {
  Factory *factory = new Factory();    //  创建生产产品的工厂
  factory->createProduct("ProductA");  //  生产产品A
  factory->createProduct("ProductB");  //  生产产品B
  return 0;
}