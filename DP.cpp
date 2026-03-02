#include <bits/stdc++.h>
using namespace std;
// top down / memoisation
class Solution
{
public:
    map<int, int> memo;
    int fib(int n)
    {
        if (n <= 1)
            return n;                   // base case
        if (memo.find(n) != memo.end()) // memoised
            return memo[n];             // always use find with map
        // memo[n]=fib(n-1)+fib(n-2);
        // return memo[n];
        return memo[n] = fib(n - 1) + fib(n - 2); // recursive step
    }
};
// bottom up / iterative
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        vector<int> dp(n + 1, 0);
        // base case
        dp[0] = 0;
        dp[1] = 1;
        // for (int i = n; i >= 2; i--) // wrong loop
        for (int i = 2; i <= n; i++)
        {
            // this works under the assumption that
            // dp[i-1] and dp[i-2] contain the correct values
            // reverse loop will give garbage answer
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
// House robber
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = nums[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

// min cost climbing stairs
class Solution
{
public:
    int rec(int n, vector<int> &cost, vector<int> &dp)
    {
        if (n <= 1)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        dp[n] = min(
            rec(n - 1, cost, dp) + cost[n - 1],
            rec(n - 2, cost, dp) + cost[n - 2]);
        return dp[n];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return rec(n, cost, dp);
    }
};
// Coin change
class Solution
{
public:
    vector<int> memo;
    int helper(int T, vector<int> &coins)
    {
        if (T < 0)
            return INT_MAX;
        if (T == 0)
            return 0;
        if (memo[T] != -1)
            return memo[T];
        int ans = INT_MAX;
        for (int c : coins)
        {
            int curr = helper(T - c, coins);
            if (curr == INT_MAX)
                continue;
            ans = min(ans, curr + 1);
        }
        memo[T] = ans;
        return ans;
    }
    int coinChange(vector<int> &coins, int T)
    {
        memo.resize(T + 1, -1);
        int ans = helper(T, coins);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};
class Solution
{
public:
    vector<int> memo;
    int coinChange(vector<int> &coins, int T)
    {
        memo.resize(T + 1, INT_MAX);
        memo[0] = 0;
        for (int i = 0; i <= T; i++)
        {
            for (int c : coins)
            {
                if (i - c < 0)
                    continue;
                if (memo[i - c] == INT_MAX)
                    continue;
                memo[i] = min(memo[i], memo[i - c] + 1);
            }
        }
        if (memo[T] == INT_MAX)
            return -1;
        return memo[T];
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}