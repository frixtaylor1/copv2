#ifndef IALLOCATORPOLICY_HPP
#define IALLOCATORPOLICY_HPP

#include <cstddef>
#include <cstring>

#define interface struct
#define implements public

typedef char byte;
typedef int Index;


struct IMemPolicy {
  virtual ~IMemPolicy() {}
  virtual void *alloc(size_t) = 0;
  virtual void free() = 0;
};

enum MemAllocPolicies {
  KLinearPolicy = 0,
  KFreeListPolicy = 1,
  KPoolPolicy = 2,
};

#endif // IALLOCATORPOLICY_HPP
