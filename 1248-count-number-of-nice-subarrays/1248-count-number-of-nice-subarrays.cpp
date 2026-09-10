class Solution {
public:
    int raihan(vector<int>& arr,int num)
    {
        int sum=0,n=arr.size();
        map<int,int>mp;
        
        for(int right=0,left=0;right<n;right++)
        {
            mp[arr[right]]++;
            while(mp[1]>num)
            {
                mp[arr[left]]--;
                if(mp[arr[left]] ==0) mp.erase(arr[left]);
                left++;
            }
            sum += (right -left +1);
        }
        return sum;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        {
            nums[i] = (nums[i]%2);
        }
        return raihan(nums,k)-raihan(nums,k-1);
        
    }
};