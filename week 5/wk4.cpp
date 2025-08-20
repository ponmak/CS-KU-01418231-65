#include<iostream>

using namespace std;

int** createGraph(int n){
    int** adjMatrix = new int*[n];
    for(int i = 0; i < n; i++){
        adjMatrix[i] = new int[n];
        for(int j = 0; j < n; j++){
            adjMatrix[i][j] = 0;
        }
    }
    return adjMatrix;
}

void addEdge(int** adjMatrix, int u, int v){
    adjMatrix[u][v] = 1;
}

void printGraph(int** adjMatrix, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n = 5;

    int** graph = createGraph(n);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 1, 4);

    printGraph(graph, n);

    return 0;
}