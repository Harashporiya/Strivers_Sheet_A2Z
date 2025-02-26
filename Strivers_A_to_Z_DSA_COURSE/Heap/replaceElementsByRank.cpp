#include<bits/stdc++.h>
using namespace std;

vector<int> replaceElements(int a[], int N) {
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;
    //   set<pair<int, int>> sorted;
     for (int i = 0; i < N; i++) {
        // sorted.insert({a[i], i});
        minHeap.push({a[i],i});
    }

    vector<int> res(N);
    int rank=1;
    int prev_value=-1;


    while(!minHeap.empty()){
        int value = minHeap.top().first;
        int index = minHeap.top().second;
        minHeap.pop();
        
        if(value!=prev_value){
            prev_value=value;
            res[index] = rank++;
        }else{
            res[index] = rank-1;
        }
    }


    return res;
}

int main() {
    int a[] = {2, 2, 1, 6};
    int n = sizeof(a) / sizeof(a[0]);

    vector<int> ans = replaceElements(a, n);

    for(auto it : ans) {
        cout << it<<" ";
    }
    cout << endl;

    return 0;
}
