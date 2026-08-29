class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        vector<int>emne = nums;
        vector<int>postgcd,pregcd;
        int ans=INT_MIN;

        for(int notin = -1;notin<n;notin++)
            {
                vector<int>arr;
                for(int i=0;i<n;i++)
                    {
                        if(i != notin)
                        {
                            arr.push_back(emne[i]);
                        }
                    }
                int m = arr.size();
                postgcd.resize(m),pregcd.resize(m);
                postgcd[m-1]=arr[m-1];pregcd[0]=arr[0];
                for(int i=1;i<m;i++)
                {
                    pregcd[i] = __gcd(pregcd[i-1],arr[i]);
                }
                for (int i = m - 2; i >= 0; --i) {
                postgcd[i] = gcd(postgcd[i + 1], arr[i]);
                }
                int cnt =0;
                for (int i = 0; i < m - 1; ++i) {
                if (pregcd[i] == postgcd[i + 1]) 
                    {
                        cnt++;
                    }
                }
                ans = max(ans,cnt);
            }
    return ans;




        
        // postgcd[n-1]=nums[n-1];pregcd[0]=nums[0];
        // for(int i=1;i<n;i++)
        //     {
        //         pregcd[i] = __gcd(pregcd[i-1],nums[i]);
        //     }
        // for(int i=n-2;i>=0;i--)
        //     {
        //         postgcd[i] = __gcd(postgcd[i+1],nums[i]);
        //     }
        
        // for(int i=0;i<n-1;i++)
        //     {
        //         if(pregcd[i] == postgcd[i+1])
        //         {
        //             ans = max(ans,i);
        //         }
        //     }
        // for(int i=1;i<n-1;i++)
        //     {
        //         if(pregcd[i-1] == postgcd[i+1])
        //         {
        //             ans = max(ans,i);
        //         }
        //     }
        // return ans;
    }
};