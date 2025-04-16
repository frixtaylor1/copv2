#ifndef POOLPOLICY_HPP
#define POOLPOLICY_HPP
#include "IAllocatorPolicy.hpp"

/**
 * The Pool allocator takes the entire buffer of memory and splits it into
 * equal size parts. Each chunk contains a tag with a flag if the block is
 * free or not. The Allocate function, looks for a free block, then marks it
 * used and returns a pointer to it. The free function takes the incoming
 * chunk and marks it free
 */
template <size_t CAPACITY> class PoolPolicy : implements IMemPolicy {
public:
  PoolPolicy(byte *arena) : arena(arena) {}

  void *alloc(size_t size) { return nullptr; }
  void free(void *ptr) {}
  void setMem(byte *memRef) { arena = memRef; }

private:
  byte *arena;
};

#endif // POOLPOLICY
