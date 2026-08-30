class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n= nums.size();
        if (n==1) return 1;
        if(n ==2) return 2;
        multiset<pair<int,int>>mlst;
        for(int i=0;i<n;i++)
        {
            mlst.insert({nums[i],i});
        }
        int mnval = mlst.begin()->first; int mnidx = mlst.begin()->second;
        int mxval = mlst.rbegin()->first; int mxidx = mlst.rbegin()->second;
        if(mnidx>mxidx) swap(mnidx,mxidx);
        int ans = min({mxidx+1,n-mnidx,n+mnidx+1-mxidx});
        return ans;

    }
};