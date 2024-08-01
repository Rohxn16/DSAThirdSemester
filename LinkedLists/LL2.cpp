#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }


};

    void display(Node* head){
        Node* curr = head;
        while(curr){
           cout << curr->data <<" -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }

    void insertAtHead(Node** head, int data){
        // the double pointer allows us to modify the address of a Node
        Node* newNode = new Node(data);
        newNode->next = *head;
        *head = newNode;
    }

    void deleteHead(Node** head){
        if(*head == nullptr) cout <<"Empty List\n";
        else{
            Node* temp = *head;
            *head = (*head)->next;
            delete temp;
        }
    }

int main(){
    Node* head = new Node(15);
    Node* second = new Node(12);
    Node* third = new Node(19);

    head->next = second;
    second->next = third;
    insertAtHead(&head,5);
    deleteHead(&head);
    display(head);

}