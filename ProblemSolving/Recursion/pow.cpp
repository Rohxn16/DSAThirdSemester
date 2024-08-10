#include <iostream>
using namespace std;

double helper(double x, int n){
    //0 power
    if(n == 0) return 1;
    //even cases
        double ans = helper(x,n/2);
    if(n % 2 == 0){
        return ans * ans;
    }else{
        return x * ans * ans;
    }
    //odd case
}

double myPow(double x, int n) {
    int flag = 0;
    
    // takes care of -ve exponent
    if(n < 0){
        flag++;
        n *= -1;
    }

    double res = helper(x,n);
    if(flag == 1) return 1/res;
    else return res;
    
}

int main(int argc, char const *argv[])
{
    double x;
    int n;
    cin >> x >> n;
    double res = myPow(x,n);
    cout << res <<endl;
    return 0;
}
