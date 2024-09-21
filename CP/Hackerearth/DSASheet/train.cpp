#include<bits/stdc++.h>
using namespace std;

long long solve (int N, int start, int finish, vector<int> Ticket_cost) {
   // Write your code here
   // |-------------------|
   // v                   |
   // 1 -> 2 -> 3 -> 4 ---|
    
    long long cost1 = 0;
    long long cost2 = 0;

    for(int i = start; i < finish; i++){
        cost1 += Ticket_cost[i-1];
    }

    for(int i = 1; i < start; i++){
        cost2 += Ticket_cost[i-1];
    }

    for(int i = finish; i > N; i++){
        cost2 += Ticket_cost[i-1];
    }
    cost2 += Ticket_cost[N-1];

    return cost2>cost1?cost1:cost2;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int start;
    cin >> start;
    int finish;
    cin >> finish;
    vector<int> Ticket_cost(N);
    for(int i_Ticket_cost = 0; i_Ticket_cost < N; i_Ticket_cost++)
    {
    	cin >> Ticket_cost[i_Ticket_cost];
    }

    long long out_;
    out_ = solve(N, start, finish, Ticket_cost);
    cout << out_;
}