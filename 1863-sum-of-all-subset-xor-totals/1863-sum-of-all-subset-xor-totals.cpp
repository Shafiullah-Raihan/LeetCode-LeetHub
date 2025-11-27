class Solution {
public:

    void backtrack(int idx, vector<int>& arr, int currXor, int& total, int n) {
        if (idx == n) {
            total += currXor;
            return;
        }

        // Choice 1: include arr[idx]
        backtrack(idx + 1, arr, currXor ^ arr[idx], total, n);

        // Choice 2: exclude arr[idx]
        backtrack(idx + 1, arr, currXor, total, n);
    }


    int subsetXORSum(vector<int>& arr) {
        int total = 0;
        int n = arr.size();
        backtrack(0, arr, 0, total, n);
        return total;
    }
};