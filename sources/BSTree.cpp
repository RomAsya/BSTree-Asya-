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
Tree::~Tree() {
  while ((root->right != nullptr) && (root->left != nullptr)) {
    Node *curr = root;
    Node *parent = root;
    while (1) {
      if ((curr->right != nullptr) && (curr->left != nullptr)) {
        parent = curr;
        curr = curr->right;
        continue;
      }
      if (curr->left != nullptr) {
        parent = curr;
        curr = curr->left;
        continue;
      }
      if (curr->right != nullptr) {
        parent = curr;
        curr = curr->right;
        continue;
      }
      break;
    }
    if (curr->data > parent->data)
      delete parent->right;
    else
      delete parent->left;
  }
  delete root;
}
