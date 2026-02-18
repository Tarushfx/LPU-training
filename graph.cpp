#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
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