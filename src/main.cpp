#include "Allocator.hpp"
#include <iostream>

#include "Queue.hpp"
#include "Stack.hpp"
#include "Trees.hpp"
#include "Vector.hpp"

class String {
public:
  String(const char *anStr) { *this = anStr; }

public:
  String remove(const char ch) {
    for (size_t idx = 0; idx < str.len(); idx++) {
      if (ch == str.at(idx)) {
        str.remove(idx);
        return *this;
      }
    }
    return *this;
  }

  size_t len() { return str.len(); }

  // void replace(char oldChar, char newChar) {
  //   assert(false && "MUST IMPLEMENT");
  // }

  // void replaceAll(char oldChar, char newChar) {
  //   assert(false && "MUST IMPLEMENT");
  // }

  // void replaceAll(const char *oldSubStr, const char *newSubStr) {
  //   assert(false && "MUST IMPLEMENT");
  // }

public:
  void operator+=(const char ch) { str.add(ch); }

  void operator+=(const char *anStr) {
    for (size_t idx = 0; idx < ::strlen(anStr); idx++) {
      str.add(anStr[idx]);
    }
  }

  void operator=(const char *anStr) {
    for (size_t idx = 0; idx < ::strlen(anStr); idx++) {
      str.add(anStr[idx]);
    }
  }

  bool operator==(const String &rhs) const {
    if (str.len() != rhs.str.len()) {
      return false;
    }

    for (size_t idx = 0; idx < str.len(); idx++) {
      if (str.at(idx) != rhs.str.at(idx)) {
        return false;
      }
    }

    return true;
  }

  bool operator!=(const String &rhs) { return !(*this == rhs); }

  friend std::ostream &operator<<(std::ostream &stream, String &rhs) {
    stream << rhs.str.items;
    return stream;
  }

private:
  enum { CAPACITY = 24 };
  Vector<char, CAPACITY> str;
};

struct Something {
  int id = 0;
  const char *something;
};

bool operator<(Something &lhs, Something &rhs) { return lhs.id < rhs.id; }

int main(void) {
  // AVLTree<Something> aAVLTree;

  // aAVLTree.insert({10, "Something0"});
  // aAVLTree.insert({11, "Something1"});
  // aAVLTree.insert({12, "Something2"});
  // aAVLTree.insert({13, "Something3"});
  // aAVLTree.insert({14, "Something4"});
  // aAVLTree.insert({15, "Something5"});
  String str{"hello"};
  // str.replace('s', '1');

  return 0;
}
