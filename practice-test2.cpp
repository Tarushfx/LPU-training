// weekly contest 431
#include <bits/stdc++.h>
using namespace std;
// 1
class Solution
{
public:
    long long int lcm(long long int a, long long int b)
    {
        return a * b / gcd(a, b);
    }
    int maxLength(vector<int> &nums)
    {
        int ans = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            long long int l = nums[i], g = nums[i], p = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                p *= nums[j];
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);
                if (p == g * l)
                {
                    ans = max(ans, j - i + 1);
                }
                if (p != g * l)
                    break;
            }
        }
        return ans;
    }
};
// 2
class Solution
{
public:
    long long calculateScore(string s)
    {
        vector<vector<long long int>> indices(26);
        long long int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'a';
            if (indices[25 - idx].size() > 0)
            {
                ans += i - indices[25 - idx].back();
                indices[25 - idx].pop_back();
                continue;
            }
            indices[idx].push_back(i);
        }
        return ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}