#include "../include/bst.hpp"

int main( void ) 
{
    ABB tree;

    ABB::node_ * nodetest = tree.buscar( tree.raiz_, 23, 0 );

    tree.inserir(34);
    
    ABB::node_ * nodetest2 = tree.buscar( tree.raiz_, 34, 0 );

    return 0;
}
