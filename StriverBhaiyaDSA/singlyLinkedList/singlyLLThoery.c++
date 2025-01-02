#include <bits/stdc++.h>
using namespace std;

// Creation of Linkedlist
class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

Node* convertArrToSLL(vector<int> arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }
    return head;
}

Node* insertAtHead(Node* head, int val) {
    return new Node(val, head);
}

Node* insertAtEnd(Node* head, int val) {
    if (!head) return new Node(val);
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}

Node* insertAtK(Node* head, int val, int k) {
    if (k <= 1) return insertAtHead(head, val);
    Node* temp = head;
    int cnt = 1;
    while (temp && cnt < k - 1) {
        temp = temp->next;
        cnt++;
    }
    if (temp) {
        temp->next = new Node(val, temp->next);
    }
    return head;
}

Node* insertAtValue(Node* head, int val, int value) {
    Node* temp = head;
    while (temp && temp->next) {
        if (temp->next->data == value) {
            temp->next = new Node(val, temp->next);
            return head;
        }
        temp = temp->next;
    }
    return head;
}

Node* deleteHead(Node* head) {
    if (!head) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteTail(Node* head) {
    if (!head) return nullptr;
    if (!head->next) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while (temp->next && temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* deleteAtKth(Node* head, int k) {
    if (!head || k <= 0) return head;
    if (k == 1) return deleteHead(head);
    Node* temp = head;
    int cnt = 1;
    while (temp && cnt < k - 1) {
        temp = temp->next;
        cnt++;
    }
    if (temp && temp->next) {
        Node* temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
    }
    return head;
}

Node* deleteAtValue(Node* head, int val) {
    if (!head) return nullptr;
    if (head->data == val) return deleteHead(head);
    Node* temp = head;
    while (temp && temp->next) {
        if (temp->next->data == val) {
            Node* temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

void traverseSLL(Node* head) {
    cout << "\n";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    Node* head = convertArrToSLL(arr);
    traverseSLL(head);

    head = insertAtHead(head, 9);
    traverseSLL(head);

    head = insertAtEnd(head, 11);
    traverseSLL(head);

    head = insertAtK(head, 18, 3);
    traverseSLL(head);

    head = insertAtValue(head, 21, 5);
    traverseSLL(head);

    head = deleteHead(head);
    traverseSLL(head);

    head = deleteTail(head);
    traverseSLL(head);

    head = deleteAtKth(head, 6);
    traverseSLL(head);

    head = deleteAtValue(head, 18);
    traverseSLL(head);

    return 0;
}
