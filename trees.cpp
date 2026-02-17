#include <bits/stdc++.h>
using namespace std;
int sumOfAllNodes(int at, int parent, vector<vector<int>> &tree)
{
    int sm = 1;
    for (auto to : tree[at])
    {
        if (to == parent)
            continue;
        sm += sumOfAllNodes(to, at, tree);
    }
    return sm;
}
int sumOfAllEdgesWeighted(int at, int parent, vector<vector<pair<int, int>>> &tree)
{
    int sm = 0;
    for (auto [to, w] : tree[at])
    {
        if (to == parent)
            continue;
        sm += w + sumOfAllEdgesWeighted(to, at, tree);
    }
    return sm;
}
int sumOfAllNodesWeighted(int at, int parent, vector<vector<int>> &tree, vector<int> weights)
{
    int sm = weights[at];
    for (auto to : tree[at])
    {
        if (to == parent)
            continue;
        sm += sumOfAllNodesWeighted(to, at, tree, weights);
    }
    return sm;
}

int sumOfAllNodeBFS(int root, vector<vector<int>> &tree)
{
    queue<int> q;
    q.push(root);
    set<int> visited;
    visited.insert(root);
    int ans = 0;
    while (!q.empty())
    {
        int at = q.front();
        q.pop();
        ans++;
        for (auto to : tree[at])
        {
            if (visited.find(to) == visited.end())
            {
                q.push(to);
                visited.insert(to);
            }
        }
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>> edges = {
        {1, 2},
        {3, 4},
        {1, 3},
        {3, 5},
        {1, 6},
    };
    auto weights = {0, 1, 2, 3, 4, 5, 6};
    vector<vector<int>> edgeWeights = {
        {1, 2, 1},
        {3, 4, 2},
        {1, 3, 3},
        {3, 5, 5},
        {1, 6, 7},
    };
    int n = 6;
    vector<vector<int>> tree(n + 1, vector<int>());
    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    cout << "total sum = " << sumOfAllNodes(1, -1, tree) << endl;
    vector<vector<pair<int, int>>> weightedTree(n + 1, vector<pair<int, int>>());
    for (auto edge : edgeWeights)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        weightedTree[u].push_back({v, w});
        weightedTree[v].push_back({u, w});
    }
    // cout << "total sum of weighted edges = " << sumOfAllEdgesWeighted(1, -1, weightedTree) << endl;
    cout << "total sum of weighted nodes = " << sumOfAllNodesWeighted(1, -1, tree, weights) << endl;
    cout << "total sum of tree BFS = " << sumOfAllNodeBFS(1, tree);
}
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
// sum of all nodes in binary tree
class Solution
{
public:
    int sumBT(Node *root)
    {
        if (!root)
            return 0;
        return (sumBT(root->left) +
                root->data +
                sumBT(root->right));
    }
};
// inver binary tree dfs
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;
        auto tempr = invertTree(root->left);
        auto templ = invertTree(root->right);
        root->right = tempr;
        root->left = templ;
        return root;
    }
};

// Invert binary tree BFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (!node)
                continue;
            TreeNode *temp = node->right;
            node->right = node->left;
            node->left = temp;
            q.push(node->left);
            q.push(node->right);
        }
        return root;
    }
};

// max depth of a tree
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// diameter of a tree
class Solution
{
public:
    int diameter = INT_MIN;
    int diameterOfBinaryTree(TreeNode *root)
    {
        height(root);
        return diameter;
    }
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
};