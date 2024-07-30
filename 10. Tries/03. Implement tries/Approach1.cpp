class Node{
public:
    Node* list[26];
    bool flag ;

    Node()
    {
        for(int i=0;i<26;i++)   list[i] = NULL;
        flag = false;
    }    

    bool containKey(char ch)
    {
        return (list[ch-'a']!=NULL);
    }

    void set(char ch,Node* new_node)
    {
        list[ch-'a'] = new_node;
    }

    Node* get(char ch)
    {
        return list[ch-'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};


class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;

        for(auto it: word)
        {
            if(!temp->containKey(it))
            {
                Node* new_node = new Node();
                temp->set(it,new_node);
            }
            temp = temp->get(it);
        }

        temp->setEnd();
    }
    
    bool search(string word) {
        Node* temp = root;
        for(auto it:word)
        {
            if(!temp->containKey(it))
            {
                return false;
            }

            temp = temp->get(it);
        }

        return temp->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(auto it:prefix)
        {
            if(!temp->containKey(it))
            {
                return false;
            }

            temp = temp->get(it);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
