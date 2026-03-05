#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

   int binarySearch(vector<int>&a,int t){
        int l = 0;
        int h = a.size() - 1;

        while(l <= h){
            int mid = l + (h - l) / 2;

            if(a[mid] == t){
                return mid;
            } 
            else if(a[mid] > t){
                h = mid - 1;
            } 
            else{
                l = mid + 1;
            }
        }

        return l;
   }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;

        for(int num : nums){
            if(res.empty() || res.back() < num){
                res.push_back(num);
            } else {
                int ind = binarySearch(res, num);
                res[ind] = num;
            }
        }
        return res.size();
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << "Length of LIS: " << obj.lengthOfLIS(nums) << endl;

    return 0;
}