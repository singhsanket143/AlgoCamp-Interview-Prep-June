class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = int(s.length()), res = 0;
        unordered_map<char, int> mp;

        for (int j = 0, i = 0; j < n; j++){
            if(mp[s[j]] > 0) {
                i = max(mp[s[j]], i);
            }
            res = max(res, j - i + 1);
            mp[s[j]] = j + 1;
        }
        return res;
    }
};
