#include <iostream>
#include <vector>

struct Box {
  Box() { std::cout << "Box()\n"; }   // default ctor
  ~Box() { std::cout << "~Box()\n"; } // destructor

  Box(const Box &) { std::cout << "Box(const Box &)\n"; } // copy ctor
  Box(Box &&) { std::cout << "Box(Box &&)\n"; }           // move ctor

  Box &operator=(const Box &) {
    std::cout << "operator=(const Box&)\n";
    return *this;
  } // copy assignment
  Box &operator=(Box &&) {
    std::cout << "operator=(Box&&)\n";
    return *this;
  } // move assignment

  int value{0};
};

// If we assume that object is rather complicated to construct, we would
// write a helper function like
Box fork() {
  std::cout << "START FORK\n";
  Box b;

  // complicated initialization

  std::cout << "WILL END FORK\n";
  return std::move(b); //=> invokes move ctor Box(Box&&)
  // return b;
}

Box update_with_ref(Box &&b, const int value) {
  b.value = value;
  return std::move(b);
}

int main() {
  Box b;
  b.value = 11;

  /*
  std::vector<Box> boxVec{};
  size_t sizeOfVec = 3;
  boxVec.reserve(sizeOfVec); // to prevent invoking copy ctor again and again
  for (int i = 0; i < sizeOfVec; i++) {
    std::cout << "Begin fork, push element " << i << " to vector\n";
    boxVec.emplace_back(b.fork());
    // boxVec.emplace_back(Box());
    std::cout << "End fork, pushed element " << i << " to vector\n";
  }
*/

  // Box box = b.update_with_ref(b, 9); //=> an rvalue reference cannot be bound
  // to an lvalue
  Box box = update_with_ref(Box(), 8);
  std::cout << box.value << "\n";
  std::cout << b.value << "\n";

  return 0;
}
