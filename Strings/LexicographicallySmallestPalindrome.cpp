class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i <= s.size()/2){
            s[i] = min(s[i], s[j]);
            s[j] = s[i];
            i++; j--;
        }
        return s;
    }
};