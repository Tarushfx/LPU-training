#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// redundant connection
class Solution
{
public:
    vector<int> parent;
    void _union(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb)
            return;
        parent[pa] = pb;
    }
    int find(int a)
    {
        if (parent[a] == a)
            return a;
        int pa = find(parent[a]);
        parent[a] = pa; //  path compression
        return pa;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        for (auto edge : edges)
        {
            int u = edge[0], v = edge[1];
            if (find(u) == find(v))
                return {u, v};
            _union(u, v);
        }
        return {};
    }
};

// path esists
class Solution
{
public:
    vector<int> parent;
    void _union(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb)
            return;
        parent[pa] = pb;
    }
    int find(int a)
    {
        if (parent[a] == a)
            return a;
        int pa = find(parent[a]);
        parent[a] = pa; // path compression
        return pa;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        for (auto edge : edges)
        {
            int u = edge[0], v = edge[1];
            if (find(u) == find(v))
                return {u, v};
            _union(u, v);
        }
        return {};
    }
};