#include <unordered_map>

struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:    
    LRUCache(int capacity) {
        this->capacity = capacity;
        
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) 
    {
        if(map.find(key) != map.end()){
            Node* resNode = map[key];
            int ans = resNode -> val;

            map.erase(key);
            removeNode(resNode);
            insertNode(resNode);

            map[key] = head -> next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value)
    {
        if(map.find(key) != map.end()){
            Node* curr = map[key];
            map.erase(key);
            removeNode(curr);
        }

        if(map.size() == capacity){
            map.erase(tail -> prev -> key);
            removeNode(tail -> prev);
        }

        insertNode(new Node(key, value));
        map[key] = head -> next;
    }

private:
    std::unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
    unsigned int length = 0;
    unsigned int capacity;

    void insertNode(Node* newNode)
    {
        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }

    void removeNode(Node* delNode)
    {
        Node* prev = delNode->prev;
        Node* next = delNode->next;

        prev->next = next;
        next->prev = prev;
    }
};

int main()
{
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    lRUCache->get(1);    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache->get(2);    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache->get(1);    // return -1 (not found)
    lRUCache->get(3);    // return 3
    lRUCache->get(4);
}