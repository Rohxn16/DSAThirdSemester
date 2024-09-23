#include <bits/stdc++.h>
using namespace std;

int findMax(string s, int n){
    
    vector<int> substrings;
    int max = -1;

    // getting all substrings of size n from the string s and putting them in the substrings vector in integer form if they are even numbers
    for(int i = 0; i < s.size(); i++){
        if(i+n <= s.size()){
            string sub = s.substr(i, n);
            int num = stoi(sub);
            if(num % 2 == 0){
                substrings.push_back(num);
            }
        }
    }

    // finding the max number from there and returning it, if the vector is empty returning -1
    if(substrings.size() == 0){
        return -1;
    }else{
        for(int i = 0; i < substrings.size(); i++){
            if(substrings[i] > max){
                max = substrings[i];
            }
        }
        return max;
    }
}

int main(){
    string s;
    int n;
    cin >> s >> n;
    cout << findMax(s, n) << endl;
    return 0;
}