#include <iostream>
#include "include/bstree.hpp"
using namespace std;
using namespace BSTree;

auto Menu(Tree *&) -> void;

int main(int argc, char *argv[]) {
  Tree *tree = new Tree;
  int *array = new int[argc - 1];
  for (int i = 1; i < argc; i++) {
    array[i - 1] = atoi(argv[i]);
  };
  for (int i = 0; i < argc - 1; i++) {
    for (int j = i + 1; j < argc - 1; j++) {
      if (array[i] == array[j]) {
        for (int k = j; j < argc - 1; j++) array[j] = array[j + 1];
        argc--;
      };
    }
  };
  for (int i = 0; i < argc - 1; i++) {
    tree->insert(array[i]);
  }
  delete[] array;
  Menu(tree);
  delete tree;
}

auto Menu(Tree *&tree) -> void {
  string exit;
  int choise;
  while ((exit != "y") && (exit != "yes") && (exit != "Y") && (exit != "Yes") &&
         (exit != "YES")) {
    cout << "Select one of the operations:" << endl;
    cout << "1.Print the tree on the screen" << endl;
    cout << "2.List the nodes of the tree" << endl;
    cout << "3.Add a node to the tree" << endl;
    cout << "4.Remove the node from the tree" << endl;
    cout << "5.Save tree to a file" << endl;
    cout << "6.Load the tree from a file" << endl;
    cout << "7.Check node availability" << endl;
    cout << "8.Complete the program" << endl;
    cin >> choise;
    switch (choise) {
      case 8:
        cout << "Do you want to leave program? ( yes, no )" << endl;
        cin >> exit;
        if ((exit == "y") || (exit == "yes") || (exit == "Y") ||
            (exit == "Yes") || (exit == "YES"))
          cout << "Good by!";
        break;
    }
  }
