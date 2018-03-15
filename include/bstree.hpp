namespace BSTree {
struct Node {
  int data;
  Node* left;
  Node* right;
};
class Tree {
  Node* root;
  auto print_elements(Node* curr, int space) const -> void;
  auto deleting(Node*&curr) -> void;
 public:
  Tree();
  auto insert(int value) -> bool; 
  auto print() const -> void;
  ~Tree();
};
}
