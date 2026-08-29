class Solution {
public:
    int raihan(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (int left = 0, right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;

            while (mp.size() > k) {
                mp[nums[left]]--;

                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }

                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return raihan(nums, k) - raihan(nums, k - 1);
    }
};


// class Solution {
// public:
//     int raihan(vector<int>& nums,int k)
//     {
//         unordered_map<int,int>mp;
//         int n= nums.size(),ans=0;
//         for(int left=0,right=0;left<=right,right<n;right++)
//         {
//             mp[nums[right]]++;
//             while(mp.size() > k)
//             {
//                 mp[nums[left]]--;
//                 if(mp[nums[left]] == 0) mp.erase(nums[left]);
//                 left++;
//             }
//             if(mp.size() == k)
//             {
//                 ans = ans + (right - left+1);
//             }

//         }
//         return ans;
//     }
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         return raihan(nums,k) - raihan(nums,k-1);
//     }
// };