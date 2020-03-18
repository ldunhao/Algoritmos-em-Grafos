/*Neste programa voc� vai trabalhar com a representa��o de um grafo em listas
   de adjac�ncias com vetor.
1. Observe a declara��o do grafo: vari�veis n, m, vector A, vetor de graus D.
2. Observe a cria��o aleat�ria do grafo.
3. Acrescente instru��es para imprimir as listas de adjac�ncias.
4. Descubra at� para qual maior valor de n+m voc� consegue rodar o programa*/
#include <stdio.h>
#include <string.h> 
#include<stdlib.h>
#include<vector>
#include<iostream>
using namespace std;
const int NVM=10000000;

// Declara��es para o grafo
vector<int> A[NVM];
int n, m;
//Outras declara��es
int i, j, u, w;

void Inicializa(int n){
    for (int i=1; i<=n; i++) A[i].clear();
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
				A[u].push_back(w);  A[w].push_back(u);
	    }
	    cout<<"Vizinhan�a:"<<endl;  cin.get();
	    // for(i = 1; i<=n; i++){
			// 	cout<<i<<": "<<endl; 
			// 	for(j = 1; j <= A[i].size(); j++) {
			// 		cout << " -> " << A[i][j] << " ";
			// 	}
			// 	cout <<  endl;

	    // }
	}
	return 0;
}
