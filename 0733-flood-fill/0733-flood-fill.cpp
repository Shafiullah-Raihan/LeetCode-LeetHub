class Solution {
public:
    int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int i,int j, int color) {

        int n = image.size(), m = image[0].size();
        int prevColor = image[i][j];
        if(prevColor == color) return image;

        queue<pair<int,int>>q;

        q.push({i,j});

        

        while(!q.empty())
        {
            auto [i,j] = q.front();

            q.pop();
            image[i][j] = color;
            for(int k=0;k<4;k++){
                int x = i + dx[k] , y = j + dy[k];
                if(x<0 || x>=n || y<0 || y >=m) continue;
                if(image[x][y] == prevColor){
                    
                    q.push({x,y});
                }
            } 
        }
        return image;

    }
};