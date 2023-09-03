#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &A, int B)
{

    long mod = 1000000007, ans = 0;

    int l = 0, r = A.size() - 1;

    while (l < A.size() && r >= 0) // Loop through entire array, as its sorted if we find product < B add to ans r+1 'cause evrything less than r would be smaller too
    {
        if (1l * A[l] * A[r] >= B)
        {
            r--;
        }
        else
        {
            ans = (ans % mod + (r + 1) % mod) % mod;
            l++;
        }
    }
    return int(ans % mod);
}