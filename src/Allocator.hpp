#ifndef ALLOCATORS_HPP
#define ALLOCATORS_HPP

#include "FreeListPolicy.hpp"
#include "IAllocatorPolicy.hpp"
#include "LinearPolicy.hpp"
#include "PoolPolicy.hpp"

template <size_t ALLOCATOR_CAP = 1024,
          MemAllocPolicies policy = MemAllocPolicies::KLinearPolicy>
class Allocator {
public:
  Allocator() { initialize(); }
  ~Allocator() { cleanup(); }

public:
  [[nodiscard]] void *alloc(size_t size) {
    return policies[policy]->alloc(size);
  }
  void free(void *ptr = nullptr) { policies[policy]->free(ptr); }

private:
  void cleanup() {
    _dynamicCleanup();
    _staticCleanup();
  }

  void _dynamicInitialize() {
#ifndef CXX_STATIC_MEM
    arena = new char[CAPACITY];
    return;
#endif
  }

  void _staticInitialize() {
#ifdef CXX_STATIC_MEM
    return;
#endif
  }

  void initialize() {
    policies[policy]->setMem(arena);
    _dynamicInitialize();
    _staticInitialize();
    ::memset(arena, {0}, CAPACITY);
  }

  void _dynamicCleanup() {
#ifndef CXX_STATIC_MEM
    delete[] arena;
#endif
  }

  void _staticCleanup() {
#ifdef CXX_STATIC_MEM
    ::memset(arena, {0}, CAPACITY);
#endif
  }

private:
  enum { CAPACITY = ALLOCATOR_CAP };

#ifdef CXX_STATIC_MEM
  byte arena[CAPACITY] = {0};
#else
  byte *arena;
#endif

private:
  LinearPolicy<CAPACITY> linearPolicy;
  FreeListPolicy<CAPACITY> freeListPolicy;
  PoolPolicy<CAPACITY> poolPolicy;

  size_t ALLOCATOR_KEY_POLICY = 0;

  IMemPolicy *policies[3] = {&linearPolicy, &freeListPolicy, &poolPolicy};
};

#endif // ALLOCATORS_HPP
