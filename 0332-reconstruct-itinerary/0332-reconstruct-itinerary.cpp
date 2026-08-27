class Solution {
public:

    void dfs(string src,unordered_map<string,vector<string>>& mp,vector<string>& ans)
    {

        while(!mp[src].empty())
        {
            string node = mp[src].back();
            mp[src].pop_back();
            dfs(node,mp,ans);
        }
        ans.push_back(src);
    }


    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>mp;
        for(auto u:tickets)
        {
            mp[u[0]].push_back(u[1]);
        }
        for(auto &u:mp)
        {
            sort(u.second.rbegin(),u.second.rend());

        }
        vector<string>ans;

        
        dfs("JFK",mp,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};



    // void bfs(unordered_map<string,vector<string>>& mp,vector<string>& ans)
    // {
    //     set<string>st;
    //     // st.insert("JFK");
    //     queue<string>q;
    //     q.push("JFK");
    //     // ans.push_back("JFK");
    //     while(!q.empty())
    //     {
    //         string node = q.front();q.pop();
    //         if(st.count(node)) continue;
    //         st.insert(node);
    //         ans.push_back(node);
    //         for(auto& it: mp[node])
    //         {
    //             q.push(it);
    //         }
    //     }
    // }
    // unordered_map<string,vector<string>>mp;
    //     for(auto u:tickets)
    //     {
    //         mp[u[0]].push_back(u[1]);
    //     }
    //     for(auto &u:mp)
    //     {
    //         sort(u.second.begin(),u.second.end());

    //     }
    //     vector<string>ans;
    //     bfs(mp,ans);
    //     return ans;