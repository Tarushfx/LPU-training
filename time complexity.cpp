

#include <bits/stdc++.h>
using namespace std;

int *merge_array(int *arr1, int *arr2, int n1, int n2)
{
    int i = 0, j = 0;
    int ptr = 0;
    int *res = new int[n1 + n2];
    while (i < n1 && j < n2)
    {
        if (*(arr1 + i) < *(arr2 + j))
        {
            res[ptr] = *(arr1 + i);
            i++;
        }
        else
        {
            res[ptr] = *(arr2 + j);
            j++;
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N = 1000;
    // log N
    // for (int i = N; i > 0; i >>= 1)
    // {
    //     cout << i << endl;
    // }
    // for (int i = N; i > 0; i >>= 1)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         cout << i << " " << j << endl;
    //     }
    // }
    // n+n/2+n/4 ....
    // n(1+1/2+1/4+....)
    // 2n
    // O(n)

    int arr[] = {4, 1, 5, 2, 6, 7, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    auto res = merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << *(res + i) << " ";
}

void example1(int n)
{
    string result = "";
    for (int i = 0; i < n; i++)
    {
        result = result + "a"; // O(n)
        result += "a";         // O(1)
    }
    // O(n2) if first operation O(n) if second
}
// /logn
void example2(int n)
{
    while (n > 0)
    {
        // Some O(1) work
        n = n / 2;
    }
}

void example2extended(int n)
{
    while (n > 0)
    {
        // O(n) work
        n >>= 1;
    }
    // O(nlogn)
}
void example3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Some O(1) work
        }
    }
    // O(n2)
}

void example4(int n)
{
    vector<int> arr(n);
    int target = 10;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n && arr[i] + arr[j] < target)
        {
            j++;
        }
    }
}
void example5(int n)
{
    if (n <= 1)
        return;
    example5(n / 2);
    example5(n / 2);
    // O(n)
}
void example6(int n)
{
    if (n <= 1)
        return;
    example6(n - 1);
    example6(n - 1);
    // O(2^n)
}