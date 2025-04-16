#ifndef TREES_HPP
#define TREES_HPP

#include "LinearPolicy.hpp"
#include <new>

/**
 * For custom DataTypes must implement operator "<"
 */
template <class T, size_t TREE_CAPACITY = 1024> class AVLTree {
  struct TreeNode {
    TreeNode(T value) : data(value), height(1), left(nullptr), right(nullptr) {}
    T data;
    int height;
    TreeNode *left;
    TreeNode *right;
  };

public:
  AVLTree() : root(nullptr) { allocator.setMem(mem); }

  ~AVLTree() { ::memset(&mem, 0, TREE_CAPACITY); }

public:
  void insert(T data) { root = insertNode(root, data); }

  // @TODO:
  //   search,
  //   update,
  //   remove

private:
  TreeNode *insertNode(TreeNode *node, T data) {
    if (node == nullptr) {
      void *mem = allocator.alloc(sizeof(TreeNode));
      if (mem == nullptr) {
        throw std::bad_alloc();
      }
      return new (mem) TreeNode(data);
    }

    if (data < node->data) {
      node->left = insertNode(node->left, data);
    } else {
      node->right = insertNode(node->right, data);
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balanced = balance(node);

    if (balanced > 1 && balance(node->left) >= 0) {
      return rightRotate(node);
    }

    if (balanced > 1 && balance(node->left) < 0) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }

    if (balanced < -1 && balance(node->right) <= 0) {
      return leftRotate(node);
    }

    if (balanced < -1 && balance(node->right) > 0) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
    return node;
  }

  int max(int lhs, int rhs) { return lhs > rhs ? lhs : rhs; }

  int height(TreeNode *node) {
    if (!node)
      return 0;
    return node->height;
  }

  int balance(TreeNode *node) {
    if (!node) {
      return 0;
    }
    return height(node->left) - height(node->right);
  }

  TreeNode *rightRotate(TreeNode *y) {
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
  }

  TreeNode *leftRotate(TreeNode *x) {
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
  }

private:
  byte mem[TREE_CAPACITY] = {0};
  TreeNode *root;
  LinearPolicy<TREE_CAPACITY> allocator;
};

#endif // TREES_HPP
