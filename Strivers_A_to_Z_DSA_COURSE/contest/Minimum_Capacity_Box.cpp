#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        vector<pair<int,int>> res;
        
        for(int i = 0; i < capacity.size(); i++){
            if(capacity[i] >= itemSize){
                res.push_back({capacity[i], i});
            }
        }

        if(res.size() == 0) return -1;

        sort(res.begin(), res.end());

        return res[0].second;
    }
};

int main() {
    Solution obj;

    vector<int> capacity = {5, 3, 8, 6, 2};
    int itemSize = 4;

    int result = obj.minimumIndex(capacity, itemSize);

    cout << "Minimum index with enough capacity: " << result << endl;

    return 0;
}