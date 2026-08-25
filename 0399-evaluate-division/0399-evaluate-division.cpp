class Solution {
public:
    // cout<<fixed<<setprecission(5);
    double bfs(string start,string target,unordered_map<string, vector<pair<string, double>>>& graph)
    {
        queue<pair<string,double>>q;
        double ans =1.0;
        q.push({start,1.0});
        set<string>st;
        st.insert(start);
        while(!q.empty())
        {
            auto frnt = q.front();q.pop();
            string node = frnt.first;double w = frnt.second;
            if(node == target)
            {
                return w;
            }
            for(auto &[child, nodeW] : graph[node])
            {
                // string child = u.first;double nodeW = u.second;
                if(st.count(child)) continue;
                st.insert(child);
                q.push({child, nodeW * w});
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for(int i=0;i<equations.size();i++)
        {
            string start = equations[i][0];
            string end = equations[i][1];
            double val = values[i];
            graph[start].push_back({end,val/1.0});
            graph[end].push_back({start,1.0/val});
        }

        // set<double>st;
        vector<double>ans;
        for(auto &u: queries)
        {
            string start = u[0],target=u[1];
            if(!graph.count(start) || !graph.count(target)) 
            {
                ans.push_back(-1.0);continue;
            }
            double div = bfs(start,target,graph);
            ans.push_back(div);
        }
        return ans;






















        // vector<vector<pair<string,double>>>q;
        // for(int i=0;i<equations.size();i++)
        // {
        //     q[equations[i][0]].push_back({equations[i][1],values[i]/1.0});
        //     q[equations[i][1]].push_back({equations[i][0],1.0/(values[i]*1.0)});
        // }
        // for(auto u:queries)
        // {
        //     auto f = u[0],s = u[1];

        // }
    }
};