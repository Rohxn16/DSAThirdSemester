#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void brute_force_matrix_rotation(){
  int n;
  cin >> n;
  int arr[n][n];


  // array input from user
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> arr[i][j];
    }
  }

  // rotating the array into a new array;
  int rotated[n][n];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      rotated[j][n-i-1] = arr[i][j];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << rotated[i][j] << " ";
    }
    cout << endl;
  }
}

void rotateMatrixOptimized(){
  int row,col;
  cin >> row >> col;
  int arr[row][col];
  for(int i = 0;i < row; i++){
    for(int j = 0; j < col; j++){
      cin >> arr[i][j];
    }
  }

  // rotate the matrix into a new matrix with optimized approach
  int rotated[col][row];
  
}


int main(){
  brute_force_matrix_rotation();
  return 0;
}
