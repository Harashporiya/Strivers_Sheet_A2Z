#include<iostream>
#include<vector>
using namespace std;
vector<int> movedZeroLast(vector<int>& a, int n){
   vector<int> res;
   int countZero = 0;
   for(int i=0;i<n;i++){
    if(a[i] == 0){
        countZero++;
    }else{
        res.push_back(a[i]);
    }
   }

   for(int i=0;i<countZero;i++){
    res.push_back(0);
   }
   return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> arr = movedZeroLast(a,n);
    for(auto it:arr){
        cout<<it<<" ";
    }
}