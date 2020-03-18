/*Neste programa voc� vai trabalhar com a representa��o de um grafo em matriz
   de adjac�ncias.
1. Observe a declara��o do grafo: vari�veis n, m, matriz E, vetor de graus D.
2. Observe a leitura do grafo.
3. Acerte o c�lculo dos graus.*/
#include<iostream>
#include<string.h>
using namespace std;
const int NVM=1001;

// Declara��es para o grafo
bool E[NVM][NVM];
int n, m, D[NVM];
//Outras declara��es
int i, j, u, w;

void Inicializa(){
    memset(D, 0, sizeof(D));
    memset(E, 0, sizeof(E));
}

int main(){
    while(true){
   	    cout<<endl<<"n, m = ";  cin >> n >> m;
	    Inicializa();
	    cout<<"Arestas:"<<endl;
	    for(i = 1; i<=m; i++){
			cin >> u >> w;
			E[u][w] = 1;
			E[w][u] = 1;
			D[u]++;
			D[w]++;
	    }
	    cout<<endl<<"Graus dos vertices:"<<endl;
	    for(i = 1; i<=n; i++) cout<< i <<" "<< D[i]<<endl;
	}
	return 0;
}


