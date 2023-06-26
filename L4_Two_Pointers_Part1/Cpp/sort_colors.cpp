#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, k = 0, j = nums.size() - 1;
        while(k <= j) {
            if(nums[k] == 0) {
                swap(nums[k], nums[i]);
                i++; k++;
            } else if(nums[k] == 2) {
                swap(nums[k], nums[j]);
                j--;
            } else {
                k++;
            }
        }
    }
};