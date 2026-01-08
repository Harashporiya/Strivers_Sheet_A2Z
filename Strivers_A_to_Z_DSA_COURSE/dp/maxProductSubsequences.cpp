#include <bits/stdc++.h>
using namespace std;


// void f(int i,vector<int>& nums1,vector<int>& sub,vector<vector<int>> &subsequences){
//         if(i==nums1.size()){
//             if(!sub.empty()){
//                 subsequences.push_back(sub);
//             }
//             return;
//         }

//         sub.push_back(nums1[i]);
//         f(i+1,nums1,sub,subsequences);
//         sub.pop_back();
//         f(i+1,nums1,sub,subsequences);
//     }
// int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
//         vector<vector<int>> subsequences1,subsequences2;
//         vector<int> sub;
//         f(0,nums1,sub,subsequences1);
//         int maxi=INT_MIN;
//         sub.clear();
//          f(0,nums2,sub,subsequences2);

//         for(auto it1:subsequences1){
//             for(auto it2:subsequences2){
//                 if(it1.size()!=it2.size())continue;
//                 int sum=0;
//                 for(int i=0;i<it1.size();i++){
//                     sum+=it1[i]*it2[i];
//                 }
//                 maxi=max(maxi,sum);
//          }
//         }



//         return maxi;
// }
int f(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp){
        if(i==nums1.size()||j==nums2.size()){
            return INT_MIN;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int take=nums1[i]*nums2[j];
        int n = f(i+1,j+1,nums1,nums2,dp);
        if(n>0){
            take+=n;
        }

        int notTake1=f(i,j+1,nums1,nums2,dp);
        int notTake2=f(i+1,j,nums1,nums2,dp);

        return dp[i][j]=max({take,notTake1,notTake2});
    }
int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,INT_MIN));

        for(int i=nums1.size()-1;i>=0;i--){
            for(int j=nums2.size()-1;j>=0;j--){
                int take=nums1[i]*nums2[j];
                if(dp[i+1][j+1]!=INT_MIN){
                    take +=max(0, dp[i+1][j+1]);
                }

                int notTake1=dp[i][j+1];
                int notTake2=dp[i+1][j];
                dp[i][j]=max({take,notTake1,notTake2});
            }
        }

       return dp[0][0];
    }  

int main() {
    vector<int> nums1 = {2, 1, -2, 5};
    vector<int> nums2 = {3, 0, -6};
    cout << maxDotProduct(nums1, nums2) << endl;

    return 0;
}
