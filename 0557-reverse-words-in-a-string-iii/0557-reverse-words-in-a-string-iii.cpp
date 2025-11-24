class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        stringstream ss(s);
        string word,ans,res;
        while(ss>>word)
        {
            reverse(word.begin(),word.end());
            res += word + " ";
        }
        res.pop_back();
        return res;

    }
};