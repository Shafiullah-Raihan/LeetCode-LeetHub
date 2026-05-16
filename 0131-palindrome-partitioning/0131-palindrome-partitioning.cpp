class Solution {
public:
    bool isPalindrome(string& s,int left,int right){
        while(left < right){
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
            
        }
        return true;
    }

    void solve(string& s,vector<vector<string>>& ans,int index,vector<string>& temp)
    {
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }
        string store = "";
        for(int i=index;i<s.size();i++){
            store+= s[i];
            if(isPalindrome(s,index,i)){
                temp.push_back(store);
                solve(s,ans,i+1,temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        if(s.empty()){
            return ans;
        }
        solve(s,ans,0,temp);
        return ans;
    }
};