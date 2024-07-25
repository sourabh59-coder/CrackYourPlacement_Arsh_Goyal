class Solution {
public:
    bool fun(string &s,int i,int j,bool flag)
    {
        if(i>j) return true;

        if(s[i]==s[j])
        {
            return fun(s,i+1,j-1,flag);
        }
        else
        {
            if(flag)
            {
                return fun(s,i+1,j,false) || fun(s,i,j-1,false);
            }
            else    return false;
        }

        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n-1;
        bool flag = true;

        return fun(s,i,j,flag); 
    }
};
