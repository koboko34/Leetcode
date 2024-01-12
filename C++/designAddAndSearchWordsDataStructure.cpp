#include <string>

struct Node
{
    Node* next[26] {};
    bool end = false;
};


class WordDictionary {
public:
    Node* root;
    
    WordDictionary()
    {
        root = new Node();    
    }
    
    void addWord(std::string word)
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

        return searchLetter(root, word, 0);
    }

    bool searchDot(Node* cur, const std::string& word, int index)
    {
        if (index == word.length())
        {
            return cur->end;
        }

        if (word[index] != '.')
        {
            return searchLetter(cur, word, index);
        }

        for (Node* node : cur->next)
        {
            if (!node)
            {
                continue;
            }

            if (searchDot(node, word, index + 1))
            {
                return true;
            }
        }
        return false;
    }

    bool searchLetter(Node* cur, const std::string& word, int index)
    {
        if (index == word.length())
        {
            return cur->end;
        }

        if (word[index] == '.')
        {
            return searchDot(cur, word, index);
        }

        if (cur->next[word[index] - 'a'] == nullptr)
        {
            return false;
        }

        return searchLetter(cur->next[word[index] - 'a'], word, index + 1);
    }
};