
class Solution(object):
    dirs = [(0,1), (0,-1), (1,0), (-1,0), (1,1), (1,-1), (-1,1), (-1,-1), (0,0)]
    def gridIllumination(self, N, lamps, queries):
        """
        :type n: int
        :type lamps: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        m1 = defaultdict(int)  # row number to count of lamps
        m2 = defaultdict(int)  # col number to count of lamps
        m3 = defaultdict(int)  # diagonal x-y to count of lamps
        m4 = defaultdict(int)  # diagonal x+y to count of lamps
        m5 = defaultdict(int)  # whether lamp is ON|OFF
        
        # increment counters while adding lamps
        for lamp in lamps:
            x, y = lamp
            m1[x] += 1
            m2[y] += 1
            m3[x - y] += 1
            m4[x + y] += 1
            m5[N * x + y] += 1

        ans = []
        # address queries
        for query in queries:
            x, y = query
            ans.append(int(m1[x] > 0 or m2[y] > 0 or m3[x - y] > 0 or m4[x + y] > 0))
            
            # switch off the lamps, if any
            for d in self.dirs:
                x1 = x + d[0]
                y1 = y + d[1]
                if 0 <= x1 < N and 0 <= y1 < N and (N * x1 + y1) in m5:
                    times = m5[N * x1 + y1]
                    m1[x1] -= times
                    m2[y1] -= times
                    m3[x1 - y1] -= times
                    m4[x1 + y1] -= times
                    del m5[N * x1 + y1]
        
        return ans
