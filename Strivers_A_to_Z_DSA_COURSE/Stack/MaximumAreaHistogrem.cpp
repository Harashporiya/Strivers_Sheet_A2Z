#include<bits/stdc++.h>
using namespace std;
vector<int> leftNextSmollest(vector<int> & a, int n){
     vector<int> left;
     int psudoIndex = -1;
     stack<pair<int, int>> s;
     for(int i=0;i<n;i++){
        if(s.size()==0){
            left.push_back(psudoIndex);
        }else if(s.size()>0 && s.top().first<a[i]){
            left.push_back(s.top().second);
        }else if(s.size()>0 && s.top().first>=a[i]){
            while(s.size()>0 && s.top().first>=a[i]){
                s.pop();
            }
            if(s.size()==0){
                left.push_back(psudoIndex);
            }else{
                left.push_back(s.top().second);
            }
        }

        s.push({a[i],i});
     }
     return left;
}
vector<int> rightNextSmollest(vector<int> & a, int n){
     vector<int> right;
     int psudoIndex=-1;
     stack<pair<int, int>> s;
     for(int i=n-1;i>=0;i--){
        if(s.size()==0){
            right.push_back(psudoIndex);
        }else if(s.size()>0 && s.top().first<a[i]){
            right.push_back(s.top().second);
        }else if(s.size()>0 && s.top().first>=a[i]){
            while(s.size()>0 && s.top().first>=a[i]){
                s.pop();
            }
            if(s.size()==0){
                right.push_back(psudoIndex);
            }else{
                right.push_back(s.top().second);
            }
        }
        s.push({a[i],i});
     }
     reverse(right.begin(), right.end());
     return right;
     
}
int maxHistogrem(vector<int> &a, int n){
   vector<int> left = leftNextSmollest(a,n);
   vector<int> right = rightNextSmollest(a,n);
   vector<int> width;
    vector<int> area;
   for(int i=0;i<n;i++){
      width.push_back(right[i]-left[i]-1);
   }
   for(int i=0;i<n;i++){
      area.push_back(a[i]*width[i]);
   }
   int max=area[0];
   for(int i=0;i<n;i++){
    if(max<area[i]){
        max = area[i];
    }
   }
   return max;


}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
  int ans = maxHistogrem(a,n);
  cout<<ans;
}