#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char c;
    map<char, TrieNode *> children;
    bool isEnd;
    int count;
    TrieNode(char c)
    {
        this->c = c;
        this->count = 0;
        this->isEnd = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        this->root = new TrieNode(' ');
    }

    void add(string word)
    {
        TrieNode *curr = this->root;
        for (char w : word)
        {
            if (curr->children[w] == NULL)
                curr->children[w] = new TrieNode(w);
            curr = curr->children[w];
            curr->count += 1;
        }
        curr->isEnd = true;
    }
    bool find(string word)
    {
        TrieNode *curr = this->root;
        for (char w : word)
        {
            if (!curr->children[w])
                return false;
            curr = curr->children[w];
        }
        return curr->isEnd;
    }
    int startWithCount(string word)
    {
        TrieNode *curr = this->root;
        for (char w : word)
        {
            if (!curr->children[w])
                return 0;
            curr = curr->children[w];
        }
        return curr->count;
    }
    void display()
    {
        cout << "Trie Structure:" << endl;
        printHelper(root, "", true);
    }
    void printHelper(TrieNode *node, string indent, bool isLast)
    {
        if (!node)
            return;

        // Print the branch line and the character
        cout << indent;
        if (isLast)
        {
            cout << "└── ";
            indent += "    ";
        }
        else
        {
            cout << "├── ";
            indent += "│   ";
        }

        // Highlight word endings with a '*' or similar symbol
        cout << node->c << (node->isEnd ? " (end)" : "") << "(" << node->count << ")" << endl;
        // cout << node->count;

        // Iterate through children
        auto it = node->children.begin();
        while (it != node->children.end())
        {
            char charKey = it->first;
            TrieNode *childNode = it->second;
            it++;
            bool lastChild = (it == node->children.end());
            printHelper(childNode, indent, lastChild);
        }
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Trie *trie = new Trie();
    trie->add("apple");
    trie->add("applause");
    trie->add("apron");
    trie->add("food");
    trie->add("fool");
    trie->add("foolish");
    trie->display();
    cout << "app " << trie->startWithCount("app") << endl;
    cout << "ap " << trie->startWithCount("ap") << endl;
    cout << "land exists: " << trie->find("land") << endl;
    cout << "apron exists: " << trie->find("apron") << endl;
}