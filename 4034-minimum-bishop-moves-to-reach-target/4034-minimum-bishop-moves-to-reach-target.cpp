class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int xi=source[0];int yi=source[1];
        int xf = target[0];int yf=target[1];
        
        if(xi == xf && yi == yf)
        {
            return 0;
        }
        else if(abs(xi-xf) == abs(yi-yf))
        {
            return 1;
        }
        else if((xi+yi)%2 != (xf+yf)%2)
        {
            return -1;
        }
        else{
            return 2;
        }
    }
};