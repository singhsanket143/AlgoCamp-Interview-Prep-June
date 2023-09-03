#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        if (strs.empty()) return std::vector<std::vector<std::string>>();
        
        std::unordered_map<std::string, std::vector<std::string>> ans;
        for (const std::string& s : strs) {
            std::string sortedStr = s;
            std::sort(sortedStr.begin(), sortedStr.end());
            
            if (ans.find(sortedStr) == ans.end())
                ans[sortedStr] = std::vector<std::string>();
            
            ans[sortedStr].push_back(s);
        }
        
        std::vector<std::vector<std::string>> result;
        for (auto& entry : ans) {
            result.push_back(entry.second);
        }
        
        return result;
    }
};
