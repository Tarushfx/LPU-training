#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    // // 1. print columns

    // int n = 5;
    // for (int r = 0; r < n; r++)
    // {
    //     for (int c = 0; c < n; c++)
    //     {
    //         cout << c << "";
    //     }
    //     cout << endl;
    // }

    // // 2. print hollow rectangle

    // int rows = 5, cols = 10;
    // for (int r = 0; r < rows; r++)
    // {
    //     for (int c = 0; c < cols; c++)
    //     {
    //         // boundry check
    //         if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
    //             cout << "*";
    //         else
    //             cout << " ";
    //     }
    //     cout << endl;
    // }
    // // 3. print right angled triangle

    // n = 10;
    // for (int r = 0; r < n; r++)
    // {
    //     for (int c = 0; c < n; c++)
    //     {
    //         if (c > r)
    //         {
    //             cout << "#";
    //         }
    //         else if (c == 0 || r == n - 1 || r == c)
    //             cout << "*";
    //         else
    //             cout << " ";
    //     }
    //     cout << endl;
    // }

    // 4. print manhattan distance from origin
    // n = 5;
    // for (int r = 0; r < n; r++)
    // {
    //     for (int c = 0; c < n; c++)
    //     {
    //         cout << r + c << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // // 5. print manhattan distance from a random point
    // n = 5;
    // int x = 2, y = 3;
    // for (int r = 0; r < n; r++)
    // {
    //     for (int c = 0; c < n; c++)
    //     {
    //         cout << abs(r - x) + abs(c - y) << " ";
    //     }
    //     cout << endl;
    // }

    // 6. print a circle

    // int r = 20;
    // for (int i = -r; i <= r; i++)
    // {
    //     for (int j = -r; j <= r; j++)
    //     {
    //         if (i * i + j * j <= r * r)
    //             cout << "* ";
    //         else
    //             cout << "  ";
    //     }
    //     cout << endl;
    // }

    //  7. print a spiral (leetcode)
    // 8. print pascals triangle
    // 9. print xor pyramid

    n = 4;
    vector<int> v({2, 3, 5, 4});
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << (v[j] ^ v[j + 1]);
            v[j] = v[j] ^ v[j + 1];
        }
        cout << endl;
    }
}