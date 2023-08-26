class Solution:
    def nodesBetweenCriticalPoints(self, head: ListNode) -> List[int]:

        ct, critPts, prev = 0, [], head.val                         # keep track of node-count, critical points
                                                                    # encountered, and previous node value
        while head.next:
																	# Tests for critical points: product < 0 if and only if
            if (prev-head.val)*(head.val-head.next.val) < 0:        #          prev < head.val > head.next.val, or 
                critPts.append(ct)                                  #          prev > head.val < head.next.val
                                                      
            prev, head = head.val, head.next                        # iterates to next node and increments node-count
            ct+= 1

        n = len(critPts)                                            # fewer than 2 nodes
        if n < 2: return [-1,-1]

        mn = min((critPts[i]-critPts[i-1] for i in range(1, n)))    # list already sorted, so min is least dist between 
        mx = critPts[-1] - critPts[0]                               # consecutive elements; max is last element - 1st element

        return [mn, mx]
