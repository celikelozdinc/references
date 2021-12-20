#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Payload {
  char c;
  int i;
  char r;
  int y;
  bool b;
  std::string s;
} Str;

/**
 * @brief Pass-By-Value
 * 
 * @param p 
 */
void bar(Payload p) {
  std::cout << "bar()::Got \"Payload\" by value\n";
  std::cout << p.c << "\n";
  std::cout << p.i << "\n";
  std::cout << p.r << "\n";
  std::cout << p.y << "\n";
  std::cout << p.b << "\n";
  std::cout << p.s << "\n";
}

/**
 * @brief Pass-By-Reference
 * 
 * @param p 
 */
void baz(Payload &p) {
  std::cout << "baz()::Got \"Payload\" by reference\n";
  std::cout << p.c << "\n";
  std::cout << p.i << "\n";
  std::cout << p.r << "\n";
  std::cout << p.y << "\n";
  std::cout << p.b << "\n";
  std::cout << p.s << "\n";
}

void foo(const Payload& p) {
  std::cout << "Accepts const lvalue reference as an argument.\n";
}


void foo(Payload &&p) { // rvalue arguments will select this function
  std::cout << "Accepts rvalue reference as an argument.\n";
}

class Package {
public:
  Package() {
    vec.reserve(3);
    vec.emplace_back(10);
    vec.emplace_back(8);
    vec.emplace_back(6);
  }

  const int &get_first() { return vec.at(0); }

  const int &get_second() { return vec.at(1); }

  const int &get_third() { return vec.at(2); }

  int *get_int_ptr() { return &vec.at(0); }

  void print() noexcept {
    std::cout << "*******START PRINTING PACKAGE ****\n";
    for (int i = 0; i < 3; i++) {
      std::cout << i << "=>" << vec.at(i) << "\n";
    }
    std::cout << "*******END PRINTING PACKAGE****\n";
  }

private:
  std::vector<int> vec;
};

int main() {
  Payload payloadd{'o', 17, 'c', 91, true, "OzdincCelikel"};
  // Payload &payloadRef = Payload{'s', 88, 's', 88, true, "SSSsssSSS"};
  // initial value of reference to non-const must be an lvalue
  Payload payloadS{'s', 88, 's', 88, true, "SSSsssSSS"};
  Payload &&refref = std::move(payloadd);
  // A named rvalue is an lvalue as all named objects are lvalues
  bar(refref);
  baz(refref);
  // foo(refref);
  // an rvalue reference cannot be bound to an lvalue
  std::cout << "================================================\n";
  bar(payloadS);
  baz(payloadS);
  // foo(payloadS);
  // an rvalue reference cannot be bound to an lvalue
  Payload &payloadRef = payloadS;
  bar(payloadRef);
  baz(payloadRef);
  // foo(payloadRef);
  // an rvalue reference cannot be bound to an lvalue
  std::cout << "================================================\n";
  bar(Payload{'s', 41, 'a', 93, true, "SimgeAlkin"});
  // baz(Payload{'s', 41, 'a', 93, true, "SimgeAlkin"});
  // initial value of reference to non-const must be an lvalue
  // foo(refref); //an rvalue reference cannot be bound to an lvalue
  foo(Payload{'s', 41, 'a', 93, true, "SimgeAlkin"});
  std::cout << "================================================\n";
  bar(std::move(payloadd));
  // baz(std::move(payloadd));
  // initial value of reference to non-const must be an lvalue
  foo(std::move(payloadd));
  std::cout << "================================================\n";
  // baz(Payload{});
  // initial value of reference to non-const must be an lvalue
  foo(Payload{});  //=> Payload&& p = Payload{};
  // we can reference and rvalue with &&
  std::cout << "================================================\n";

  int x = 20, y = 40; // x and y are our referent
  int &firstRef = x;
  std::cout << "Address of x : " << &x << ", Value of x : " << x << "\n";
  std::cout << "Address of y : " << &y << ", Value of y : " << y << "\n";
  std::cout << "Address of firstRef : " << &firstRef
            << ", Value of firstRef : " << firstRef << "\n";

  firstRef = y;

  std::cout << "Address of x : " << &x << ", Value of x : " << x << "\n";
  std::cout << "Address of y : " << &y << ", Value of y : " << y << "\n";
  std::cout << "Address of firstRef : " << &firstRef
            << ", Value of firstRef : " << firstRef << "\n";

  firstRef = 80;

  std::cout << "Address of x : " << &x << ", Value of x : " << x << "\n";
  std::cout << "Address of y : " << &y << ", Value of y : " << y << "\n";
  std::cout << "Address of firstRef : " << &firstRef
            << ", Value of firstRef : " << firstRef << "\n";

  std::cout << "================================================\n";
  auto pkg = Package();
  // pkg.get_first() = 88; //assignment of read-only location
  auto i = pkg.get_first();
  std::cout << i << "\n";
  pkg.print();
  i = -10;
  std::cout << i << "\n";
  pkg.print();
  const int &second = pkg.get_second();
  std::cout << second << "\n";
  // second = pkg.get_third(); //assignment of read-only reference ‘second
  std::cout << "================================================\n";
  return 0;
}
