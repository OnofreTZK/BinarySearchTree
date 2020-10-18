#ifndef _ABB_H_
#define _ABB_H_

#include <iostream>
#include <chrono>
#include <sstream>
#include <math.h>

// Árvore binária de busca

// Autores: Tiago Onofre & Amanda Albuquerque.

using namespace std;


class ABB {


        private:
        



		public:

            // Atributos --------------------------------------------------------------------------------------
			struct node_{
				int chave; // Valor -> para este projeto foi escolhido o tipo inteiro.
				node_ *esquerdo = nullptr; // ponteiro para o filho esquerdo.
				node_ *direito = nullptr; // ponteiro para o filho direito.
				node_ *pai; 

                // Construtor padrão do nó.
				node_(int chave = 0, node_* p = nullptr, node_* esq = nullptr, node_* dir = nullptr): 
                    chave(chave), pai(p), esquerdo(esq), direito(dir) { }

			};

            // Nó raiz            
            node_ *raiz_;


            // Construtor padrão da árvore.
            ABB(): raiz_( new node_ ) {}


            // Métodos ---------------------------------------------------------------------------------------

        

            // Vai buscar o valor passado e, caso esteja na árvore, retornará o nó que o contém.
            node_ * buscar( node_* no_aux, int _valor_, int f );

            // Realiza a busca para achar o valor que deve ser removido.
            // Retorna true caso realize com sucesso.
            bool remover( int _valor_ );

            // Realiza a busca para achar o local correto de inserćão de acordo com as especificaćões da ABB.
            // Retorna true caso consiga inserir.
            bool inserir( int _valor_);



};

#endif
