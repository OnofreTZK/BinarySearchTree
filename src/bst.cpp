#include "../include/bst.hpp"

ABB::node_ ABB::buscar( int _valor_ )
{

    std::cout << "testando chamada\nRetornando nó raiz\n";
    
    return *raiz_;

}



bool ABB::remover( int _valor_ )
{

    std::cout << "testando chamada\nRetornando true\n";

    return true;

}



bool ABB::inserir( int _valor_ )
{
    // Ponteiro que será usado parar saber o nó pai do novo nó.
    ABB::node_ * parente;

    // Ponteiro que irá percorrer a árvore -> inicia no nó raiz.
    ABB::node_ * runner = this.raiz_; 

    while( runner != nullptr )
    {
        parente = runner;

        return true;
    }

    return true;

}
