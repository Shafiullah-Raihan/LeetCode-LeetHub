class Solution {
public:
    int countDigits(int num) {
        int tmp = num,ans=0;
        while(tmp)
        {
            int last = tmp%10;
            tmp/=10;
            if(last ==0) continue;
            if(num%last ==0) ans++;
        }
        return ans;
    }
};