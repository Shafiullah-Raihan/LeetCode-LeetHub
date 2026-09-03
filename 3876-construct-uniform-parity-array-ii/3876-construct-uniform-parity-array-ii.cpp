class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        if(nums1.size()==1) return true;
        int par = nums1[0]%2;
        if(par == 1) return true;
        int n=nums1.size();
        int odd =0;
        for(int i=0;i<n;i++)
        {
            if(nums1[i]%2 == 1) odd++;
        }
        if(odd)
        {
            return false;
        }
        return true;



        // vector<int>pararr(n);
        // for(int i=0;i<n;i++)
        // {
        //     if(i==0)
        //     {
        //         pararr[i] = nums1[i]%2;continue;
        //     }
        //     pararr[i] = (nums1[i]%par) + pararr[i-1];

        // }
        // bool flag = true;
        // for(int i=n-1;i>=1;i--)
        // {
        //     if(nums1[i]%2 == par) continue;
        //     else{
        //         if(pararr[i] == 0)
        //         {
        //             flag = false;
        //         }
        //     }
        // }
        // return flag;
    }
};