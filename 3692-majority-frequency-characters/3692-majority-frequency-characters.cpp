// class Solution {
// public:
//     string majorityFrequencyGroup(string s) {
//         vector<int>freq(26,0);
//         int mx=0;
//         unordered_map<int,int>mp;
//         for(auto u:s)
//         {
//             int n=(int)(u-'a');
            
//             int old = freq[n];        
//             if (old > 0) {
//                 mp[old]--;
//                 if (mp[old] == 0) mp.erase(old);   
//             }
//             freq[n]++;
//             mp[freq[n]]++;

            
//         }
//         for (auto &p : mp) {
//             mx = max(mx, p.second);
//         }
//         string ans="";
       

//         for (int i = 0; i < 26; ++i) {
//             if (freq[i] > 0 && mp[freq[i]] == mx) {
//                 ans += char('a' + i);
//             }
//         }
//         return ans;

//     }
// };





class Solution {
    public:
    string majorityFrequencyGroup(string s) {
        vector<int> freq(26, 0);
        unordered_map<int, int> mp;

        for (char u : s) {
            int n = u - 'a';
            int old = freq[n];
            if (old > 0) {
                mp[old]--;
                if (mp[old] == 0) mp.erase(old);
            }
            freq[n]++;
            mp[freq[n]]++;
        }

       
        int mx = 0;
        for (auto &p : mp) {
            if (p.second > mx) mx = p.second;
        }


        int targetFreq = 0;
        for (auto &p : mp) {
            if (p.second == mx) targetFreq = max(targetFreq, p.first);
        }

        string ans = "";
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == targetFreq) ans += char('a' + i);
        }

        return ans;
    }
};
