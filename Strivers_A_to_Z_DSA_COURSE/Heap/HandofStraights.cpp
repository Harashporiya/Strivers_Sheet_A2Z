#include<bits/stdc++.h>
using namespace std;
bool isNStraightHand(vector<int>& hand, int groupSize) {
   unordered_map<int, int> mpp;
   for(int i=0;i<hand.size();i++){
    mpp[hand[i]]++;
   }

   sort(hand.begin(),hand.end());

   for(int card:hand){
    if(mpp[card]>0){
        for(int i=0;i<groupSize;i++){
            if(mpp[card + i]==0){
                return false;
            }
            mpp[card+i]--;
        }
    }
   }
   return false;
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
     if( isNStraightHand(a,k) == 1){
        cout<<"true";
     }else{
        cout<<"false";
     }
}