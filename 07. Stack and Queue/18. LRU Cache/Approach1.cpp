class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node()
    {
        next = NULL;
        prev = NULL;
    }    

    Node(int k,int v)
    {
        key = k;
        val = v;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int,Node* > mp;
    Node* head;
    Node* tail;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* new_node)
    {
        Node* head_next = head->next;
        head->next = new_node;
        new_node->prev = head;
        new_node->next = head_next;
        head_next->prev = new_node;
    }

    void deleteNode(Node* ptr)
    {
        Node* prev_node = ptr->prev;
        Node* next_node = ptr->next;
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            Node* ptr = mp[key];
            int ans = ptr->val;
            mp.erase(key);
            deleteNode(ptr);
            addNode(ptr);
            mp[key] = head->next;
            return ans;
        }
        else    return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)!=0)
        {
            Node* ptr = mp[key];
            deleteNode(ptr);
            mp.erase(key);
        }

        if(mp.size()>=cap)
        {
            Node* ptr = tail->prev;
            mp.erase(ptr->key);
            deleteNode(ptr);
        }
        Node* temp = new Node(key,value);
        addNode(temp);
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
