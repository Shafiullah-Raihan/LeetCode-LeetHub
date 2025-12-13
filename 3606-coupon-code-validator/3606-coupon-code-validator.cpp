class Solution {
public:
    bool check(string& p)
    {
        if (p.empty()) return false;
        for(char c:p)
            {
                if(!isalnum(c) && c!='_')
                {
                    return false;
                }
            }
        return true;
    }
    bool business(string& p)
    {
        return (p=="electronics" || p=="grocery" || p=="pharmacy" || p=="restaurant");
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {


        vector<pair<string, string>> valid; 
        int n = code.size();

        for (int i = 0; i < n; i++) {
            if (check(code[i]) && business(businessLine[i]) && isActive[i]) {
                valid.emplace_back(businessLine[i], code[i]);
            }
        }

        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        sort(valid.begin(), valid.end(), [&](const pair<string, string>& a, const pair<string, string>& b) {
            if (priority[a.first] != priority[b.first])
                return priority[a.first] < priority[b.first];
            return a.second < b.second;
        });

        vector<string> ans;
        for (auto& p : valid) {
            ans.push_back(p.second);
        }
        return ans;
        
        // set<string>st;
        // int n=code.size();
        // for(int i=0;i<n;i++)
        //     {
        //         if(check(code[i]) && business(businessLine[i]) && isActive[i] )
        //         {
        //             st.insert(code[i]);
        //         }
        //     }
        // vector<string>ans;
        // for(auto u:st)
        //     {
                
        //          ans.push_back(u);
        //     }
        // return ans;
    }
};