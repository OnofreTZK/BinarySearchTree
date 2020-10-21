#include "../include/bst.hpp"

ABB::node_ * ABB::buscar( node_* no_aux, int _valor_, int f)
{

    // 1 = nó encontrado; 2 = chave não encontrada e nó aponta para arvore esquerda vazia
    // 3 = chave não encontrada e nó aponta para arvore direita vazia

    if (no_aux != nullptr){ //checando se a árvore é vazia
        if (no_aux->chave == _valor_){ // checando se o nó atual contém a chave procurada
            f = 1;
        } else {
            if (_valor_ < no_aux->chave){
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
                buscar(no_aux, _valor_, f);
            }
        }
    }
    
    
    if ( f == 1 )
    { 
        std::cout << "O valor " << _valor_ << " está na árvore!\n";
        return no_aux; 
    } // chave encontrada.
    else 
    {
        std::cout << "O valor " << _valor_ << " não está na árvore!\n";
        return nullptr; 
    } // abb vazia ou nó não existia na árvore
    

}



ABB::node_ * ABB::remover( ABB::node_ * atual, int _valor_ )
{
    // Nó auxiliar para guardar um dos filhos do nó atual.
    node_ * runner;

    // vazia
	if( atual == nullptr)
    {
	    return atual;
	}

    // Percorrendo a árvore até chega no nó a ser removido
	if( _valor_ < atual->chave )
    {
		atual->esquerdo = remover( atual->esquerdo, _valor_ );

	}
    else if( _valor_ > atual->chave )
    {

		atual->direito = remover( atual->direito, _valor_ );

	}
    else
    {
        // Caso tenha só um filho a direita ou a esquerda.
	    if( atual->esquerdo == nullptr)
        {
		    runner = atual->direito;
			delete atual;
			return runner;
		}
        else if( atual->direito == nullptr)
        {
			runner = atual->esquerdo;
			delete atual;
			return runner;
        }

        // Caso tenha 2 filhos.
		runner = atual->pai->esquerdo;
		atual->chave = runner->chave;
		atual->direito = remover( atual->direito, runner->chave );
			
    }
		
    return atual;

}



bool ABB::inserir( int _valor_ )
{
    // Ponteiro que será usado parar saber o nó pai do novo nó.
    ABB::node_ * parente = nullptr;

    // Ponteiro que irá percorrer a árvore -> inicia no nó raiz.
    ABB::node_ * runner = this->raiz_; 

    while( runner != nullptr )
    {
        // Guarda o nó que eventualmente será o pai do novo nó.
        parente = runner;

        
        if( parente->chave == _valor_ )
        {
            return false;
        }
        else if( parente->chave < _valor_ )
        {
            runner = parente->direito;
        }
        else if( parente->chave > _valor_ )
        {
            runner = parente->esquerdo;
        }

    }

    // Caso a árvore esteja vazia o laco não será rodado
    // portanto devemos verificar essa circunstancia.

    if( parente->chave == 0 )
    {
        parente->chave = _valor_;
    }
    else if( parente->chave < _valor_ )
    {
        parente->direito = new node_(_valor_);
        parente->direito->pai = parente;
    }
    else
    {
        parente->esquerdo = new node_(_valor_);
        parente->esquerdo->pai = parente;
    }

    return true;

}
