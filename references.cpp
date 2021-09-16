#include <iostream>
#include <memory>
#include <string>

struct Payload {
  char c;
  int i;
  char r;
  int y;
  bool b;
  std::string s;
} Str;

void bar(Payload p) {
  std::cout << "bar()::Got \"Payload\" by value\n";
  std::cout << p.c << "\n";
  std::cout << p.i << "\n";
  std::cout << p.r << "\n";
  std::cout << p.y << "\n";
  std::cout << p.b << "\n";
  std::cout << p.s << "\n";
}

void baz(Payload &p) {
  std::cout << "baz()::Got \"Payload\" by reference\n";
  std::cout << p.c << "\n";
  std::cout << p.i << "\n";
  std::cout << p.r << "\n";
  std::cout << p.y << "\n";
  std::cout << p.b << "\n";
  std::cout << p.s << "\n";
}

void foo(Payload &&p) { // rvalue arguments will select this function
  std::cout << "Accepts rvalue reference as an argument.\n";
}

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
  return 0;
}
