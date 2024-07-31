class Node{
public:
    Node* list[26];
    int CE;
    int CP;

    Node()
    {
        for(int i=0;i<26;i++)   list[i] = NULL;
        CE = 0;
        CP = 0;
    }

    bool containKey(char ch)
    {
        return (list[ch-'a']!=NULL);
    }

    Node* get(char ch)
    {
        return list[ch-'a'];
    }

    void put(char ch,Node* new_node)
    {
        list[ch-'a'] = new_node;
    }

    void setEnd()
    {
        CE++;
    }

    void setPrefix()
    {
        CP++;
    }

    int isPrefix()
    {
        return CP;
    }

    int isEnd()
    {
        return CE;
    }
};

class Trie{
public:
    Node* root;

    Trie()
    {
        root = new Node();
    }

    void Insert(string s)
    {
        Node* temp = root;

        for(auto it:  s)
        {
            if(!temp->containKey(it))
            {
                Node* new_node = new Node();
                temp->put(it,new_node);
            }
            temp = temp->get(it);
            temp->setPrefix();
        }

        temp->setEnd();
    }


    bool search(string word)
    {
        Node* temp = root;

        for(auto it: word)
        {
            if(!temp->containKey(it))
            {
                return false;
            }

            temp = temp->get(it);
        }

        return (temp->isEnd());
    }

    bool searchPrefix(string word)
    {
        Node* temp = root;

        for(auto it: word)
        {
            if(!temp->containKey(it))
            {
                return false;
            }
            temp = temp->get(it);
        }

        return true;
    }

    string helper(string s,int n)
    {
        Node* temp = root;
        string ans = "";
        for(auto it: s)
        {
            temp = temp->get(it);
            if(temp->isPrefix()==n)   ans += it;
            else    break;
        }
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie Obj;
        for(auto it: strs)  Obj.Insert(it);

        return Obj.helper(strs[0],(int)strs.size());
    }
};
