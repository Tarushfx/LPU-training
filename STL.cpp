#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
    for (auto temp : v)
    {
        cout << temp << " ";
    }
    cout << endl;
}
void print_set(set<int> s)
{
    for (auto x : s)
        cout << x << " ";
    cout << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> v = {1, 2, 3, 4};
    cout << "First element: " << *v.begin() << endl;
    auto x = v.end();

    v.push_back(5);
    cout << "After push_back(5): ";
    print(v);

    v.pop_back();
    cout << "After pop_back(): ";
    print(v);
    // O(n)
    v.erase(v.begin() + 1);
    print(v);

    vector<vector<int>> vv(3, vector<int>(5, -1));
    for (vector<int> temp : vv)
        cout << temp.size() << " ";
    cout << endl;

    set<int> s;
    s.insert(5);
    s.insert(4);
    s.insert(-1);
    cout << "Print set\n";
    for (auto itr = s.begin(); itr != s.end(); itr++)
    {
        cout << *itr << " Values less than *itr " << distance(s.begin(), itr) << endl;
    }
    print_set(s);
    set<int, greater<int>> desc;
    desc.insert(1);
    desc.insert(4);
    desc.insert(10);
    desc.insert(6);

    map<int, vector<int>> mp;
    mp[1] = {1, 2, 3, 4};
    mp[2] == vector<int>(); // makes and extra value
    for (auto x : mp)
    {
        cout << "key: " << x.first << " " << "value: ";
        for (auto y : x.second)
            cout << y << " ";
        cout << endl;
    }
    mp[1].pop_back(); // removes 4
    cout << (mp.find(3) != mp.end()) << endl;
    vector<int> arr = {1, 2, 234, 12, 23464, 0, -1};
    sort(arr.begin() + 2, arr.end() - 1);
    print(arr);
    // priority_queue<int, vector<int>, greater<int>> minheap;
}
