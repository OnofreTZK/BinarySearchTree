#include "../include/bst.hpp"

ABB::node_ ABB::buscar( node_* no_aux, int _valor_, int f)
{

    // 1 = nó encontrado; 2 = chave não encontrada e nó aponta para arvore esquerda vazia
    // 3 = chave não encontrada e nó aponta para arvore direita vazia

    if (no_aux != nullptr){ //checando se a árvore é vazia
        if (no_aux->chave == _valor_){ // checando se o nó atual contém a chave procurada
            f = 1;
        } else {
            if (chave < no_aux->chave){
                if (no_aux->esquerdo == nullptr){
                    f = 2;
                } else {
                    no_aux = no_aux->esquerdo;
                }
            } else {
                if (no_aux->direito == nullptr){
                    f = 3;
                } else {
                    no_aux = no_aux->direito;
                }
            } if (f < 1){
                buscar(no_aux, chave, f);
            }
        }
    }
    if ( f == 1){ return no_aux; } // chave encontrada.
    else { return nullptr; } // abb vazia ou nó não existia na árvore

    //std::cout << "testando chamada\nRetornando nó raiz\n";
    
    //return *raiz_;

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
