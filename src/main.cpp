#include "../include/bst.hpp"

int main( void ) 
{
    ABB tree;

    ABB::node_ nodetest = tree.buscar( 0 );

    tree.inserir(1);

    tree.remover(1);

    return 0;
}
