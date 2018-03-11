namespace BSTree {
struct Node {
  int data;
  Node* left;
  Node* right;
};
class Tree {
  Node* root;
 public:
  Tree();
  auto insert(int value) -> bool;
  auto deleting(Node*&curr) -> void;
  ~Tree();
};
}
