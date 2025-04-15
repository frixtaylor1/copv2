#ifndef QUEUE_HPP
#define QUEUE_HPP

/**
 * @FIFO: First in -> First out.
 * [item]enque->[item][item][item]deque->[item]
 * Operation | AVGERAGE | WORST CASE
 * Search    | O(n)     | O(n)
 * Insert    | O(1)     | O(1)
 * Delete    | O(1)     | O(1)
 *       Space Complexity:
 * Space cost| O(n)     | O(n)
 *
 */
#include "Vector.hpp"
template <class ItemType, size_t CAP = 16> class Queue {
public:
  Vector<ItemType, CAP> items;
  ItemType deque() {
    ItemType removedItem = items.at(0);
    items.remove(0);
    return removedItem;
  }

  void enque(const ItemType &item) {
    size_t idxToEnque = items.CAPACITY - (items.CAPACITY - items.len());
    items.add(item);
  }

  [[nodiscard]] ItemType front() { return items.at(0); }
  [[nodiscard]] ItemType back() { return items.at(items.len()); }
};

#endif // QUEUE_HPP
