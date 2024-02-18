#include <vector>
#include <unordered_map>
#include <queue>

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        if (node == nullptr)
        {
            return nullptr;
        }
        
        // old, new
        std::unordered_map<Node*, Node*> map;
        std::queue<Node*> queue;
        queue.push(node);

        while (!queue.empty())
        {
            Node* ref = queue.front();
            queue.pop();

            Node* newNode;
            auto it = map.find(ref);
            if (it != map.end())
            {
                newNode = it->second;
            }
            else
            {
                newNode = new Node(ref->val);
                map[ref] = newNode;
            }

            for (Node* oldNeighbor : ref->neighbors)
            {
                auto iter = map.find(oldNeighbor);
                if (iter != map.end())
                {
                    if (std::find(newNode->neighbors.begin(), newNode->neighbors.end(), iter->second) == newNode->neighbors.end())
                    {
                        newNode->neighbors.push_back(iter->second);
                    }
                    if (std::find(iter->second->neighbors.begin(), iter->second->neighbors.end(), newNode) == iter->second->neighbors.end())
                    {
                        iter->second->neighbors.push_back(newNode);
                    }                        
                    continue;
                }
                
                Node* newNeighbor = new Node(oldNeighbor->val);
                newNeighbor->neighbors.push_back(newNode);
                newNode->neighbors.push_back(newNeighbor);
                map[oldNeighbor] = newNeighbor;
                queue.push(oldNeighbor);
            }
        }
        return map[node];
    }
};

int main()
{
    Solution s;
    Node first(1);
    Node second(2);
    Node third(3);
    Node fourth(4);

    first.neighbors.push_back(&second);
    first.neighbors.push_back(&fourth);
    second.neighbors.push_back(&first);
    second.neighbors.push_back(&third);
    third.neighbors.push_back(&second);
    third.neighbors.push_back(&fourth);
    fourth.neighbors.push_back(&first);
    fourth.neighbors.push_back(&third);

    s.cloneGraph(&first);
}