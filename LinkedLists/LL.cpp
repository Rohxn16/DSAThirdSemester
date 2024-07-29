#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }

};

int main(){
    int arr[] = {1,2,3,4,5};
    Node node = Node(arr[0],nullptr);
    Node* nodepath = new Node(arr[1],nullptr);
    cout << node.data<<endl;
    cout << nodepath <<endl;
    // cout << *nodepath <<endl; -> this line throws error as nodepath is already a pointer
}