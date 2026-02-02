#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// koko eating bananas
class Solution
{
public:
    bool helper(long long int k, vector<int> piles, long long int h)
    {
        long long int sm = 0;
        for (long long int x : piles)
        {
            sm += (x + k - 1) / k;
        }
        return sm <= h;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        long long int lo = 1, hi = *max_element(piles.begin(), piles.end()) + 1;
        while (lo < hi)
        {
            long long int mid = lo + (hi - lo) / 2;
            if (helper(mid, piles, h))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};

// rotated sorted array
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int lo = 0, hi = n;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[0])
                hi = mid;
            else
                lo = mid + 1;
        }
        int pivot = lo;
        if (target >= nums[0])
            lo = 0, hi = pivot;
        else
            lo = pivot, hi = n;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= target)
                hi = mid;
            else
                lo = mid + 1;
        }
        if (lo >= n || nums[lo] != target)
            return -1;
        return lo;
    }
};

// valid perfect square
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 0)
            return 0;
        long long int lo = 1, hi = num;
        hi++;
        while (lo < hi)
        {
            long long int mid = lo + (hi - lo) / 2;
            if (mid >= num / mid)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo * lo == num;
    }
};
// First Bad Version
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        long long int lo = 1, hi = n;
        hi++;
        while (lo < hi)
        {
            long long int mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};