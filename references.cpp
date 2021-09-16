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
  std::cout << "Got \"Payload\" by value\n";
  std::cout << p.c << "\n";
  std::cout << p.i << "\n";
  std::cout << p.r << "\n";
  std::cout << p.y << "\n";
  std::cout << p.b << "\n";
  std::cout << p.s << "\n";
}

int main() {
  Payload payloadd{'o', 17, 'c', 91, true, "OzdincCelikel"};
  Payload &&refref = std::move(payloadd);
  bar(refref);
  return 0;
}
