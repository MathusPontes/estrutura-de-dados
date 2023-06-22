/*
Faça um programa que receba 20 números e armazene os pares em uma lista
simplesmente encadeada e não ordenada e os ímpares em uma segunda lista
simplesmente encadeada e não ordenada. Posteriormente, o programa deve montar
uma terceira lista, duplamente encadeada e ordenada de forma crescente, com os
números das duas listas anteriores. Para finalizar, o programa deve mostrar todos os
números da terceira lista das seguintes formas:
a. Crescente.
b. Decrescente.
*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertNode(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void displayList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int getListLength(Node* head) {
    int length = 0;
    Node* curr = head;
    while (curr != nullptr) {
        length++;
        curr = curr->next;
    }
    return length;
}

void bubbleSort(Node*& head) {
    int length = getListLength(head);
    if (length <= 1) {
        return;
    }

    bool swapped;
    Node* curr;
    Node* prev = nullptr;

    do {
        swapped = false;
        curr = head;

        while (curr->next != prev) {
            if (curr->data > curr->next->data) {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swapped = true;
            }
            curr = curr->next;
        }
        prev = curr;
    } while (swapped);
}

Node* mergeLists(Node* list1, Node* list2) {
    Node* mergedList = nullptr;
    Node* tail = nullptr;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data <= list2->data) {
            if (mergedList == nullptr) {
                mergedList = list1;
                tail = list1;
                list1 = list1->next;
            } else {
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            }
        } else {
            if (mergedList == nullptr) {
                mergedList = list2;
                tail = list2;
                list2 = list2->next;
            } else {
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }
        }
    }

    if (list1 != nullptr) {
        tail->next = list1;
    } else if (list2 != nullptr) {
        tail->next = list2;
    }

    return mergedList;
}

int main() {
    Node* evenList = nullptr;
    Node* oddList = nullptr;

    cout << "Digite 20 números: " << endl;
    for (int i = 0; i < 20; i++) {
        int num;
        cin >> num;

        if (num % 2 == 0) {
            insertNode(evenList, num);
        } else {
            insertNode(oddList, num);
        }
    }

    bubbleSort(evenList);
    bubbleSort(oddList);

    Node* mergedList = mergeLists(evenList, oddList);

    cout << "Lista mesclada em ordem crescente: ";
    displayList(mergedList);

    Node* reversedList = nullptr;
    Node* curr = mergedList;
    while (curr != nullptr) {
        Node* newNode = new Node;
        newNode->data = curr->data;
        newNode->next = reversedList;
        reversedList = newNode;
        curr = curr->next;
    }

    cout << "Lista mesclada em ordem decrescente: ";
    displayList(reversedList);

    return 0;
}
