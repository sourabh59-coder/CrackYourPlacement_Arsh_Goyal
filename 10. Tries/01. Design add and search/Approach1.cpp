class Node{
public:
    Node* list[26];
    bool flag;

    Node()
    {
        for(int i=0;i<26;i++)   list[i] = NULL;
        flag = false;
    }

    bool containKey(char ch)
    {
        return (list[ch-'a']!=NULL);
    }

    void put(char ch,Node* new_node)
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


class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* temp = root;
        for(auto it: word)
        {
            if(!temp->containKey(it))
            {
                Node* new_node = new Node();
                temp->put(it,new_node);
            }
            temp = temp->get(it);
        }

        temp->setEnd();
    }

    bool fun(Node* temp, int ind, string &word) {
        if (ind == word.size()) return temp->isEnd();

        if (word[ind] == '.') {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (temp->containKey(ch)) {
                    if (fun(temp->get(ch), ind + 1, word)) {
                        return true; 
                    }
                }
            }
            return false; 
        } else {
            if (temp->containKey(word[ind])) {
                return fun(temp->get(word[ind]), ind + 1, word);
            } else {
                return false;  
            }
        }
    }
    
    bool search(string word) {
        // bool ans = false;
        int ind = 0;
        Node* temp = root;
        return fun(temp,0,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
