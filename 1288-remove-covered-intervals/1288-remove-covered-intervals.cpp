class Solution {
public:

    static bool build (const pair<int,int>& a, const pair<int,int>& b)
    {
        if( a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first < b.first;
        
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> arr ;
        for(auto &it: intervals)
        {
            int f = it[0],s = it[1];
            arr.push_back({f,s});
        }
        sort(arr.begin(),arr.end(),build);

        int mx = INT_MIN,cnt=0;

        for(auto& [f,s]: arr)
        {
            if(s>mx) 
            {
                mx =s,cnt++;
            }

        }
        return cnt;
    }
};