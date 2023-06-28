class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            std::swap(nums[i], nums[j]);
        }
        reverse(nums, i + 1);
    }

private:
    void reverse(std::vector<int>& nums, int start) {
        int i = start, j = nums.size() - 1;
        while (i < j) {
            std::swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};
