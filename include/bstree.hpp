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
  auto print_elements(Node*& curr, int space) -> void;
  auto print() -> void;
  auto deleting(Node*&curr) -> void;
  ~Tree();
};
}
