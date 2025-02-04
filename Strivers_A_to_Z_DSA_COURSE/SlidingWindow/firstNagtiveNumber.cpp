//First Negative Number in every Window of Size K
#include<bits/stdc++.h>
using namespace std;
vector<int> firstNegativeNumber(vector<int> &a, int n, int k){
    queue<int> q;
    vector<int> ans;

    int i=0,j=0;
    while(j<n){
        if(a[j]<0){
            q.push(a[j]);
        }
        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            if(q.empty()){
                ans.push_back(0);
            }else{
                ans.push_back(q.front());
                if(a[i]==q.front()){
                    q.pop();
                }
            }
            i++;
           j++;
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
    int k;
    cin>>k;

    vector<int> res = firstNegativeNumber(a,n,k);
    for(auto it:res){
        cout<<it<<" ";
    }
}