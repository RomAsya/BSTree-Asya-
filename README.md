## BSTree
## Processing the input data
```bash
$ g++ tree.cpp sources.cpp -o bstree -std=c++11
$ ./bstree 1 2 3 # с указаниями входных параметров
Select one of the operations:
1.Print the tree on the screen
2.List the nodes of the tree
3.Add a node to the tree
4.Remove the node from the tree
5.Save tree to a file
6.Load the tree from a file
7.Check node availability
8.Complete the program


$ g++ tree.cpp sources.cpp -o bstree -std=c++11
$ ./bstree # без указания входных данных
Select one of the operations:
1.Print the tree on the screen
2.List the nodes of the tree
3.Add a node to the tree
4.Remove the node from the tree
5.Save tree to a file
6.Load the tree from a file
7.Check node availability
8.Complete the programи 
```
## Printing elements
```bash
# Вывод на экран не пустого древа
$ g++ tree.cpp sources.cpp -o bstree -std=c++11
$ ./bstree 6 8 7 9 4 1
Select one of the operations:
1.Print the tree on the screen
2.List the nodes of the tree
3.Add a node to the tree
4.Remove the node from the tree
5.Save tree to a file
6.Load the tree from a file
7.Check node availability
8.Complete the program
1
      --9
   --8
      --7
6
   --4
      --1
      
# Вывод на экран пустого древа
$ g++ tree.cpp sources.cpp -o bstree -std=c++11
$ ./bstree 
Select one of the operations:
1.Print the tree on the screen
2.List the nodes of the tree
3.Add a node to the tree
4.Remove the node from the tree
5.Save tree to a file
6.Load the tree from a file
7.Check node availability
8.Complete the program
1
Tree is empty
```
