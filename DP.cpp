#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<int, int> memo;
    int fib(int n)
    {
        if (n <= 1)
            return n;
        if (memo.find(n) != memo.end())
            return memo[n]; // always use find with map
        // memo[n]=fib(n-1)+fib(n-2);
        // return memo[n];
        return memo[n] = fib(n - 1) + fib(n - 2);
    }
};

class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        // for (int i = n; i >= 2; i--) //wrong loop
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// climbing stairs
class Solution
{
public:
    map<int, int> memo;
    int climbStairs(int n)
    {
        if (n <= 1)
            return 1;
        if (memo.find(n) != memo.end())
            return memo[n]; // always find
        return memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};
// climbing stairs
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return 1;
        vector<int> memo(n + 1, 0);
        memo[0] = 1;
        memo[1] = 1;
        for (int i = 2; i <= n; i++)
            memo[i] = memo[i - 1] + memo[i - 2];
        return memo[n];
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}