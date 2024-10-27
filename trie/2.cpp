#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    char val;
    unordered_map<char, TrieNode *> next;
    int count;
    bool last;

    TrieNode(char val = -1, bool last = 0)
    {
        this->val = val;
        this->last = last;
        this->count = 0;
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
            curr->count++;

            if (last)
                curr->last = 1;
            i++;
        }

        while (!last)
        {
            last = i == n - 1;
            curr->next[s[i]] = new TrieNode(s[i], last);
            curr = curr->next[s[i]];
            curr->count++;
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
            res += curr->count;
            i++;
        }
        return res;
    }
};
vector<int> sumPrefixScores(vector<string> &v)
{
    Trie t = Trie();
    vector<int> res(v.size());
    for (string &s : v)
        t.add(s);
    for (int i = 0; i < v.size(); i++)
        res[i] = t.get(v[i]);
    return res;
}

int main()
{
    vector<string> v = {"abc", "ab", "bc", "b"};
    vector<int> res = sumPrefixScores(v);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}