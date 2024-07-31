#include <bits/stdc++.h>
using namespace std;

struct Node{
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

    Node* convertArraytoLL(vector<int> arr){
        Node* head = new Node(arr[0]);
        
        for(int i = 1; i < arr.size(); i++){
            // complete the program to convert array to linked list
            
        }
    }

};

int main(){
    int arr[] = {1,2,3,4,5};
    Node node = Node(arr[0],nullptr);
    // Node* nodepath = new Node(arr[1],nullptr);
    Node node2 = Node(arr[1],node.next);
    Node node3 = Node(arr[2],node2.next);
    Node node4 = Node(arr[3],node3.next);

    cout << node.data <<endl;
    // cout << *nodepath <<endl; -> this line throws error as nodepath is already a pointer
}