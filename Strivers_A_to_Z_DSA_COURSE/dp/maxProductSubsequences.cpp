#include <bits/stdc++.h>
using namespace std;

// int f(int i, int j, vector<int>& a, vector<int>& b) {
//     if (i == a.size() || j == b.size())
//         return INT_MIN;

//     int take = a[i] * b[j];
//     int next = f(i + 1, j + 1, a, b);
//     if (next != INT_MIN)
//         take += max(0, next);

//     int skipA = f(i + 1, j, a, b);
//     int skipB = f(i, j + 1, a, b);

//     return max({take, skipA, skipB});
// }

void f(int i,vector<int>& nums1,vector<int>& sub,vector<vector<int>> &subsequences){
        if(i==nums1.size()){
            if(!sub.empty()){
                subsequences.push_back(sub);
            }
            return;
        }

        sub.push_back(nums1[i]);
        f(i+1,nums1,sub,subsequences);
        sub.pop_back();
        f(i+1,nums1,sub,subsequences);
    }
int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> subsequences1,subsequences2;
        vector<int> sub;
        f(0,nums1,sub,subsequences1);
        int maxi=INT_MIN;
        sub.clear();
         f(0,nums2,sub,subsequences2);

        for(auto it1:subsequences1){
            for(auto it2:subsequences2){
                if(it1.size()!=it2.size())continue;
                int sum=0;
                for(int i=0;i<it1.size();i++){
                    sum+=it1[i]*it2[i];
                }
                maxi=max(maxi,sum);
         }
        }



        return maxi;
}

int main() {
    vector<int> nums1 = {2, 1, -2, 5};
    vector<int> nums2 = {3, 0, -6};
    cout << maxDotProduct(nums1, nums2) << endl;

    return 0;
}
