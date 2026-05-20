class Solution {
public:
    char findTheDifference(string s, string t) {

        int tSum = 0;
        for(char c : t){
            tSum += c;
        }

        int sSum = 0;
        for(char c : s){
            sSum += c;
        }

        return (char)(tSum - sSum);
    }
};