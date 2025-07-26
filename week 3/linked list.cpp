#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef struct node {
    int data;
    node* next;
} Node;

typedef struct linked_list {
    int length;
    Node* head;
    Node* tail;
}  NumList;

Node *newNode(){
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    return p;
}

void initList(NumList *list) {
    list->length = 0;
    list->head = newNode();
    list->tail = list->head;
}

void appendHeadList(NumList *list, Node *node) {
    node->next = list->head->next;
    list->head->next = node;
    if (list->length == 0) {
        list->tail = node;
    }
    list->length++;
}

void insertLast(NumList *list, Node *node) {
    list->tail->next = node;
    list->tail = node;
    list->length++;
}

void printNumList(NumList *list) {
    Node *p = list->head->next;
    while (p != NULL) {
        cout << "Num: " << p->data << endl;
        p = p->next;
    }
    cout << endl;
}

void deleteHead(NumList *list) {
    if (list->length == 0) return;
    Node *temp = list->head->next;
    list->head->next = temp->next;
    free(temp);
    list->length--;
    if (list->length == 0) {
        list->tail = list->head;
    }
}

int main(){

    NumList list;
    initList(&list);

    for (int i = 1; i <= 10; i++) {
        Node *node = newNode();
        node->data = i;
        appendHeadList(&list, node);
    }

    printNumList(&list);

    // show length
    cout << "Length: " << list.length << endl;

    return 0;
}