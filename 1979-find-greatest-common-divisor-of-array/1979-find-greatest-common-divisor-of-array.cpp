class Solution {
public:

    

    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(),nums.end());
        int mx = *max_element(nums.begin(),nums.end());
        int ans = __gcd(mn,mx);
        return ans;

    }
};