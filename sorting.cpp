#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
void heapify(vi &arr, int p, int heapSize)
{
    int l = 2 * p + 1;
    int r = 2 * p + 2;
    if (l > heapSize || r > heapSize)
        return;
    int largest = p;
    if (arr[l] > arr[largest])
        largest = l;
    if (arr[r] > arr[largest])
        largest = r;
    if (p != largest)
    {
        swap(arr[p], arr[largest]);
        heapify(arr, largest, heapSize);
    }
}
void heapSort(vi &arr)
{
    // make heap
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
    // remove largest element
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i - 1);
    }
}
void heapifypairs(vpi &arr, int p, int heapSize)
{
    int l = 2 * p + 1;
    int r = 2 * p + 2;
    if (l > heapSize || r > heapSize)
        return;
    int largest = p;
    if (arr[l].first > arr[largest].first)
        largest = l;
    if (arr[r].first > arr[largest].first)
        largest = r;
    if (p != largest)
    {
        swap(arr[p], arr[largest]);
        heapifypairs(arr, largest, heapSize);
    }
}
void heapSortPair(vpi &arr)
{
    // make heap
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        heapifypairs(arr, i, n);
    }
    // remove largest element
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapifypairs(arr, 0, i - 1);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vi v({2, 3, 1, 1, 5, 5});
    vpi arr;
    for (int i = 0; i < v.size(); i++)
        arr.push_back(make_pair(v[i], i));
    heapSort(v);
    for (auto x : v)
        cout << x << " ";

    cout << endl;
    heapSortPair(arr);
    for (auto [v, i] : arr)
    {
        cout << v << "-" << i << " ";
    }
    cout << endl;
}

int *merge_array(int *arr1, int *arr2, int n1, int n2)
{
    int i = 0, j = 0;
    int ptr = 0;
    int *res = new int[n1 + n2];
    while (i < n1 && j < n2)
    {
        if (*(arr1 + i) <= *(arr2 + j))
        {
            res[ptr] = *(arr1 + i);
            i++;
        }
        else
        {
            res[ptr] = *(arr2 + j);
            j++;
            // inversion count
            // count += (n1 - i);
        }
        ptr++;
    }
    while (i < n1)
    {
        res[ptr] = *(arr1 + i);
        i++;
        ptr++;
    }
    while (j < n2)
    {
        res[ptr] = *(arr2 + j);
        j++;
        ptr++;
    }

    return res;
}
int *merge_sort(int arr[], int l, int r)
{
    if (l == r)
        return arr + l;
    int mid = l + (r - l) / 2;
    auto left = merge_sort(arr, l, mid);
    auto right = merge_sort(arr, mid + 1, r);
    auto merged = merge_array(left, right, mid - l + 1, r - mid);
    return merged;
}

// sort 01s
// User function template for C++

class Solution
{
public:
    void segregate0and1(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int ptr = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                continue;
            while (arr[i] != 0 && i < ptr)
            {
                swap(arr[i], arr[ptr]);
                ptr--;
            }
        }
    }
};
// sort 012s
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        for (int i = 0; i < n; i++)
        {
            while (nums[i] != 1 && i <= hi && i >= lo)
            {
                if (nums[i] == 2)
                {
                    swap(nums[i], nums[hi]);
                    hi--;
                }
                else if (nums[i] == 0)
                {
                    swap(nums[i], nums[lo]);
                    lo++;
                }
            }
        }
    }
};