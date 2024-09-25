#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> &a, int n, int target){
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    for(int i=0;i<n;i++){
        if(i>0 && a[i]==a[i-1]) continue;
       for(int j=i+1;j<n;j++){
        if(j>i+1 && a[j]==a[j-1]) continue;
         
        int k = j+1;
        int l=n-1;
        while(k<l){
            int sum=a[i]+a[j]+a[k]+a[l];
            if(sum<target){
                k++;
            }else if(sum>target){
                l--;
            }else {
                ans.push_back({a[i],a[j],a[k],a[l]});
                k++;
                l--;
                while(k<l && a[k]==a[k-1]) k++;
                while(k<l && a[l]==a[l+1]) l--;
            }
        }

       }
    }
    return ans;
}
int main(){
    int n, target;
    cin>>n>> target;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<vector<int>> res = fourSum(a,n, target);

    for(auto fourlet:res){
        for(auto it:fourlet){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}