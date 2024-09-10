#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int length = s.length();
  for(int i = 1; i <= length; i++){
    for(int j = 0; j < length; j+= i){
      cout << s.substr(j,i)<<" ";
    }
    cout << '\n';
  }
  return 0;
}

