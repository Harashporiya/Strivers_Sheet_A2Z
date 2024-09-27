#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int maxProduct(vector<int> &a, int n)
{
    int maxi = INT_MIN;
    int product = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     product *= a[i];

    //     maxi = max(maxi, product);

    //     if (product == 0)
    //     {
    //         product = 1;
    //     }
    // }
    // product = 1;
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     product *= a[i];

    //     maxi = max(maxi, product);

    //     if (product == 0)
    //     {
    //         product = 1;
    //     }
    // }
    int suff = 1;
    for(int i=0;i<n;i++){
        if(product==0) product=1;
        if(suff==0) suff=1;
        product*=a[i];
        suff*=a[n-i-1];
        maxi=max(maxi, max(product,suff));
    }
    return maxi;
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

    int ans = maxProduct(a, n);
    cout << ans;
}