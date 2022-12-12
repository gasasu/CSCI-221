#include <memory>
#include <iostream>

template <typename T>
class BinarySearchTree {
public:
  // create a new binary search tree node with the given value
  BinarySearchTree(const T& value)
      : value(value),
        left(nullptr),
        right(nullptr),
        parent(nullptr) {}

  // insert a new value into the tree
  void insert(const T& value) {
    // if the value is less than or equal to this node's value, it goes in the left subtree
    if (value <= this->value) {
      // if there is no left child, create a new node with the value and link it as the left child
      if (!left) {
        left = std::make_unique<BinarySearchTree<T>>(value);
        left->parent = this;
      }
      // otherwise, insert the value into the left subtree
      else {
        left->insert(value);
      }
    }
    // if the value is greater than this node's value, it goes in the right subtree
    else {
      // if there is no right child, create a new node with the value and link it as the right child
      if (!right) {
        right = std::make_unique<BinarySearchTree<T>>(value);
        right->parent = this;
      }
      // otherwise, insert the value into the right subtree
      else {
        right->insert(value);
      }
    }
  }

  // search the tree for a given value
  // returns true if the value is found, false otherwise
  bool search(const T& value) const {
    // if the value is less than or equal to this node's value, search the left subtree
    if (value <= this->value) {
      // if there is no left child, the value is not in the tree
      if (!left) {
        return false;
      }
      // otherwise, search the left subtree
      else {
        return left->search(value);
      }
    }
    // if the value is greater than this node's value, search the right subtree
    else {
      // if there is no right child, the value is not in the tree
      if (!right) {
        return false;
      }
      // otherwise, search the right subtree
      else {
        return right->search(value);
      }
    }
  }

  // print the tree in in-order traversal order
  void print() const {
    // print the left subtree
    if (left) {
      left->print();

    }}

#include <memory>

template <typename T>
class BinarySearchTreeNode {
public:
  // create a new node with the given value
  BinarySearchTreeNode(const T& value)
      : value(std::make_unique<T>(value)),
        left(nullptr),
        right(nullptr),
        parent(nullptr) {}

  // the node's data value
  std::unique_ptr<T> value;
  // the left child of the node
  std::unique_ptr<BinarySearchTreeNode<T>> left;
  // the right child of the node
  std::unique_ptr<BinarySearchTreeNode<T>> right;
  // the parent of the node
  BinarySearchTreeNode<T>* parent;
};

#include <memory>

template <typename T>
class BinarySearchTree {
public:
  // create a new binary search tree with no elements
  BinarySearchTree() : root(nullptr), count(0) {}

  // insert a new value into the tree
  void insert(const T& value) {
    // if the tree is empty, create a new root node with the value
    if (!root) {
      root = std::make_unique<BinarySearchTreeNode<T>>(value);
      count++;
    }
    // otherwise, insert the value into the subtree rooted at the root node
    else {
      root->insert(value);
    }
  }

  // search the tree for a given value
  // returns true if the value is found, false otherwise
  bool search(const T& value) const {
    // if the tree is empty, the value is not in the tree
    if (!root) {
      return false;
    }
    // otherwise, search the subtree rooted at the root node
    else {
      return root->search(value);
    }
  }

  // print the tree in in-order traversal order
  void print() const {
    // if the tree is empty, there is nothing to print
    if (!root) {
      return;
    }
    // otherwise, print the subtree rooted at the root node
    else {
      root->print();
    }
  }

private:
  // the root node of the tree
  std::unique_ptr<BinarySearchTreeNode<T>> root;
  // the number of elements in the tree
  int count;
};


#include <algorithm>
#include <array>

template <typename T, std::size_t N>
std::unique_ptr<BinarySearchTree<T>> createBinarySearchTree(
    const std::array<T, N>& values) {
  auto tree = std::make_unique<BinarySearchTree<T>>();
  for (const auto& value : values) {
    tree->insert(value);
  }
  return tree;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
  // the root node's destructor will recursively delete all child nodes
  // so we just need to reset the unique_ptr to the root node
  root.reset();
}


template <typename T>
int BinarySearchTree<T>::remove(const T& value) {
  // if the tree is empty, there is nothing to remove
  if (!root) {
    return 0;
  }

  // search the tree for the value
  auto node = root.get();
  while (node) {
    // if the current node has the value, remove it
    if (node->value == value) {
      // if the current node has no right child, we can replace it with its left child
      if (!node->right) {
        root = std::move(node->left);
        count--;
        return 1;
      }
      // if the current node has no left child, we can replace it with its right child
      else if (!node->left) {
        root = std::move(node->right);
        count--;
        return 1;
      }
      // if the current node has both a left and a right child, we need to find the largest element in the left subtree
      else {
        auto largest = node->left.get();
        while (largest->right) {
          largest = largest->right.get();
        }
        // replace the current node's value with the largest value in the left subtree
        node->value = largest->value;
        // remove the node with the largest value in the left subtree
        return largest->remove(largest->value);
      }
    }
    // if the current node's value is smaller than the search value, move to the right subtree
    else if (node->value < value) {
      node = node->right.get();
    }
    // if the current node's value is larger than the search value, move to the left subtree
    else {
      node = node->left.get();
    }
  }

  // if the value was not found in the tree, return 0
  return 0
}


