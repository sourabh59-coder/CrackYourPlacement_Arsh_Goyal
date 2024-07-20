class Solution {
public:
    int ladderLength(string start, string dest, vector<string>& v) {
        unordered_set<string> st;
        int n = v.size();
        for(int i=0;i<n;i++)    st.insert(v[i]);

        // if(st.count(start)!=0)  st.erase(start);
        st.erase(start);
        if(st.count(dest)==0)   return 0;

        queue<string> qe;
        qe.push(start);

        int cnt = 0;
        while(!qe.empty())
        {
            int si = qe.size();
            cnt++;
            for(int i=0;i<si;i++)
            {
                auto it = qe.front();
                qe.pop();

                if(it==dest)    return cnt;
                // string curr = it;
                for(int j=0;j<it.size();j++)
                {
                    char curr = it[j];
                    for(char ch='a';ch<='z';ch++)
                    {
                        it[j] = ch;
                        if(st.count(it)!=0)
                        {
                            st.erase(it);
                            qe.push(it);
                        }
                    }
                    it[j] = curr;
                }

            }
        }

        return 0;
    }
};
