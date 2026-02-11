#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// leetcode 1004. Max Consecutive Ones III
class Solution
{
public:
    int longestOnes(vector<int> &arr, int k)
    {
        int l = 0;
        int cnt0 = 0;
        int n = arr.size();
        int ans = 0;
        for (int r = 0; r < n; r++)
        {
            if (arr[r] == 0)
                cnt0++;
            while (cnt0 > k && l <= r)
            {
                if (arr[l] == 0)
                    cnt0--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
// Leetcode 3. Longest Substring Without Repeating Characters
class Solution
{
public:
    int lengthOfLongestSubstring(string arr)
    {
        int l = 0;
        int dist = 0;
        map<char, int> mp;
        int n = arr.size();
        int ans = 0;
        for (int r = 0; r < n; r++)
        {
            mp[arr[r]]++;
            if (mp[arr[r]] == 1)
                dist++;
            while (dist != r - l + 1 && l <= r)
            {
                mp[arr[l]]--;
                if (mp[arr[l]] == 0)
                    dist--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

// 1248 Count Number of Nice Subarrays
class Solution
{
public:
    int numberOfSubarrays(vector<int> &arr, int k)
    {
        int l = 0;
        int cntodd = 0;
        int n = arr.size();
        int ans = 0;
        deque<int> q; // first odd number
        for (int r = 0; r < n; r++)
        {
            if (arr[r] % 2 == 1)
            {
                cntodd++;
                q.push_back(r);
            }
            while (cntodd > k && l <= r)
            {
                if (arr[l] % 2 == 1)
                {
                    cntodd--;
                    if (!q.empty() && q.front() == l)
                        q.pop_front();
                }
                l++;
            }
            if (!q.empty() && cntodd == k)
                ans += q.front() - l + 1;
        }
        return ans;
    }
};
// leetcode 1588
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int x = 1; x <= n; x += 2)
            {
                int left = max(0, i - x + 1);
                int right = min(n - 1, i + x - 1);
                int len = right - left + 1;
                int subarray = (len - x + 1);
                ans += subarray * arr[i];
            }
        }
        return ans;
    }
};
// sum of all subarrays
class Solution
{
public:
    int subarraySum(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (i + 1) * (n - i) * arr[i];
        }
        return ans;
    }
};

// leetcode 719 Find K-th Smallest Pair Distance
class Solution
{
public:
    int countpairs(int diff, vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;
        int ans = 0;
        for (int r = 0; r < n; r++)
        {
            while (l < r && nums[r] - diff > nums[l])
                l++;
            ans += r - l;
        }
        return ans;
    }
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int lo = INT_MAX;
        for (int i = 1; i < nums.size(); i++)
            lo = min(lo, nums[i] - nums[i - 1]);
        int hi = nums.back() - nums.front() + 1;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (countpairs(mid, nums) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};