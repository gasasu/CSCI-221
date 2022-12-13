#include <memory>
#include <iostream>
#include <algorithm>
#include <array>

/*
) Design a class to store a node in the binary search tree. All of the pointers in a node
should be implemented using smart pointers. The pointer to the data should be a unique pointer.
The pointers to other nodes should be designed in a manner that allows proper memory management
using the concepts we discussed in class.
*/

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
  std::shared_ptr<BinarySearchTreeNode<T>> left;
  // the right child of the node
  std::shared_ptr<BinarySearchTreeNode<T>> right;
  // the parent of the node
  BinarySearchTreeNode<T>* parent;
};

/*(5 points) Design a class to represent a binary search tree. This class should contain a pointer to
the root node in the tree and the number of elements in the tree. Remember to update the count in
other functions as appropriate. Your class should have all of the standard functionality for classes.
(c) (5 points) Write a constructor that takes as input an array of values and creates a binary search
tree containing values. The method should return a pointer to the created binary search tree. You
should insert elements in to the tree in the order they appear in the array. You are allowed to add
additional arguments to your function as necessary.
(d) (4 points) Write a destructor for your binary search tree.
(e) (5 points) Write a method that takes as input a value of the appropriate type and adds the value
to the binary search tree. You should follow the BST property to ensure that you add the new node
to the right place in the tree. This should not change any other part of the tree.
(f) (8 points) Write a method that takes as input a value of the appropriate type and removes the
value from the tree. The method should modify the original tree, not create a copy. The tree must
be updated to maintain its structure. If possible the largest element in the subtree rooted at the left
child should be moved to the position occupied by the removed value. This may cause additional
issues that need to be fixed. The function should return the number of values removed (0 or 1).
Beware of memory leaks.
*/

template <typename T>
class BinarySearchTree {
public:
  // create a new binary search tree with no elements
  BinarySearchTree(){
  root(nullptr);
  count = 0;
  };
  // constructor that takes in an array of values of Type T and creates a binary search Tree
  // the return type cannot be of any type since constructors do not return types
  BinarySearchTree(T values[]){
      for (auto value:values){
        insert(value);
      }
    }
    ~BinarySearchTree(){
    if (!root){
        delete root;
        root = nullptr;
    }
    };
    // removes a particular value from the tree
    int remove(const T& value)
{
  // if the tree is empty, there is nothing to remove
  if (!root) {
    return 0;
  }

  // search the tree for the value
  std::shared_ptr<BinarySearchTreeNode<T>> node = root;
  while (node) {
    // if the current node has the value, remove it
    if (node->value == value) {
      // if the current node has no right child, we can replace it with its left child
      if (!node->right) {
        node->value = node->left->value;
        node->left = nullptr;
        count--;
        return 1;
      }
      // if the current node has no left child, we can replace it with its right child
      else if (!node->left) {
        node->value = node->right->value;
        node->right = nullptr;
        count--;
        return 1;
      }
      // if the current node has both a left and a right child, we need to find the largest element in the left subtree
      else {
        auto largest = node->left;
        if (largest) {
          while (largest->right) {
            largest = largest->right;
          }
          // replace the current node's value with the largest value in the left subtree
          node->value = largest->value;
          // remove the node with the largest value in the left subtree
          return remove(largest->value);
        }
      }
    }
    // if the current node's value is smaller than the search value, move to the right subtree
    else if (node->value < value) {
      node = node->right;
    }
    // if the current node's value is larger than the search value, move to the left subtree
    else {
      node = node->left;
    }
  }

  // if the value was not found in the tree, return 0
  return 0;
}

  // insert a new value into the tree
  void insert(const T& value) {
      BinarySearchTreeNode<T> newnode = BinarySearchTreeNode<T>(value);
      if (!root){
        root = newnode;
      }
      else{
        std::shared_ptr<BinarySearchTreeNode<T>> cur = root;

        while (true){
            if (*cur->value > value) {
      if (!cur->left) {
        cur->left = newnode;
        newnode->parent = this;
        break;
      }
      else {
        cur = cur->left;
      }
    }
    else {
      if (!cur->right) {
        cur->right = newnode;
        newnode->parent = this;
        break;
      }

      else {
        cur = cur->right;
      }
      }

    }
    count++;
  }
  }
private:
  // the root node of the tree
  std::shared_ptr<BinarySearchTreeNode<T>> root;
  // the number of elements in the tree
  int count;
};


int main(){
return 0;
}

