#include <iostream>
#include <queue>
#include <stack>
#include <sstream>
#include <fstream>
#include <math.h>

using namespace std;


class ABB_ {

		public:

			struct node_{
				int chave;
				node_ *esquerdo = nullptr; //ponteiro para o filho esquerdo
				node_ *direito = nullptr;
				node_ *pai; 
				size_t altura;

				node_(int chave = 0, node_* p = nullptr, node_* esq = nullptr, node_* dir = nullptr): chave(chave), pai(p), esquerdo(esq), direito(dir), altura(0){ }

			};

		private:



}