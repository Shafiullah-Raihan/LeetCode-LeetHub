class DSU{
    vector<int>parents,rank;
    public:
        DSU(int n)
        {
            parents.resize(n,-1);
            rank.resize(n,1);
        }
        int find(int x)
        {
            if(parents[x] == -1) return x;
            return parents[x] = find(parents[x]);
        }
        void merge(int x,int y)
        {
            int s1 = find(x),s2 = find(y);
            if(s1 != s2)
            {
                if(rank[s1]<rank[s2]) parents[s1] = s2;
                else if(rank[s1]>rank[s2]) parents[s2] = s1;
                else 
                {
                    parents[s2] = s1;
                    rank[s1] += 1;
                }
            }
        }
};

int krushkals(int n,vector<vector<int>>& edges)
{
    sort(edges.begin(),edges.end());
    DSU dsu(n);
    int ans =0,cnt=0;
    for(auto it: edges)
    {
        int w = it[0],x = it[1],y = it[2];
        if(dsu.find(x) != dsu.find(y))
        {
            dsu.merge(x,y);
            ans += w;
            cnt++;
        }
        if(cnt == n-1) break;
    }
    return ans;
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
         int n = points.size();
        vector<vector<int>>edges;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1]- points[j][1]);
                edges.push_back({cost,i,j});
            }
        }
        int ans = krushkals(n,edges);
        return ans;
    }
};