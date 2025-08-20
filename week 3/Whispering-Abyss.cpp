// 6710405427 : linked list 
#include <iostream>
#include <cstdio>
#include <cstdlib>

typedef struct Node {
    int data;
    Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = new Node();
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

//     int Josephus(int N, int k)
// {

//     // Initialize variables i and ans with 1 and 0
//     // respectively.

//     int i = 1, ans = 0;

//     // Run a while loop till i <= N

//     while (i <= N) {

//         // Update the Value of ans and Increment i by 1
//         ans = (ans + k) % i;
//         i++;
//     }

//     // Return required answer
//     return ans + 1;
// }


    // cout << "x: " << x << endl;

    // azkaban remake : Josephus
    Node* current = head;
    Node* prev = NULL;
    while (current->next != current) {

        if (current == prev) {
            break;
        }

        int step = (x - 1) % n;
        for (int i = 0; i < step; i++) {
            prev = current;
            current = current->next;
        }
        
        cout << current->data << " ";

        Node* toDelete = current;
        prev->next = toDelete->next;
        delete(toDelete);

        // cout << endl;
        
        n--;
        current = prev->next;
    }

    cout << current->data << endl;


    return 0;
}