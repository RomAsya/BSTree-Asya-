#include "bstree.hpp"
#include <iostream>
using namespace BSTree;
Tree::Tree() {
  root = nullptr; }
auto Tree::insert(int value) -> bool {
  if (root == nullptr) {
    root = new Node{value, nullptr, nullptr};
    return true;
  }
  Node *parent = root;
  Node *curr = root;
  while (curr != nullptr) {
    if (curr->data == value) 
      return false;
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
auto Tree::print_elements(Node*& curr, int space) -> void {
  if (curr != nullptr) {
    if (curr->right != nullptr)
      print_elements(curr->right, space + 1);
    for (int i = 0; i < space; i++) {
      std::cout << "   ";
    }
    if ((curr->data) != (root->data)) 
      std::cout << "--";
    std::cout << curr->data << std::endl;
    if (curr->left != nullptr) 
      print_elements(curr->left, space + 1);
  } else
    std::cout << "Tree is empty" << std::endl;
}
auto Tree::print() -> void {
  print_elements(root, 0); }
auto Tree::deleting(Node*& curr) -> void {
  if (curr == nullptr) return;
  if (curr->right != nullptr) deleting(curr->right);
  if (curr->left != nullptr) deleting(curr->left);
  delete curr;
  curr = nullptr;
}
Tree::~Tree() {
  deleting(root); }
