class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n > 26) {
            n -= 1;
            res = (char)('A' + n % 26) + res;
            n /= 26;
        }
        n -= 1;
        res = (char)('A' + n) + res;
        return res;       
    }
};