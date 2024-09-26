#include <iostream>
#include <vector>
using namespace std;
int maxProduct(vector<int> &a, int n)
{
    int maxi = 0;
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        product *= a[i];

        maxi = max(maxi, product);

        if (product == 0)
        {
            product = 1;
        }
    }
    product = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        product *= a[i];

        maxi = max(maxi, product);

        if (product == 0)
        {
            product = 1;
        }
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