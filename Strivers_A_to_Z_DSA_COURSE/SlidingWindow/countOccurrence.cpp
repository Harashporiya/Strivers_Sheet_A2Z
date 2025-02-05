// Count Occurrences Of Anagrams | Sliding Window
#include <bits/stdc++.h>
using namespace std;
int countOccurrences(string s, string m)
{
    unordered_map<char, int> mpp;
    for (char c : m)
    {
        mpp[c]++;
    }
    int count = mpp.size();
    int k = m.length();
    int i = 0, j = 0;
    int ans = 0;
    while (j < s.length())
    {
        if (mpp.find(s[j]) != mpp.end())
        {
            mpp[s[j]]--;
            if (mpp[s[j]] == 0)
            {
                count--;
            }
        }

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (count == 0)
            {
                ans++;
            }
            if (mpp.find(s[i]) != mpp.end())
            {
                mpp[s[i]]++;
                if (mpp[s[i]] == 1)
                {
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    string str;
    cin >> str;
    string s;
    cin >> s;
    cout << countOccurrences(str, s);
}
