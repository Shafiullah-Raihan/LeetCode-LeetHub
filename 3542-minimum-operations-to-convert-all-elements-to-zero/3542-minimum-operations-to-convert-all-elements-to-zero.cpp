class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>st;
        int ans=0;
        ///Eikhane cinta korte hobe je barle or komle. Same thakle moruk ga. ar 0 thakle add er dorkar nai.
        for(int u:nums)
        {
            
            while(!st.empty() && st.top()>u)
            {
                st.pop();
            }
            if(u==0) continue;
            if(st.empty() || st.top()<u)
            {
                ans++;
                st.push(u);
            }
        }
        return ans;
    }
};