#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    char val;
    unordered_map<char, TrieNode *> next;
    bool last;

    TrieNode(char val = -1, bool last = 0)
    {
        this->val = val;
        this->last = last;
    }
};

class Trie
{
public:
    TrieNode *head;

    Trie()
    {
        head = new TrieNode();
    }

    void add(const string &s)
    {
        int i = 0;
        int n = s.size();
        bool last = 0;
        TrieNode *curr = head;

        while (!last && curr->next.count(s[i]))
        {
            last = i == n - 1;
            curr = curr->next[s[i]];

            if (last)
                curr->last = 1;

            i++;
        }

        while (!last)
        {
            last = i == n - 1;
            curr->next[s[i]] = new TrieNode(s[i], last);
            curr = curr->next[s[i]];
            i++;
        }
    }

    int get(const string &s)
    {
        int res = 0;
        int i = 0;
        int n = s.size();
        TrieNode *curr = head;

        while (i < n && curr->next.count(s[i]))
        {
            curr = curr->next[s[i]];
            res++;
            i++;
        }

        // Check if we reached the end of the string
        return res;
    }
};
int longestCommonPrefix(vector<int> &a, vector<int> &b)
{
    Trie t = Trie();

    for (int &i : a)
        t.add(to_string(i));
    int res = INT_MIN;
    for (int &i : b)
        res = max(res, t.get(to_string(i)));
    return res;
}
int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 3};
    cout << longestCommonPrefix(a, b) << endl;
    return 0;
}