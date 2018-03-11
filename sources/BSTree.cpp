#include "BSTree.hpp"
#include <iostream>
using namespace BSTree;
Tree::Tree() { root = nullptr; }
auto Tree::insert(int value) -> bool {
  if (root == nullptr) {
    root = new Node{value, nullptr, nullptr};
    return true;
  }
  Node *parent = root;
  Node *curr = root;
  while (curr != nullptr) {
    if (curr->data < value)
      curr = curr->right;
    else
      curr = curr->left;
    if (curr != nullptr) parent = curr;
  }
  if (parent->data < value)
    parent->right = new Node{value, nullptr, nullptr};
  else
    parent->left = new Node{value, nullptr, nullptr};
  return true;
}
auto Tree::deleting(Node*& curr) -> bool {
  if (curr->right != nullptr) deleting(curr->right);
  if (curr->left != nullptr) deleting(curr->left);
  if (curr->data != root->data)
    delete curr;
  else
    curr = nullptr;
}
Tree::~Tree() { deleting(root); }
