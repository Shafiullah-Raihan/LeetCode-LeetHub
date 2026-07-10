class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        vector<string>ans;
        if(n<10) return ans;
        map<string,int>mpp;
        for(int i=0;i<=(n-10);i++){
            string substring=s.substr(i,10);
            mpp[substring]++;
        }
        for(auto it:mpp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};