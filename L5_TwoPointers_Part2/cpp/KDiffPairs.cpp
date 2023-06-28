class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int left = 0, right = 1;
        int result = 0;
        while (left < nums.size() && right < nums.size()) {
            if (left == right || nums[right] - nums[left] < k) {
                right++;
            } else if (nums[right] - nums[left] > k) {
                left++;
            } else {
                left++;
                result++;
                while (left < nums.size() && nums[left] == nums[left - 1])
                    left++;
            }
        }
        return result;
    }
};
