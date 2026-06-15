class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0,left=0,right=0,mx=0;

        while(right<nums.size()-1){
            for(int i=left;i<=right;i++){
                mx = max(mx,i+nums[i]);

            }
            left= right+1;
            right = mx;
            jumps++;

        }
        return jumps;
        
    }
};