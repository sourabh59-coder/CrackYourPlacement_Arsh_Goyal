class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        
        
        for(int i=0;i<s.length();i++)
        {
            if(s1.empty())
            {
                if(s[i]!='#')
                {
                    s1.push(s[i]);
                }
            }
            else
            {
                if(s[i]=='#')
                {
                    s1.pop();
                }
                else
                {
                    s1.push(s[i]);
                }
            }
        }
        
        for(int i=0;i<t.length();i++)
        {
            if(s2.empty())
            {
                if(t[i]!='#')
                {
                    s2.push(t[i]);
                }
            }
            else
            {
                if(t[i]=='#')
                {
                    s2.pop();
                }
                else
                {
                    s2.push(t[i]);
                }
            }
        }
        
        string a="";
        string b = "";
        
        while(!s1.empty())
        {
            a += s1.top();
            s1.pop();
        }
        
        while(!s2.empty())
        {
            b += s2.top();
            s2.pop();
        }
        
        if(a==b)
        {
            return true;
        }
        return false;
    }
};
