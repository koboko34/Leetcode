#include <string>

struct Node
{    
    Node* next[26] {};
    bool end = false;
};

class Trie {
public:
    Node* root;

    Trie()
    {
        root = new Node();
        root->end = true;
    }
    
    void insert(std::string word)
    {
        if (word.empty())
        {
            return;
        }
        
        Node* cur = root;
        for (char c : word)
        {
            if (cur->next[c - 'a'] == nullptr)
            {
                cur->next[c - 'a'] = new Node();
            }
            cur = cur->next[c - 'a'];
        }
        cur->end = true;
    }
    
    bool search(std::string word)
    {
        if (word.empty())
        {
            return true;
        }
        
        Node* cur = root;
        for (char c : word)
        {
            if (cur->next[c - 'a'] == nullptr)
            {
                return false;
            }
            cur = cur->next[c - 'a'];
        }

        return cur->end;
    }
    
    bool startsWith(std::string prefix)
    {
        if (prefix.empty())
        {
            for (size_t i = 0; i <= 'z' - 'a'; i++)
            {
                if (root->next[i] != nullptr)
                {
                    return true;
                }
            }
            return false;
        }
        
        Node* cur = root;
        for (char c : prefix)
        {
            if (cur->next[c - 'a'] == nullptr)
            {
                return false;
            }
            cur = cur->next[c - 'a'];
        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    trie.search("apple");   // return True
    trie.search("app");     // return False
    trie.startsWith("app"); // return True
    trie.insert("app");
    trie.search("app");     // return True
}