#include <bits/stdc++.h>

#define MAXN 1010

using namespace std;

int G[MAXN][MAXN],G_criado[MAXN][MAXN], M_AUX[MAXN][MAXN];
int tam_f=0,n;
vector<vector<int> > F;
int cor[MAXN], vis[MAXN], C[MAXN]; 

// =====================================================
// PRINT
// =====================================================

int Print(int M[1010][1010], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

// =====================================================
// CONECTIVIDADE
// =====================================================

void DFS(int v){
    vis[v] = 1;
    for(int i = 0; i < n; i++){
        if(G[v][i]){
            if(!vis[i]) DFS(i);
        }
    }
}

void checa_conexo(){
    int comp;
    comp = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            DFS(i);
            comp++;
        } 
    }
    cout << endl << endl << " --> O Grafo " << (comp == 1 ? "Eh conexo" : "Nao eh conexo") << endl << endl;
}


// =====================================================
// ARVORE GERADORA
// =====================================================

// int Teste(){
//     int retorna;

//     retorna = 0;

//     for(int i=0;i<n;i++){
//         if (C[i] != 0) retorna = 1;
//     }

//     return retorna;
// }

int Cria_Arvore(){
    memset(G_criado,0,sizeof(G_criado));

    for(int i=0;i<n;i++) C[i] = i;


    for(int i=0;i<n;i++){
        if(C[i] == 0){
            for(int j=0;j<n;j++){
                if(C[j] != 0 && G[i][j] == 1){
                    G_criado[i][j] = 1;
                    C[j] = 0;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>i){
                G_criado[j][i] = G_criado[i][j];
            }
        }
    }
}

// =====================================================
// COLORACAO PELO METODO GULOSO 
// =====================================================

// int greedy(){
//     int k;

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){

//         }
//     }
// }

// =====================================================
// BIPARTICAO
// =====================================================

void colore(int x){ 
	
	cor[x] = 0; 
	
	vector<int> fila; 
	fila.push_back(x); 
	
	int pos = 0; 
	
	while(pos < (int)fila.size()){ 
		
		int atual = fila[pos]; 
		pos++;
		
		
        for(int j = 0; j < n; j++){
            if(G[atual][j]){
                if(cor[j] == -1){ 
                    cor[j] = 1 - cor[atual]; 			
                    fila.push_back(j); 
                }
            }
		}
	}
}

bool checa_bipartido(){
	
	for(int i = 0;i < n;i++){
		if(cor[i] == -1){       
			colore(i);         
		}
	}
	
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(G[i][j]){
			    if(cor[i] == cor[j]) return false; 
            }
		}
	}
	
	return true; 
}


// =====================================================
// CRIACAO OS GRAFOS
// =====================================================

int n_cubo(int x){
    int tam_cubo = pow(2,x);
    memset(G_criado,0,sizeof(G_criado));

    if(x==0) G_criado[0][0] = 0;
    else if(x==1){
        G_criado[0][0]=0;
        G_criado[0][1]=1;
        G_criado[1][0]=1;
        G_criado[1][1]=0;
    }else{
        int p = tam_cubo/2;
        n_cubo(x-1);
        for(int i=0;i<=p;i++){
            for(int j=0;j<=p;j++){
                G_criado[i+p][j+p] = G_criado[i][j];
            }
        }
        for(int i=0;i<tam_cubo;i++) G_criado[tam_cubo-i-1][i] = 1;
    }
}

int Kn(int x){
    memset(G_criado,0,sizeof(G_criado));
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            ((i==j)? G_criado[i][j]=0: G_criado[i][j]=1);
        }
    }
}

int Pn(int x){
    memset(G_criado,0,sizeof(G_criado));
    for(int i=0;i<x;i++) {
        if(i!=x-1)G_criado[i][i+1] = 1;
        if(i!=0) G_criado[i][i-1] = 1;
    }
}

int Cn(int x){
    memset(G_criado,0,sizeof(G_criado));
    for(int i=0;i<x;i++) {
        if(i>0) G_criado[i][i-1] = 1;
        if(i!=x-1) G_criado[i][i+1] = 1;
        if(i==0) G_criado[i][x-1] = 1; 
        if(i==x-1) G_criado[i][0] = 1;
    }
}

int Wn(int x){
    memset(G_criado,0,sizeof(G_criado));
    for(int i=0;i<x;i++) {
        if(i>0) G_criado[i][i-1] = 1;
        if(i!=x-1) G_criado[i][i+1] = 1;
        if(i==0) G_criado[i][x-2] = 1; 
        if(i==x-1) G_criado[i][0] = 1;
        G_criado[x][i] = 1;
        G_criado[i][x] = 1;
        G_criado[x][x] = 0;
    }
}

int Kn1_n2(int x,int y){
    memset(G_criado,0,sizeof(G_criado));
    int tot=0;
    tot = x+y;
    for(int i=0;i<tot;i++){
        for(int j=0;j<tot;j++){
            if(i!=j){
                if(i<x && j>=x) G_criado[i][j] = 1;
                if(i>=x && j<x) G_criado[i][j] = 1;
            }
        }
    }
}

// =====================================================
// ESCOLHA DOS GRAFOS
// =====================================================

int escolha_grafo(){
    int opcubo,cubo,op;
    char tecla;
    bool ok;
    ok = false;


    cout << "Digite qual grafo voce quer gerar?" << endl;
    cout << "1 - N-Cubo(Qn)" << endl;
    cout << "2 - Completo(Kn) ou Caminho(Pn)" <<endl;
    cout << "3 - Ciclo(Cn) ou Roda(Wn)" <<endl;
    cout << "4 - Um Bipartido Completo(Kn1,n2)" << endl;
    cout << "Escolha: ";
    cin >> opcubo;

    switch (opcubo){
        int k;
        
        case 1:   
                cout << "Qual o valor do n? ";
                cin >> cubo;
                while(!ok){
                    if (cubo<0){
                        cout << "O valor tem que ser maior ou igual a 0!" << endl;
                        cout << "Qual o valor do n? ";
                        cin >> cubo;
                    } 
                    else ok = true;
                }
                system("clear");
                n_cubo(cubo);
                int tam;
                tam = pow(2,cubo);
                cout << endl << endl;
                Print(G_criado,tam);
                cout << endl << endl;
                cout << "Digite uma letra ou um numero para continuar..." << endl;
                cin >> tecla;
                system("clear");
                break;
            
        case 2: 
                cout << "1 - Um Completo (Kn)" << endl;
                cout << "2 - Um Caminhos (Pn)" << endl;
                cout << "Escolha: ";
                cin >> op;
                system("clear");
                switch(op){
                    case 1:
                            cout << endl;
                            cout << "Qual o tamanho? ";
                            cin >> k;
                            while(!ok){   
                                if (k<1){
                                    cout << "O tamanho tem que ser maior ou igual a 1!" << endl;
                                    cout << "Qual o tamanho? ";
                                    cin >> k;
                                } 
                                else ok = true;
                            }
                            system("clear");
                            Kn(k);
                            cout << endl << endl;
                            Print(G_criado,k);
                            cout << endl << endl;
                            cout << "Digite uma letra ou um numero para continuar..." << endl;
                            cin >> tecla;
                            system("clear");
                            break;
                    
                    case 2:
                            cout << endl;
                            cout << "Qual o tamanho? ";
                            cin >> k;
                            while(!ok){
                                if (k<1){
                                    cout << "O tamanho tem que ser maior ou igual a 1!" << endl;
                                    cout << "Qual o tamanho? ";
                                    cin >> k;
                                } 
                                else ok = true;
                            }
                            system("clear");
                            Pn(k);
                            cout << endl << endl;
                            Print(G_criado,k);
                            cout << endl << endl;
                            cout << "Digite uma letra ou um numero para continuar..." << endl;
                            cin >> tecla;
                            system("clear");
                            break;

                    default: break;
                    }
                break;
                
        case 3: 
                cout << "1 - Um Ciclo (Cn)" << endl;
                cout << "2 - Um Roda (Wn)" << endl;
                cout << "Escolha: ";
                cin >> op;
                system("clear");
                switch(op){
                    case 1:
                        cout << endl;
                        cout << "Qual o tamanho? ";
                        cin >> k;
                        while(!ok){   
                            if (k<3){
                                cout << "O tamanho tem que ser maior ou igual a 3!" << endl;
                                cout << "Qual o tamanho? ";
                                cin >> k;
                            } 
                            else ok = true;
                        }
                        system("clear");
                        Cn(k);
                        cout << endl << endl;
                        Print(G_criado,k);
                        cout << endl << endl;
                        cout << "Digite uma letra ou um numero para continuar..." << endl;
                        cin >> tecla;
                        system("clear");
                        break;
                    
                    case 2:
                        cout << endl;
                        cout << "Qual o tamanho? ";
                        cin >> k;
                        while(!ok){   
                            if (k<3){
                                cout << "O tamanho tem que ser maior ou igual a 3!" << endl;
                                cout << "Qual o tamanho? ";
                                cin >> k;
                            } 
                            else {ok = true; break;}
                        }
                        system("clear");
                        Wn(k);
                        cout << endl << endl;
                        Print(G_criado,k+1);
                        cout << endl << endl;
                        cout << "Digite uma letra ou um numero para continuar..." << endl;
                        cin >> tecla;
                        system("clear");
                        break;


                    default: break;
                }
            break;

        case 4:
                int n1, n2;
                cout << endl;
                cout << "Qual o tamanho da parte superior? ";
                cin >> n1;
                cout << "Qual o tamanho da parte inferior? ";
                cin >> n2;
                while(!ok){   
                    if (n1<1 && n2<1){
                        cout << "O tamanho de ambos tem que ser maior ou igual a 1!" << endl;
                        cout << "Qual o tamanho da parte superior? ";
                        cin >> n1;
                        cout << "Qual o tamanho da parte inferior? ";
                        cin >> n2;
                    } 
                    else ok = true;
                }
                system("clear");
                Kn1_n2(n1,n2);
                cout << endl << endl;
                Print(G_criado,n1+n2);
                cout << endl << endl;
                cout << "Digite uma letra ou um numero para continuar..." << endl;
                cin >> tecla;
                system("clear");
                break;
        default: break;
    }
}


// =====================================================
// GRAFOS DE MYCIELSKY
// =====================================================

int base(int w){
    for(int i=0;i<w;i++){
        for(int j=0;j<w;j++){
            if(i==j) M_AUX[i][j] = 0;
            else M_AUX[i][j] = 1;
        }
    }
}

int Mycielsky(){

    memset(G_criado,0,sizeof(G_criado));
    memset(M_AUX,0,sizeof(M_AUX));

    int num_crom=0,w=0;
    bool ok;
    ok = false;

    cout << "Digite o valor da clique maxima de G: ";
    cin >> w;
    cout << "Digite o valor do numero cromatico: ";
    cin >> num_crom;

    while(!ok){
        if (w > num_crom) {
            cout << "O numero cromatico tem que ser maior ou igual ao numero da clique" << endl;
            cout << "Digite o valor da clique maxima de G: ";
            cin >> w;
            cout << "Digite o valor do numero cromatico: ";
            cin >> num_crom;
        }
        else {ok = true; break;}
    }

    if(w == num_crom) base(w), Print(M_AUX,w);
    else {
        int a1 = w + num_crom;
        base(w);
        for(int i=0;i<a1;i++){
            for(int j=0;j<a1;j++){
                if(i==j) {
                    G_criado[i][j] = 0; 
                }else{
                    if(i==0 && j<num_crom) G_criado[i][j] = 1;
                    else if(j==0 && i<num_crom) G_criado[i][j] = 1;
                    else {
                        if(i>= num_crom && j>=num_crom) G_criado[i][j] = M_AUX[i-num_crom][j-num_crom];
                        else if(i>=num_crom) G_criado[i][j] = M_AUX[i-num_crom][j-1];
                        else if(j>=num_crom) G_criado[i][j] = M_AUX[i-1][j-num_crom];
                    }
                }
            }
        }

        Print(G_criado, a1);
    }

    

}

// =====================================================
// PREENCHIMENTO DA MATRIZ
// =====================================================

int Fill_Matriz(int n){
    
    int x,y;
    bool verificado = false;

    memset(G,0,sizeof(G));
    memset(cor, -1, sizeof(cor));
    
    do{
        cout << "Digite as arestas!" << endl;
        cin >> x >> y;
        if(x>=0 && y>=0){
            G[x][y]=1;
            G[y][x]=1;
        }
        
    }while((x > -1 && x < n) && (y > -1 && y < n));

}


int Save_File(int n,int M[1010][1010],string filename){

    fstream myFile;
    myFile.open(filename, fstream::out);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            myFile << M[i][j] << " ";
        }
        myFile << endl;
    }

    myFile.close();
}

// =====================================================
// ARQUIVOS
// =====================================================

int Read_File(string filename){
    
    char c;
    int tmp;
    vector<int> aux;
    tam_f = 0;n = 0;

    ifstream myFile;
    myFile.open(filename);

    memset(G,0,sizeof(G));
    memset(cor, -1, sizeof(cor));

    myFile.get(c);
    while(myFile){
        while(c != '\n') {
            if(isdigit(c)){
                tmp = c - 48 ;
                aux.push_back(tmp); 
                tam_f++;
            } 
            myFile.get(c); 
        }
        F.push_back(aux);
        

        aux.clear();
        myFile.get(c);
    }

    tam_f = sqrt(tam_f);


    for(int i=0; i<tam_f;i++) {
        for(int j=0;j<tam_f;j++) G[i][j] = F[i][j];
    }

    F.clear();

    myFile.close();
    n = tam_f;
}



// =====================================================
// PROGRAMA PRINCIPAL
// =====================================================

int main(void){

    int op,cubo,opcubo;
    string Filename;
    bool ok = false;
    char tecla;

    cout << "O que deseja fazer?" << endl;
    cout << "1 - Preencher a Matriz" << endl;
    cout << "2 - Imprimir" << endl;
    cout << "3 - Salvar em arquivo" << endl;
    cout << "4 - Ler o arquivo" << endl;
    cout << "5 - Verificar se o grafo eh bipartido" << endl;
    cout << "6 - Gerar Grafos" << endl;
    cout << "7 - Checar se eh conexo" << endl;
    cout << "8 - Arvore Geradora" << endl;
    cout << "9 - Grafo de Mycielsky" << endl;
    cout << "10 - Finalizar Programa" << endl;
    cout << "Escolha: ";
    cin >> op;
    

    if(op == 10) return 0;

    while(op != 10){
        switch(op){

            case 1: system("clear");
                    cout << endl;
                    cout << endl;
                    cout << "Quantos elementos por linha tem a matriz?" << endl;
                    cout << "Num de elementos: ";
                    cin >> n;
                    Fill_Matriz(n);
                    ok = true;
                    cout << endl;
                    cout << endl;
                    break;
                    

            case 2: 
                    system("clear");
                    cout << endl;
                    cout << endl;
                    if(ok) Print(G,n);
                    else cout << "Nao existe matriz preenchida ainda!" << endl;
                    cout << endl;
                    cout << "Digite uma letra para continuar..." << endl;
                    cin >> tecla;
                    system("clear");
                    break;

            case 3: system("clear");
                    cout << endl;
                    cout << endl;
                    cout << "Digite o nome do arquivo: ";
                    cin >> Filename;
                    Filename = Filename + ".txt";
                    if(ok) Save_File(n,G,Filename);
                    else cout << "Nao existe matriz preenchida ainda!" << endl;
                    cout << endl;
                    cout << endl;
                    break;

            case 4: system("clear");
                    cout << endl;
                    cout << endl;
                    cout << "Digite o nome do arquivo: ";
                    cin >> Filename;
                    Filename = Filename + ".txt";
                    Read_File(Filename);
                    ok = true;
                    cout << endl;
                    cout << endl;
                    break;

            case 5: system("clear");
                    if(ok) cout << endl << endl << " --> O Grafo " << (checa_bipartido() ? "eh bipartido!":"nao eh bipartido") << endl << endl;
                    else cout << "Nao existe matriz preenchida ainda!" << endl;
                    cout << "Digite uma letra para continuar..." << endl;
                    cin >> tecla;
                    system("clear");
                    break;

            case 6: system("clear");
                    cout << endl;
                    cout << endl;
                    escolha_grafo();
                    break;


            case 7: system("clear");
                    cout << endl;
                    cout << endl;
                    checa_conexo();
                    cout << "Digite uma letra para continuar..." << endl;
                    cin >> tecla;
                    system("clear");
                    break;

            case 8: system("clear");
                    cout << endl;
                    cout << endl;
                    if(ok) {
                        Cria_Arvore();
                        Print(G_criado,n);   
                    }
                    else cout << "Nao existe matriz preenchida ainda!" << endl;
                    cout << endl << endl << "Digite uma letra para continuar..." << endl;
                    cin >> tecla;
                    system("clear");
                    break;

            case 9: system("clear");
                    cout << endl;
                    cout << endl;
                    Mycielsky();
                    cout << endl << endl << "Digite uma letra para continuar..." << endl;
                    cin >> tecla;
                    system("clear");
                    break;

            case 10: break;
                        
        }
        
        cout << "O que deseja fazer?" << endl;
        cout << "1 - Preencher a Matriz" << endl;
        cout << "2 - Imprimir" << endl;
        cout << "3 - Salvar em arquivo" << endl;
        cout << "4 - Ler o arquivo" << endl;
        cout << "5 - Verificar se o grafo eh bipartido" << endl;
        cout << "6 - Gerar Grafos" << endl;
        cout << "7 - Checar se eh conexo" << endl;
        cout << "8 - Arvore Geradora" << endl;
        cout << "9 - Grafo de Mycielsky" << endl;
        cout << "10 - Finalizar Programa" << endl;
        cout << "Escolha: ";
        cin >> op;
    }
    
}