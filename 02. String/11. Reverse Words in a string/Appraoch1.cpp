class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        string temp = "";
        string str = "";

        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
            {
                str += s[i];
            }
            else
            {
                if(str!="")
                {
                    if(temp == "")
                    {
                        temp += str + " ";
                        temp += ans;
                        ans = "";
                    }
                    else
                    {
                        ans += str + " ";
                        ans += temp;
                        temp = "";
                    }
                    str = "";
                }
            }
        }

        if(str!="")
        {
            if(temp == "")
            {
                temp += str + " ";
                temp += ans;
                ans = "";
            }
            else
            {
                ans += str + " ";
                ans += temp;
                temp = "";
            }
            str = "";
        }
        if(!temp.empty())   temp.pop_back();
        if(!ans.empty())    ans.pop_back();

        return (ans.size() > temp.size()) ? ans : temp;
    }
};
