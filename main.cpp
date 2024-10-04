#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node {
    float value;
    Node *next;
};

void output(Node *);
Node* addToFront(Node *, float);
Node* addToTail(Node *, float);
Node* deleteNode(Node *, int);
Node* insertNode(Node *, int, float);
Node* deleteList(Node *);

int main() {
    Node *head = nullptr;

    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        head = addToFront(head, tmp_val);
    }
    output(head);

    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    head = deleteNode(head, entry);
    output(head);

    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;

    head = insertNode(head, entry, 10000);
    output(head);

    head = deleteList(head);
    output(head);

    return 0;
}

void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

Node* addToFront(Node *head, float value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    return newNode;
}

Node* addToTail(Node *head, float value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (!head) {
        return newNode;
    }

    Node *current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node* deleteNode(Node *head, int pos) {
    if (!head) return nullptr;

    if (pos == 1) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *current = head;
    Node *prev = nullptr;
    for (int i = 1; i < pos && current; i++) {
        prev = current;
        current = current->next;
    }

    if (current) {
        prev->next = current->next;
        delete current;
    }

    return head;
}

Node* insertNode(Node *head, int pos, float value) {
    Node *newNode = new Node;
    newNode->value = value;

    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }

    Node *current = head;
    for (int i = 1; i < pos && current; i++) {
        current = current->next;
    }

    if (current) {
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}

Node* deleteList(Node *head) {
    Node *current = head;
    while (current) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    return nullptr;
}
