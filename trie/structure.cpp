#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    char val;
    vector<TrieNode *> next;
    bool last;

    TrieNode(char val = -1, bool last = 0)
    {
        this->val = val;
        this->last = last;
        this->next = vector<TrieNode *>(26);
        for (int i = 0; i < 26; i++)
            this->next[i] = nullptr;
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
        bool x = curr->next[s[i] - 'a'];
        while (!last && curr->next[s[i] - 'a']!=nullptr)
        {
            last = i == n - 1;
            curr = curr->next[s[i] - 'a'];

            if (last)
                curr->last = 1;

            i++;
        }

        while (!last)
        {
            last = i == n - 1;
            curr->next[s[i] - 'a'] = new TrieNode(s[i], last);
            curr = curr->next[s[i] - 'a'];
            i++;
        }
    }

    int get(const string &s)
    {
        int res = -1;
        int i = 0;
        int n = s.size();
        TrieNode *curr = head;

        while (i < n && curr->next[s[i] - 'a'])
        {
            curr = curr->next[s[i] - 'a'];
            i++;
        }

        // Check if we reached the end of the string
        if (i == n && curr->last)
            return 1; // String found
        return -1;    // String not found
    }
};
int main()
{
    Trie t = Trie();
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i : v)
        t.add(to_string(i));
}