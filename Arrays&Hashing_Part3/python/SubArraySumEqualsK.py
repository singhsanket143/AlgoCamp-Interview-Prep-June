class Solution(object):
    def subarraySum(self, nums, k):
        count = 0
        sum = 0
        map = defaultdict(int)
        map[0] = 1
        
        for num in nums:
            sum += num
            
            if (sum - k) in map:
                count += map[sum - k]
            
            map[sum] += 1
        
        return count
