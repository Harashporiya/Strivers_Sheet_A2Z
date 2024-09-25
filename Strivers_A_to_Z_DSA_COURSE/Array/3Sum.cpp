#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int> &a, int n){
    vector<vector<int>> ans;
     sort(a.begin(), a.end());
     for(int i=0;i<n;i++){
        if(i>0 && a[i]==a[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum = a[i]+a[j]+a[k];
            if(sum<0){
                j++;
            }else if(sum>0){
                k--;
            }else{
                vector<int> temp ={a[i], a[j], a[k]};
                ans.push_back(temp);
               j++;
               k--;
               while(j<k && a[j]==a[j-1]) j++;
               while(j<k && a[k]==a[k+1]) k--;
            }
        }
     }
     return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>> res = threeSum(a,n);
   for(auto triplet : res){
     for(auto it : triplet){
        cout<<it<<" ";
    }
    cout<<endl;
   }
   
}