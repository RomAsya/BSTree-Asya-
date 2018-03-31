namespace BSTree {
struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int val);
};
class Tree {
  Node* root;
  auto print_elements(Node* curr, int space) const -> void;
  auto deleting(Node*&curr) -> void;
  auto straight_detour(Node *curr) const -> void;
  auto back_detour(Node *curr) const -> void;
  auto transverse_detour(Node *curr) const -> void;

 public:
  Tree();
  auto insert(int value) -> bool;
  auto print() const -> void;
  auto straight() const -> void;
  auto back() const -> void;
  auto transverse() const -> void;
  auto empty() const -> bool;
  auto add_node(int value) -> void;
  auto delete_node(int value) -> bool;
  ~Tree();
};
}
