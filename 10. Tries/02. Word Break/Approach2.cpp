//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++



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

    void set(char ch, Node* new_node)
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

class Trie{
public:
    Node* root;
    
    Trie()
    {
        root = new Node();
    }
    
    void insert(const string &word) {
        Node* temp = root;

        for(auto ch : word)
        {
            if(!temp->containKey(ch))
            {
                Node* new_node = new Node();
                temp->set(ch, new_node);
            }
            temp = temp->get(ch);
        }

        temp->setEnd();
    }
    
    bool search(const string &word,int start,int end) {
        Node* temp = root;
        for(int i=start;i<end;i++)
        {
            if(!temp->containKey(word[i]))  return false;
            temp = temp->get(word[i]);
        }

        return temp->isEnd();
    }
    
    bool startsWith(const string &prefix) {
        Node* temp = root;
        for(auto ch : prefix)
        {
            if(!temp->containKey(ch))
            {
                return false;
            }

            temp = temp->get(ch);
        }

        return true;
    }
    
    bool wordBreakerHelp(string s,int start)
    {
        if(start==s.length())   return true;
        
        for(int end=start+1;end<=s.length();end++)
        {
            if(search(s,start,end) && wordBreakerHelp(s,end))
            {
                return true;
            }
        }
        return false;
    }
};


class Solution{
public:
    int wordBreak(const string &s, vector<string> &v) {
        Trie obj;
        for(const auto &word : v)
        {
            obj.insert(word);
        }
        
        return obj.wordBreakerHelp(s,0) ? 1 : 0;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
