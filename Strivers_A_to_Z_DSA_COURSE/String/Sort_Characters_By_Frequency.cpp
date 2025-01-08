#include <bits/stdc++.h>
using namespace std;
string frequencySort(string s)
{
    unordered_map<char, int> mpp;
    int n = s.length();
    for (char c : s)
    {
        mpp[c]++;
    }

    string temp = "";
    vector<pair<int, char>> freq;
    for (auto &it : mpp)
    {
        freq.push_back({it.second, it.first});
    }

    sort(freq.rbegin(), freq.rend());
    string result = "";
    for (auto &it : freq)
    {
        result += string(it.first, it.second);
    }

    return result;
    
}
int main()
{
    string s;
    cin >> s;
    cout << frequencySort(s);
}