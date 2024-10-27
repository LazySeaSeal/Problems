class TrieNode
{
public:
    char val;
    unordered_map<char,TrieNode *> next;
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