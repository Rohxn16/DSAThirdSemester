#include <bits/stdc++.h>

using namespace std;

void solve(int n, int A[], int B[]){
    // approach 1: I can first try to take the two arrays and combine them into 
    // numbers and find out the larger one and then spot from where the anomaly 
    // starts and till where in continues and return the last index - first index + 1

    int match = 0;
    for(int i = 0; i < n; i++){
        if(A[i] != B[i]){
            match++;
            break;
        }
    }

    if(match == 0){
        cout << 0 <<'\n';
    }else{
        int flag = 0;
        int start,end;
        start = 0;
        end = 0;
        for(int i = 0; i < n; i++){
            if(A[i] != B[i]){
                if(flag == 0){
                    start = i;
                    flag++;
                }else{
                    end = i;
                }
            }
        }
        cout << end - start + 1<<'\n';
    }

}

int main(){
int t;
cin >> t;
while (t--)
{   
    int n;
    cin >> n;

    int A[n];
    int B[n];

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        cin >> B[i];
    }
    solve(n,A,B);
}


    return 0;
}