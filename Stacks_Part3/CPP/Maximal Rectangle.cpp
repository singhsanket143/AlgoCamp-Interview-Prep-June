class Solution {
public:
    int maximalRectangle(vector<vector<char>>& M) {
        if(!size(M)) return 0;
        int ans = 0, m = size(M), n = size(M[0]);
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) 
                for(int row = i, colLen = n, col; row < m && M[row][j] == '1'; row++) {
                    for(col = j; col < n && M[row][col] == '1'; col++);
                    colLen = min(colLen, col-j);
                    ans = max(ans, (row-i+1) * colLen);
                }
            
        return ans;
    }
};
