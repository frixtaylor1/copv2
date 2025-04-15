#ifndef STACK_HPP
#define STACK_HPP

/**
 * @LIFO: Last in -> First out
 */
#include "Vector.hpp"
template <class ItemType, size_t CAP = 16> class Stack {
public:
  Vector<ItemType, CAP> items;

  void push(const ItemType &item) { items.add(item); }

  ItemType pop() {
    ItemType itemToRemove = items.at(items.len());
    items.remove(items.at(items.len()));
    return itemToRemove;
  }

  [[nodiscard]] ItemType top() { return items.at(items.len()); }
  [[nodiscard]] ItemType back() { return items.at(); }
};

#endif // STACK_HPP
