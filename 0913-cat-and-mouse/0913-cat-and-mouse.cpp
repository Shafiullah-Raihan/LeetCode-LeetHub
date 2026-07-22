class Solution {
public:
    int solve(int mouse_pos, int cat_pos, int turn, vector<vector<int>> &graph, vector<vector<vector<int>>> &dp, map<vector<int>,bool> &state) {
        if (mouse_pos == 0)                         
            return 1;
        if (mouse_pos==cat_pos)                    
            return 2;
        
        if (dp[mouse_pos][cat_pos][turn]!=-1)       
            return dp[mouse_pos][cat_pos][turn];

        vector<int> s = {mouse_pos,cat_pos,turn};
        if (state[s])                              
            return 0;
        state[s] = true;                           

        bool draw = false;

        if (turn==1) {                              
            for (auto path:graph[mouse_pos]) {
                int future_ans = solve(path,cat_pos,2,graph,dp,state);
                if (future_ans == 0)                
                    draw = true;
                else if (future_ans == 1)  {       
                    return dp[mouse_pos][cat_pos][turn] = turn;
                }
            }
        }
        else {                                     
            for (auto path:graph[cat_pos]) {
                if (path==0)                        
                    continue;
                int future_ans = solve(mouse_pos,path,1,graph,dp,state);
                if (future_ans == 0)               
                    draw = true;
                else if (future_ans == 2)   {      
                    return dp[mouse_pos][cat_pos][turn] = turn;
                }
            }
        }
        state[s] = false;                           

        if (draw)                                 
            return dp[mouse_pos][cat_pos][turn] = 0;
        return dp[mouse_pos][cat_pos][turn] = (turn==1) ? 2 : 1;   
    }

    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        map<vector<int>,bool> state;
        vector<vector<vector<int>>> dp(53,vector<vector<int>>(53,vector<int>(3,-1)));
        int ans;
        for (int turn=0; turn<n; turn++) {      
            
            for (int i=0;i<n;i++) {
                for (int j=1;j<n;j++) {
                    for (int k=1;k<=2;k++) {
                        if (dp[i][j][k]==0) 
                            dp[i][j][k] = -1;
                    }
                }
            }
            ans = solve(1,2,1,graph,dp,state);
        }
        return ans;
    }
};