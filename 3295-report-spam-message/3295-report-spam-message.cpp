class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string>st;
        for(auto u:bannedWords)
        {
            st.insert(u);
        }
        int cnt=0;
        for(auto u:message)
        {
            if(st.count(u)) cnt++;
             if(cnt>=2)
             {
                return true;
             }
        }
        
        return false;
        
    }
};