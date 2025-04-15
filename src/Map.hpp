#ifndef MAP_HPP
#define MAP_HPP

#include "Vector.hpp"

/**
 * This map only allows unique keys
 */
template <class K, class V, size_t CAP = 16> class Map {
private:
  struct KVItem {
    KVItem() = default;
    KVItem(K key_) : key(key_) {}
    KVItem(K key_, V value_) : key(key_), value(value_) {}
    KVItem(const KVItem &rhs) : key(rhs.key), value(rhs.value) {}

    void operator=(const K key_) { key = key_; }
    void operator=(const V value_) { value = value_; }

    K key;
    V value;
  };

  Vector<KVItem, CAP> items = {};

public:
  /**
   * In order to make a first class citizen
   * @TODO:
   *   - Operators
   *   - Constructors and Destructors
   */

  Map() = default;
  Map(const Map &rhs) { *this = rhs; }
  Map(Map &&rhs) { *this = rhs; }
  void operator=(const Map &rhs) { items = rhs.items; }
  void operator=(const Map &&rhs) { items = rhs.items; }

  KVItem &operator[](K key) {
    KVItem *item = at(key);
    if (!item) {
      add({key});
      item = at(key);
    }
    return *item;
  }

  [[nodiscard]] KVItem *at(K key) {
    KVItem *tmp = nullptr;
    for (KVItem &item : items.items) {
      if (key == item.key) {
        return &item;
      }
    }
    return nullptr;
  }

public:
  void add(const KVItem &item) {
    for (size_t idx = 0; idx < items.nbItems; idx++) {
      if (items.at(idx).key == item.key) {
        items.at(idx) = item;
        return;
      }
    }
    items.add(item);
  }
  [[nodiscard]] size_t len() { return items.len(); }

  void remove(K key) {
    for (size_t idx = 0; idx < items.nbItems; idx++) {
      if (items.at(idx).key == key) {
        items.remove(idx);
        break;
      }
    }
  }
};

#endif // MAP_HPP
