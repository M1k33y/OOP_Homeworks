
#include <iostream>
#include "Tree.h"
int main()
{
    Tree<int> copac(20);
    copac.add_node(nullptr,1);
    copac.add_node(copac.root,4);
    copac.add_node(copac.root, 3);
    copac.add_node(copac.root, 2);
    copac.sort(copac.root,compara);

   // copac.printChildren(copac.root);
    copac.

}
