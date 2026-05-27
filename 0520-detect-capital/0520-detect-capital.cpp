class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        bool upcase = false;
        int up=0,low=0;
        for(int i=0;i<n;i++)
        {
            if(islower(word[i])) low++;
            if(isupper(word[i])) up++;
        }
        if(isupper(word[0]) && up==1) upcase = true;
        return (upcase || up==n || low==n);
    }

};