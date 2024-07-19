class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> check(26,0);
        int l=0;
        int r=0;
        int ans = 0;
        int n = s.length();
        int len = 0;
        int maxf = 0;
        while(r<n)
        {
            check[s[r]-'A']++;
            r++;
            len++;
            for(int i=0;i<26;i++)   maxf = max(maxf,check[i]);
            if(len-maxf <= k)   ans = max(ans,len);
            else
            {
                while(l<=r && len-maxf>k)
                {
                    len--;
                    check[s[l]-'A']--;
                    l++;
                    for(int i=0;i<26;i++)   maxf = max(maxf,check[i]);
                }
            }
        }
        return ans;
    }
};
