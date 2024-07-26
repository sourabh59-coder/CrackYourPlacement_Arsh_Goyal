#include <string>
#include <algorithm>

class Solution {
public:
    string addBinary(string a,string b) {
        string ans = "";
        int n = a.size() - 1;
        int m = b.size() - 1;
        int carry = 0;

        while (n >= 0 || m >= 0) {
            int valA = (n >= 0) ? a[n] - '0' : 0;
            int valB = (m >= 0) ? b[m] - '0' : 0;
            int sum = valA + valB + carry;
            carry = sum / 2;
            ans += (sum % 2) + '0';
            n--;
            m--;
        }

        if (carry != 0) {
            ans += '1';
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
