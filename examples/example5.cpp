//lkhfhflhkfhkfkjf;
#include "BSTree.hpp"
using namespace std;
using namespace BSTree;

auto Menu (Tree *&) -> void;

int main (int argc, char * argv [])
{
    Tree *tree = new Tree;
    int* array= new int [argc-1];
    for (int i=1 ; i< argc; i++)
    {
        array[i-1]= atoi(argv[i]);
    };
    for (int i=0; i<argc-1; i++) {
        for (int j=i+1; j<argc-1; j++) {
            if (array[i]==array[j]) {
                for (int k=j; j< argc-1; j++) array[j]= array[j+1];
                argc--;
            };
        }
    };
    for (int i=0; i<argc-1; i++) {
        tree->insert (array[i]);
    }
    delete []array;
    Menu (tree);
    delete tree;
}

auto Menu (Tree *& tree)->void {
    string exit;
    char c_choise;
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
        case 1:
            tree->print ();
            break;
        case 2:
            if (!tree->empty ( )) {
                cout << "a.Straight detour" << endl;
                cout << "b.Transverse detour" << endl;
                cout << "c.Back detour" << endl;
                cin>> c_choise;
                switch (c_choise) {
                case 'a':
                    tree->straight();
                    cout<<endl;
                    break;
                case 'b':
                    tree->transverse();
                    cout<<endl;
                    break;
                case 'c':
                    tree->back();
                    cout<<endl;
                    break;
                }
                break;
            }
            else cout << "Tree is empty"<< endl;
            break;
        case 3:
            cout << "Enter a value for new node:" << endl;
            int value;
            cin.clear();
            cin.get();
            cin>> value;
            if (cin)
                tree->add_node (value);
            else cerr<< "Invalid format" << endl;
            break;
        case 4:
            if (!tree->empty ( )) {
                cout << "Enter a value for deleting node:" << endl;
                int value1;
                cin.clear();
                cin.get();
                cin>> value1;
                if (cin) {
                    if (tree->delete_node (value1))
                        std::cout<< "Node was succesfully deleted"<<std::endl;
                    else std::cout<< "Node wasn't founded"<<std::endl;
                }
                else
                    cerr<< "Invalid format"<<endl;
            }
            else cout << "Tree is empty"<< endl;
            break;
        case 5:
            if (!tree->empty()) {
                string file_name;
                cout << "Enter a name of the file:" << endl;
                cin >> file_name;
                if (tree->save_tree_to_the_file (file_name)) cout << "Tree was succesfully saved" << endl;
            }
            else cout << "Error!!! Tree is empty" << endl;
            break;
        case 8:
            cout << "Do you want to leave program? ( yes, no )" << endl;
            cin >> exit;
            if ((exit == "y") || (exit == "yes") || (exit == "Y") ||
                    (exit == "Yes") || (exit == "YES"))
                cout << "Good by!"<<endl;
            break;
        }
    }
}
