class Solution {
public:
    void CreateMapNode(Node* head, unordered_map<Node*, Node*>& mp) {
        Node* temp = head;
        while (temp != NULL) {
            Node* ptr = new Node(temp->val);
            mp[temp] = ptr;
            temp = temp->next;
        }
    }

    Node* createList(Node* head, unordered_map<Node*, Node*>& mp) {
        Node* ptr = head;
        while (ptr != NULL) {
            mp[ptr]->next = mp[ptr->next];
            ptr = ptr->next;
        }
        return mp[head];
    }

    void createRandom(Node* head, unordered_map<Node*, Node*>& mp) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->random) {
                mp[temp]->random = mp[temp->random];
            }
            temp = temp->next;
        }
    }

    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> mp;
        CreateMapNode(head, mp);
        Node* newHead = createList(head, mp);
        createRandom(head, mp);
        return newHead;
    }
};
