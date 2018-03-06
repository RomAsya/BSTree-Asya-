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
  ~Tree();
};
}
