class Solution {
public:

    void raihan(int n,int k,vector<vector<int>>&ans,vector<int>& temp,int idx)
    {   
        // if(idx>n) return ;
        if(temp.size() == k) 
        {
            ans.push_back(temp);return;
        }
        for(int i=idx;i<=n;i++)
        {
            
            temp.push_back(i);
            
            raihan(n,k,ans,temp,i+1);
            temp.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        raihan(n,k,ans,temp,1);
        return ans;
    }
};