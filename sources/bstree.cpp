#include "bstree.hpp"
#include <iostream>
using namespace BSTree;

Tree::Tree() : root(nullptr) {}

Node::Node(int val) {
  data = val;
  right = nullptr;
  left = nullptr;
}

auto Tree::get_tree_existence() const -> bool {
  if (root == nullptr) return false;
}

auto Tree::insert(int value) -> bool {
  if (root == nullptr) {
    root = new Node{value};
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
    parent->right = new Node{value};
  else
    parent->left = new Node{value};
  return true;
}

auto Tree::print_elements(Node* curr, int space) const -> void {
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

auto Tree::print() const -> void {
  print_elements(root, 0); }

auto Tree::deleting(Node*& curr) -> void {
  if (curr == nullptr) return;
  if (curr->right != nullptr) deleting(curr->right);
  if (curr->left != nullptr) deleting(curr->left);
  delete curr;
  curr = nullptr;
}

auto Tree::straight_detour(Node* curr) const -> void {
  std::cout << curr->data << " ";
  if (curr->left != nullptr) straight_detour(curr->left);
  if (curr->right != nullptr) straight_detour(curr->right);
}

auto Tree::straight() const -> void {
  straight_detour(root); }

auto Tree::back_detour(Node* curr) const -> void {
  if (curr->left != nullptr) back_detour(curr->left);
  if (curr->right != nullptr) back_detour(curr->right);
  std::cout << curr->data << " ";
}

auto Tree::back() const -> void {
  back_detour(root); }

auto Tree::transverse_detour(Node* curr) const -> void {
  if (curr->left != nullptr) transverse_detour(curr->left);
  std::cout << curr->data << " ";
  if (curr->right != nullptr) transverse_detour(curr->right);
}

auto Tree::transverse() const -> void { 
  transverse_detour(root); }

Tree::~Tree() {
  deleting(root); }
