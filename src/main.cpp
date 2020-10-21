#include "../include/bst.hpp"

int main( void ) 
{
    ABB tree;

    tree.buscar( tree.raiz_, 23, 0 );

    tree.inserir(34);
    
    tree.buscar( tree.raiz_, 34, 0 );

    tree.remover( tree.raiz_, 34 );

    tree.buscar( tree.raiz_, 34, 0 );

    return 0;
}
