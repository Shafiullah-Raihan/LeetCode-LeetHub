

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool isValid(int n,int m, int x,int y ,vector<vector<char>>& grid)
    {
        return (x<n && x >= 0 && y<m && y>=0 && grid[x][y] == '1');
    }



    void dfs(int x1,int y1, int n,int m,vector<vector<char>>& grid){
        grid[x1][y1] = '0';

        for(int i=0;i<4;i++){

            int x= x1+ dx[i], y = y1 + dy[i];
            if(isValid(n,m,x,y,grid)){
                dfs(x,y,n,m,grid);
            }
        }
        
    }




    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1')
                {
                    dfs(i,j,n,m,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};