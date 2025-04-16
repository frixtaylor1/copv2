#ifndef LINEARPOLICY_HPP
#define LINEARPOLICY_HPP

#include "IAllocatorPolicy.hpp"
#include <cassert>
#include <cstddef>

template <size_t CAPACITY> class LinearPolicy : implements IMemPolicy {
public:
  LinearPolicy() : arena(nullptr), nextPos(0) {}
  LinearPolicy(byte *arena) : arena(arena), nextPos(0) {}
  ~LinearPolicy() {}

  void setMem(byte *memRef) {
    this->arena = memRef;
    nextPos = 0;
  }

  [[nodiscard]] void *alloc(size_t size) {
    assert(nextPos + size < arenaSize);

    void *ptr = &arena[nextPos];
    nextPos += size;
    return ptr;
  }

  void free(void *ptr) { nextPos = 0; }

private:
  byte *arena;
  size_t arenaSize = CAPACITY;
  size_t nextPos;
};

#endif // LINEARPOLICY_HPP
