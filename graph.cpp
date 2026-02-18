#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// BFS
class Solution
{
public:
    vector<int> bfs(vector<vector<int>> &adj)
    {
        // code here
        int source = 0;
        queue<int> q;
        vector<int> ans;
        q.push(source);
        set<int> visited;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (visited.find(node) != visited.end())
                continue;
            visited.insert(node);
            ans.push_back(node);
            for (int nei : adj[node])
            {
                q.push(nei);
            }
        }
        return ans;
    }
};
// DFS
class Solution
{
public:
    vector<int> dfs(vector<vector<int>> &adj)
    {
        // Code here
        vector<int> ans;
        set<int> visited;
        helper(0, ans, visited, adj);
        return ans;
    }
    void helper(
        int node, vector<int> &ans, set<int> &visited,
        vector<vector<int>> &adj)
    {
        if (visited.find(node) != visited.end())
            return;
        // process
        visited.insert(node);
        ans.push_back(node);
        for (int nei : adj[node])
        {
            helper(nei, ans, visited, adj);
        }
    }
};
class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int r, int c, vector<vector<bool>> &visited)
    {
        int n = grid.size(), m = grid[0].size();
        if (r >= n || r < 0 || c >= m || c < 0)
            return;
        if (visited[r][c])
            return;
        if (grid[r][c] == '0')
            return;
        visited[r][c] = true;
        dfs(grid, r + 1, c, visited);
        dfs(grid, r, c + 1, visited);
        dfs(grid, r, c - 1, visited);
        dfs(grid, r - 1, c, visited);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int cnt = 0;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if (grid[r][c] == '0' || visited[r][c])
                    continue;
                dfs(grid, r, c, visited);
                cnt++;
            }
        }
        return cnt;
    }
};
// max area
class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int r, int c, vector<vector<bool>> &visited)
    {
        int n = grid.size(), m = grid[0].size();
        if (r >= n || r < 0 || c >= m || c < 0)
            return 0;
        if (visited[r][c])
            return 0;
        if (grid[r][c] == 0)
            return 0;
        visited[r][c] = true;
        int area = 1;
        area += dfs(grid, r + 1, c, visited);
        area += dfs(grid, r, c + 1, visited);
        area += dfs(grid, r, c - 1, visited);
        area += dfs(grid, r - 1, c, visited);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int cnt = 0;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if (grid[r][c] == 0 || visited[r][c])
                    continue;
                int area = dfs(grid, r, c, visited);
                cnt = max(cnt, area);
            }
        }
        return cnt;
    }
};
