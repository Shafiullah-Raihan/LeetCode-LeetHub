class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {

        auto cmp_name = [] (string a, string b) {
            if(a.size() == b.size()) return a > b;
            return a.size() > b.size();
        };
        
        priority_queue<string, vector<string>, decltype(cmp_name)> minH;

        
        for(int i = 0; i < nums.size(); i++) {
            minH.push(nums[i]);
            if(minH.size() > k) minH.pop();
            
        }

        return minH.top();
    }
};