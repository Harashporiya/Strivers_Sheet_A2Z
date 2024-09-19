#include<iostream>
using namespace std;
void reverse1(int a[][], int n){
    int low=0;
    int high=n-1;
    while(low<=high){
        int t=a[low];
        a[low]=a[high];
        a[high]=t;
        low++;
        high--;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    
    int a[100][100];  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    // int ans[n][m];
    
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //       ans[j][n-1-i] = a[i][j];
    //     }
    // }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<m;j++){
            int t = a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        reverse1(a, n);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
