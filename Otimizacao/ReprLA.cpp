/*Neste programa voc� vai trabalhar com a representa��o de um grafo em listas
   de adjac�ncias.
1. Observe a declara��o do grafo: vari�veis n, m, lista A, vetor de graus D.
2. Observe a cria��o aleat�ria do grafo.
3. Acrescente instru��es para imprimir as listas de adjac�ncias.
4. Descubra at� para qual maior valor de n+m voc� consegue rodar o programa*/
#include<iostream>
#include<stdlib.h>
using namespace std;
const int NVM=200000001;

// Declara��es para o grafo
typedef struct no* lista;
struct no{ int v; lista prox;};
int n, m;   lista A[NVM];
//Outras declara��es
int i, j, u, w;  lista p;

void Inicializa(int n){
    for (int i=1; i<=n; i++) A[i] = NULL;
}

int main(){
    while(true){
   	  cout<<endl<<"n, m = ";  cin >> n >> m;
	    Inicializa(n);
	    //cout<<"Arestas:"<<endl;
	    for(i = 1; i<=m; i++){
				u = 0;  w=0;
				while (u == w){
					u = (rand()%n*rand()%n)%n+1;   w = (rand()%n*rand()%n)%n+1; 
					u = (u+n)%n+1; w = (w+n)%n+1;
					//cout<<u<<" "<<w<<" ";  cin.get();
				}
				p = new(no);   p->v = w;   p->prox = A[u];   A[u] = p;
				p = new(no);   p->v = u;   p->prox = A[w];   A[w] = p;
			}
	    cout<<"Listas de Adjac�ncias"<<endl;  cin.get();
	    // for(i = 1; i<=n; i++){
			// 	cout<<i<<": "<<endl;  
			// 	while(A[i] != NULL){
			// 		cout << " -> " << A[i]->v  << " ";
			// 		A[i] = A[i]->prox;
			// 	}
			// 	cout << endl;
	    // }
	}
	return 0;
}


