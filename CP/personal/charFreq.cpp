#include <iostream>
using namespace std;

int main(int argc, char const* argv[]){
    string s;
    cin >> s;
    int arr[26] = {0};

    for(char i = 'a'; i <= 'z'; i++){
        for(char ch : s){
            if(ch == i){
                arr[(int)i - 97]++;
            }
        }

    }

    for(char i = 'a'; i <= 'z'; i++){
        cout << i <<" ";
    }
    cout <<"\n";
    for(int i = 0; i < 26; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";

}