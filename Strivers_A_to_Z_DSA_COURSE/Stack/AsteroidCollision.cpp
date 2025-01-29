#include <bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int> &a)
{
    stack<int> s;
    for (int i = 0; i < a.size(); i++)
    {
        bool dest = false;
        while (!s.empty() && s.top() > 0 && a[i] < 0)
        {
            if (s.top() < abs(a[i]))
            {
                s.pop();
                continue;
            }
            else if (s.top() == abs(a[i]))
            {
                s.pop();
            }
            dest = true;
            break;
        }
        if (!dest)
        {
            s.push(a[i]);
        }
    }
    vector<int> res(s.size());
    for (int i = s.size() - 1; i >= 0; i--)
    {
        res[i] = s.top();
        s.pop();
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> ans = asteroidCollision(a);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}