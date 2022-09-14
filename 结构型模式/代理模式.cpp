/**
 * @file 代理模式.cpp
 * @author your name (you@domain.com)
 * @brief
 * 通过代理类来代理外部类向目标类的请求，在这个过程代理类可以添加一些访问权限控制或者添加额外服务
 * @version 0.1
 * @date 2022-09-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <exception>
#include <iostream>
#include <memory>

class Subject {
 public:
  Subject() = default;
  ~Subject() = default;
  virtual void request() = 0;
};
class RealSubject : public Subject {
 public:
  RealSubject() = default;
  ~RealSubject() = default;
  void request() { std::cout << "Call RealSubject::request()\n"; }
};
typedef std::unique_ptr<Subject> SmartSubject;
class Proxy : public Subject {
 public:
  Proxy(const std::string &type) {
    if (type.compare("RealSubject") == 0) {
      s_subject_ = std::make_unique<RealSubject>();
    } else {
      throw std::exception();
    }
  }
  ~Proxy();
  void preRequest() { std::cout << "Call Proxy::preRequest()\n"; }
  void request() {
    preRequest();
    s_subject_->request();
    afterRequest();
  }
  void afterRequest() { std::cout << "Call Proxy::afterRequest()\n"; }

 private:
  SmartSubject s_subject_;
};

int main() {
  Proxy proxy("RealSubject");
  proxy.request();
  return 0;
}
