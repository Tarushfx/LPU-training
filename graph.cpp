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
        int n = adj.size();
        vector<bool> visited(n, false);
        helper(0, ans, visited, adj);
        return ans;
    }
    void helper(
        int node, vector<int> &ans, vector<bool> &visited,
        vector<vector<int>> &adj)
    {
        if (visited[node])
            return;
        // process
        visited[node] = true;
        ans.push_back(node);
        for (int nei : adj[node])
        {
            helper(nei, ans, visited, adj);
        }
    }
};
// bipartite graph
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        map<int, char> color_map;
        for (int start = 0; start < n; start++)
        {
            if (color_map.find(start) != color_map.end())
                continue;
            queue<pair<int, char>> q;
            q.push({start, 'R'});
            while (!q.empty())
            {
                auto [node, color] = q.front();
                q.pop();
                if (color_map.find(node) != color_map.end())
                {
                    if (color_map[node] != color)
                        return false;
                    continue; // already visited
                }
                color_map[node] = color;
                for (int nei : graph[node])
                {
                    char new_color = color == 'R' ? 'B' : 'R';
                    q.push({nei, new_color});
                }
            }
        }
        return true; // no issues with coloring
    }
};

// count islands
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
// path exists
class Solution
{
public:
    bool dfs(vector<vector<int>> &graph, set<int> &visited, int node, int destination)
    {
        if (node == destination)
            return true;
        if (visited.find(node) != visited.end())
            return false;
        visited.insert(node);
        for (int nei : graph[node])
        {
            if (dfs(graph, visited, nei, destination))
                return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> graph(n, vector<int>());
        for (auto edge : edges)
        {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        set<int> visited;
        return dfs(graph, visited, source, destination);
    }
};

// 01 matrix: multi source BFS
// Time complexity O( mnlog(mn) )
#define pii pair<int, int>
#define tii tuple<int, int, int>
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int N = mat.size(), M = mat[0].size();
        queue<tii> q;
        vector<vector<int>> ans(N, vector<int>(M, 0));
        set<pii> visited;
        vector<int> directions({-1, 0, 1, 0, -1});
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < M; c++)
            {
                if (mat[r][c] == 0)
                {
                    q.push(make_tuple(r, c, 0));
                    visited.insert(make_pair(r, c)); // take all sources
                }
            }
        }
        while (!q.empty())
        {
            // multi source BFS
            auto [r, c, dist] = q.front();
            q.pop();
            // process
            ans[r][c] = dist; // minimum distance from a 0
            for (int d = 0; d < 4; d++)
            {
                // trick to iterate all neighbours
                int new_r = r + directions[d];
                int new_c = c + directions[d + 1];
                if (new_r >= N || new_r < 0 || new_c >= M || new_c < 0)
                    continue; // boundary check
                if (visited.find(make_pair(new_r, new_c)) == visited.end())
                {
                    q.push({new_r, new_c, dist + 1});
                    visited.insert(make_pair(new_r, new_c));
                }
            }
        }
        return ans;
    }
};
// rotting oranges
#define tii tuple<int, int, int>
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<tii> q;
        int N = grid.size(), M = grid[0].size();
        vector<vector<bool>> visited(N, vector(M, false));
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < M; c++)
            {
                if (grid[r][c] == 2)
                {
                    q.push(make_tuple(r, c, 0));
                }
            }
        }
        // int timer = 0;
        int ans = 0;
        vector<int> D({-1, 0, 1, 0, -1});
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto [r, c, time] = q.front();
                q.pop();
                if (visited[r][c])
                    continue;
                visited[r][c] = true;
                grid[r][c] = 2;
                ans = max(ans, time);
                for (int d = 0; d < 4; d++)
                {
                    int new_r = r + D[d];
                    int new_c = c + D[d + 1];
                    if (new_r >= N || new_r < 0 || new_c < 0 || new_c >= M)
                        continue;
                    if (grid[new_r][new_c] == 1)
                    {
                        q.push(make_tuple(new_r, new_c, time + 1));
                    }
                }
            }
        }
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < M; c++)
            {
                if (grid[r][c] == 1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};

// Network delay time

#define pii pair<int, int>
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> distance(n, INT_MAX);
        k--;
        distance[k] = 0;
        vector<vector<pii>> graph(n, vector<pii>());
        for (auto time : times)
        {
            int u = time[0], v = time[1], w = time[2];
            graph[u - 1].push_back({v - 1, w});
        }
        pq.push({0, k}); // source k
        vector<bool> visited(n, false);
        while (!pq.empty())
        {
            auto [dist, node] = pq.top();
            pq.pop();
            if (visited[node])
                continue;
            for (auto [nei, weight] : graph[node])
            {
                if (dist + weight < distance[nei])
                {
                    // found a better distance
                    distance[nei] = dist + weight;
                    pq.push({distance[nei], nei});
                }
            }
        }
        for (auto x : distance)
            if (x == INT_MAX)
                return -1;
        return *max_element(distance.begin(), distance.end());
    }
};

// max probabilty path
#define pdi pair<double, int>
#define pid pair<int, double>
class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &P, int start_node, int end_node)
    {
        int E = edges.size();
        for (int i = 0; i < E; i++)
        {
            P[i] = -log2(P[i]);
            cout << P[i] << " ";
        }
        vector<vector<pid>> graph(n, vector<pid>());
        for (int i = 0; i < E; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            double w = P[i];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        priority_queue<pdi, vector<pdi>, greater<pdi>> heap;
        heap.push({0.0, start_node});
        vector<double> distance(n, 1e18);
        distance[start_node] = 0.0;
        set<int> visited;
        while (!heap.empty())
        {
            auto [d, node] = heap.top();
            heap.pop();
            if (visited.find(node) != visited.end())
                continue;
            visited.insert(node);
            for (auto [nei, w] : graph[node])
            {
                if (w + d < distance[nei])
                {
                    // realise
                    distance[nei] = w + d;
                    heap.push({distance[nei], nei});
                }
            }
        }
        if (distance[end_node] == 1e18)
            return 0.0;
        return pow(2, -distance[end_node]);
    }
};

// Path with min effort
#define pii pair<int, int>
#define tii tuple<int, int, int>
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &H)
    {
        int N = H.size();
        int M = H[0].size();
        vector<int> D({-1, 0, 1, 0, -1});
        priority_queue<tii, vector<tii>, greater<tii>> heap;
        heap.push({0, 0, 0});
        vector<vector<int>> distance(N, vector<int>(M, INT_MAX));
        distance[0][0] = 0;
        set<pii> visited;
        while (!heap.empty())
        {
            auto [dist, r, c] = heap.top();
            heap.pop();
            pii node = make_pair(r, c);
            if (visited.find(node) != visited.end())
                continue;
            visited.insert(node);
            for (int d = 0; d < 4; d++)
            {
                int new_r = r + D[d], new_c = c + D[d + 1];
                if (new_r < 0 || new_r >= N || new_c < 0 || new_c >= M)
                    continue;
                int diff = abs(H[new_r][new_c] - H[r][c]);
                if (max(diff, dist) <= distance[new_r][new_c])
                {
                    distance[new_r][new_c] = max(diff, dist);
                    heap.push(make_tuple(distance[new_r][new_c], new_r, new_c));
                }
            }
        }
        return distance[N - 1][M - 1];
    }
};