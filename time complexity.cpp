

#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void example1(int n)
{
    string result = "";
    for (int i = 0; i < n; i++)
    {
        result = result + "a";
    }
}
void example2(int n)
{
    while (n > 0)
    {
        // Some O(1) work
        n = n / 2;
    }
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
}
void example6(int n)
{
    if (n <= 1)
        return;
    example6(n - 1);
    example6(n - 1);
}