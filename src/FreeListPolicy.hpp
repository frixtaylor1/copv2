#ifndef FREELISTPOLICY_HPP
#define FREELISTPOLICY_HPP

/**
 * This manages a list of free blocks and allocated blocks.
 * The Allocate function searches for free block matching the size needed
 * or for a bigger chunk size to split. Upon selecting the right block the
 * function returns a pointer to an allocated block. The Free function takes
 * a chunk of memory and adds it back the free list, if possible it will
 * merge with one of the other free blocks.
 *
 * @Todo: Must develope BRTree for better performance
 */
#include "IAllocatorPolicy.hpp"
#include "Trees.hpp"
#include <cassert>

template <size_t CAP = 1024> class FreeListPolicy : implements IMemPolicy {
public:
  FreeListPolicy(byte *arena, size_t size) : arena(arena) {}

  void *alloc(size_t size) {
    assert("MUST IMPLEMENT!");
    return nullptr;
  }
  void free(void *ptr) {}

  void setMem(byte *memRef) { arena = memRef; }

private:
  enum { CAPACITY = CAP };
  byte *arena;
  AVLTree<void *, CAPACITY> freeList;
};

#endif // FREELISTPOLICY_HPP
