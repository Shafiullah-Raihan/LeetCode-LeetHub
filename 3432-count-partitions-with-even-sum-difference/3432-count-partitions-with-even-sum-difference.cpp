class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), post(n);

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                pre[0] = nums[0];
            } else {
                pre[i] = pre[i - 1] + nums[i];
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                post[n - 1] = nums[n - 1]; 
            } else {
                post[i] = post[i + 1] + nums[i];
            }
        }

        
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) { 
            if (abs(pre[i] - post[i + 1]) % 2 == 0) {
                cnt++;
            }
        }

        return cnt;
    }
};
