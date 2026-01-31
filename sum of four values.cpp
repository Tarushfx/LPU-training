#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<tuple<int, int, int>> vals;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            vals.push_back(make_tuple(v[i] + v[j], i + 1, j + 1));
        }
    }
    sort(vals.begin(), vals.end());
    // for (auto x : vals)
    //     cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;
    // for (auto [a, b, c] : vals)
    // {
    //     cout << a << " " << b << " " << c << endl;
    // }

    int l = 0, r = vals.size() - 1;
    while (l < r)
    {
        auto [lv, li, lj] = vals[l];
        auto [rv, ri, rj] = vals[r];
        int curr = lv + rv;
        if (curr == target)
        {
            set<int> s({li, lj, ri, rj});
            if (s.size() == 4)
            {
                cout << li << " " << lj << " " << ri << " " << rj << endl;
                return 0;
            }
            if (get<0>(vals[l + 1]) == lv)
                l++;
            else if (get<0>(vals[r - 1]) == rv)
                r--;
            else
                l++;
        }
        else if (curr > target)
        {
            r--;
        }
        else
            l++;
    }
    cout << "IMPOSSIBLE";
    return 0;
}