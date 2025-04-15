#include "Allocator.hpp"

#include "Queue.hpp"
#include "Stack.hpp"
#include "Trees.hpp"
#include "Vector.hpp"

int main(void) {
  AVLTree<int> aAVLTree;

  aAVLTree.insert(10);
  aAVLTree.insert(11);
  aAVLTree.insert(12);
  aAVLTree.insert(15);

  return 0;
}
