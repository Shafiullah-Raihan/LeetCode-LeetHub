class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;
        for(auto u:amount)
        {
            if(u!=0) pq.push(u);
        }
        int ans=0;
        while(!pq.empty() && pq.size()>1)
        {
            int a = pq.top();pq.pop();
            int b= pq.top();pq.pop();
            ans++;a--,b--;
            if(a) pq.push(a);if(b) pq.push(b);

        }
        if(!pq.empty())
        {
            ans+= pq.top();pq.pop();
        }
        return ans;
    }
};