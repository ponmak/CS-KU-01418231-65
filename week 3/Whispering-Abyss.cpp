// 6710405427 : linked list 
#include <iostream>
#include <cstdio>
#include <cstdlib>

typedef struct Node {
    int data;
    Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// void deleteNode(Node* &head, int x) {

//     Node* current = head;
//     Node* prev = NULL;

//     for (int i = 0; i < x; i++) {
//         prev = current;
//         current = current->next;
//     }

//     Node* toDelete = current;
//     prev->next = toDelete->next;
    
//     free(toDelete);

// }

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    int n, x;

    cin >> n >> x;

    Node* head = createNode(1);

    Node* maker = head;
    for (int i = 2; i <= n; ++i) {
        maker->next = createNode(i);
        maker = maker->next;
    }

    // cycle linked list
    maker->next = head;

    // for (int i = 0; i < n; i++){
    //     cout << maker->data << " ";
    //     maker = maker->next;
    // }


    // azkaban remake
    Node* current = head;

    for (int i = 0; i < n; i++) {

        Node* prev = current;

        for (int j = 0; j < x - 1 ; j++){
            prev = current;
            current = current->next;
        }


        cout << current->data << " ";
        Node* toDelete = current;
        prev->next = toDelete->next;

        current = prev->next;
        free(toDelete);
    }


    return 0;
}