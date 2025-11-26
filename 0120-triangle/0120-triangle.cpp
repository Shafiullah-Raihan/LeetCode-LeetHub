class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<int>lastCal(n,0), curr(n,0);
        for(int i=0;i<n;i++){
            lastCal[i] = triangle[n-1][i];
        }
        for(int i= n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + lastCal[j];
                int diagonal = triangle[i][j] + lastCal[j+1];
                curr[j] = min(down,diagonal);
            }
            lastCal = curr;
        }
        return lastCal[0];
    }
};