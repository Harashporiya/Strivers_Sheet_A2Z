#include<iostream>
using namespace std;

// void matrixZero(int a[100][100], int n, int m) {
//     int row[100] = {0};  
//     int col[100] = {0};  

  
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (a[i][j] == 0) {
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     }

   
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (row[i] == 1 || col[j] == 1) {
//                 a[i][j] = 0;
//             }
//         }
//     }
// }

int main() {
    int n, m;
    cin >> n >> m;
    
    int a[100][100];  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    
    // matrixZero(a, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
           if(a[i][j]==0){
            for(int k=0;k<m;k++){
               if(a[i][k]!=0){
                a[i][k]=-1;
               }
            }

            for(int l=0;l<n;l++){
               if(a[l][i]!=0){
                a[l][i]=-1;
               }
            }
           }
        }
    }
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (a[i][j] == -1) {
            a[i][j] = 0; 
        }
    }
}
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
