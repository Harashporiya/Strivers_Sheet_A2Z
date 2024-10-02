
// brute solution
// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     int m,n;
//     cin>>m>>n;
//     int a1[m],a2[n];
//     for(int i=0;i<m;i++){
//         cin>>a1[i];
//     }
//     for(int i=0;i<n;i++){
//         cin>>a2[i];
//     }
    
//     vector<int> ans;
//     for(int i=0;i<m;i++){
//         int count=0;
//         for(int j=0;j<n;j++){
//           if(a1[i]>=a2[j]){
//             count++;
            
//           }
//         }
//         ans.push_back(count);
//     }
    
    
//     for(auto it:ans){
//         cout<<it<<" ";
//     }
// }



#include<bits/stdc++.h>
using namespace std;


int upper_bound_custom(const vector<int>& arr, int target) {
    int low = 0, high = arr.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        
        if (arr[mid] <= target) {
            low = mid + 1;
        }
       
        else {
            high = mid;
        }
    }

   
    return low;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> a1(m), a2(n);

    for (int i = 0; i < m; i++) {
        cin >> a1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> a2[i];
    }

 
    sort(a2.begin(), a2.end());

    vector<int> result;

    for (int i = 0; i < m; i++) {
       
        int count = upper_bound_custom(a2, a1[i]);
        result.push_back(count);
    }

   
    for (int count : result) {
        cout << count << " ";
    }

    return 0;
}
