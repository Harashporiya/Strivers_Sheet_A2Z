#include<bits/stdc++.h>
using namespace std;
bool isNStraightHand(vector<int>& hand, int groupSize) {
   unordered_map<int, int> mpp;
   priority_queue<int, vector<int>, greater<int>> minHeap;
   for(int i=0;i<hand.size();i++){
    mpp[hand[i]]++;
   }

   for(auto card:mpp){
    minHeap.push(card.first);
   }

//    sort(hand.begin(),hand.end());

//    for(int card:hand){
//     if(mpp[card]>0){
//         for(int i=0;i<groupSize;i++){
//             if(mpp[card + i]==0){
//                 return false;
//             }
//             mpp[card+i]--;
//         }
//     }
//    }
     while(!minHeap.empty()){
        int start = minHeap.top();
        for(int i=0;i<groupSize;i++){
            if(mpp[start+i]==0){
                return false;
            }
            mpp[start+i]--;
            if(mpp[start+i]==0){
                minHeap.pop();
            }
        }
     }
   return true;
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