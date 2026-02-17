#include <bits/stdc++.h>
using namespace std;

void abc(char s[])
{
    if (s[0] == '\0')
        return;

    abc(s + 1);
    abc(s + 1);
    cout << s[0];
}

int fun(int count)
{
    cout << count << endl;
    if (count < 3)
    {
        fun(fun(fun(++count)));
    }
    return count;
}
void sortarr(vector<int> &arr, int l, int r)
{
    if (r < l)
        return;
    int mn = INT_MAX, mnidx = -1;
    for (int i = l; i <= r; i++)
    {
        if (arr[i] <= mn)
        {
            mn = arr[i];
            mnidx = i;
        }
    }
    swap(arr[mnidx], arr[l]);
    sortarr(arr, l + 1, r);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // abc("xyz");
    // fun(1);
    vector<int> arr{5, 4, 45, 2, 1};
    sortarr(arr, 0, arr.size() - 1);
    for (auto x : arr)
        cout << x << " ";
    return 0;
}
// factorial of a large number
// User function template for C++

class Solution
{
public:
    vector<int> factorial(int n)
    {
        // code here
        if (n == 1)
            return {1}; // base case
        // induction step
        vector<int> res = factorial(n - 1);
        int carry = 0;
        // hypothesis
        for (int i = res.size() - 1; i >= 0; i--)
        {
            int temp = res[i] * n + carry;
            res[i] = (temp) % 10;
            carry = temp / 10;
        }
        while (carry > 0)
        {
            res.insert(res.begin(), carry % 10);
            carry = carry / 10;
        }
        return res;
    }
};
// using reverse
// User function template for C++

class Solution
{
public:
    vector<int> factorial(int n)
    {
        // code here
        auto res = helper(n);
        reverse(res.begin(), res.end());
        return res;
    }
    vector<int> helper(int n)
    {
        if (n == 1)
            return {1}; // base case
        // induction step
        vector<int> res = helper(n - 1);
        // reversed
        int carry = 0;
        // hypothesis
        for (int i = 0; i < res.size(); i++)
        {
            int temp = res[i] * n + carry;
            res[i] = (temp) % 10;
            carry = temp / 10;
        }
        while (carry > 0)
        {
            res.push_back(carry % 10);
            carry = carry / 10;
        }
        return res;
    }
};
// clumsy factorial
class Solution
{
public:
    int clumsy(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        return 2 * (n * (n - 1) / (n - 2)) + helper(n);
    }
    int helper(int x)
    {
        // base case
        if (x == 0)
            return 0;
        if (x == 1)
            return -1;
        if (x == 2)
            return -2;
        if (x == 3)
            return -6;
        return -x * (x - 1) / (x - 2) + x - 3 + helper(x - 4);
    }
};
// tribonacci number
class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n <= 2)
            return 1;
        return (
            tribonacci(n - 1) +
            tribonacci(n - 2) +
            tribonacci(n - 3));
    }
};
class Solution
{
public:
    int nCr(int n, int r)
    {
        // code here
        if (r > n)
            return 0;
        r = min(r, n - r);
        if (r == 0 || r == n)
            return 1;
        return (1ll * (n - r + 1) * nCr(n, r - 1)) / r;
    }
};

// Binary exponentiation
double pow(double x, long long int n)
{
    if (n == 0)
        return 1;
    double temp = pow(x, n / 2);
    double res = temp * temp;
    if ((n & 1) == 1)
        res *= x;
    return res;
}
// 779. K-th Symbol in Grammar
class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (k == 1)
            return 0;
        int len = 1 << (n - 2);
        if (k > len)
            return 1 ^ kthGrammar(n - 1, k - len);
        return kthGrammar(n - 1, k);
    }
};