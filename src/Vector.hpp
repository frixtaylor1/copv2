#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <cstring>

// @TODO: Use Allocator class
template <class ItemType, size_t CAP = 16> class Vector {
public:
  enum { CAPACITY = CAP };
  ItemType items[CAPACITY];
  size_t nbItems;

  /**
   * In order to make a first class citizen
   * @TODO:
   *   - Operators
   *   - Constructors and Destructors
   */
  Vector() : nbItems(0) { initialize(); }
  Vector(const Vector &rhs) { *this = rhs; }
  Vector(Vector &&rhs) { *this = rhs; }
  ~Vector() { initialize(); }

  void operator=(const Vector &rhs) {
    ::memmove(&items, &rhs.items, rhs.nbItems * sizeof(ItemType));
    nbItems = rhs.nbItems;
  }

  void operator=(Vector &&rhs) {
    ::memmove(&items, &rhs.items, rhs.nbItems * sizeof(ItemType));
    nbItems = rhs.nbItems;
  }

  [[nodiscard]] ItemType &operator[](size_t idx) {
    assert(idx < CAPACITY && "Index out of bound.");
    return at(idx);
  }

  ItemType operator[](size_t idx) const { return (*this)[idx]; }

public:
  void initialize() { ::memset(items, {0}, sizeof(ItemType) * CAPACITY); }

  ItemType &at(size_t idx) {
    assert(idx < CAPACITY && "Index out of bound.");
    return items[idx];
  }

  ItemType at(size_t idx) const {
    return items[idx];
  }

  void add(ItemType item) {
    assert(nbItems < CAPACITY && "Capacity exceded.");
    items[nbItems] = item;
    nbItems++;
  }

  void remove(size_t idx) {
    assert(idx < Vector<ItemType>::CAPACITY && "Index out of bound.");
    ::memmove(&items[idx], &items[idx + 1],
              (nbItems - idx - 1) * sizeof(ItemType));
    nbItems--;
    items[nbItems] = ItemType();
  }

  [[nodiscard]] size_t len() const { return nbItems; }
};

#endif // VECTOR_HPP
