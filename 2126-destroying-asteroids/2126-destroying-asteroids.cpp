class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
        int n= arr.size();
        sort(arr.begin(),arr.end());
        long long sum=mass;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=sum)
            {
                sum += arr[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};