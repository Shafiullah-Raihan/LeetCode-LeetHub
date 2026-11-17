class Solution {
    public int minimumChanges(String s, int k) {
        int[][] dp1 = new int[s.length()][k + 1];
        int[][] dp2 = new int[s.length()][s.length()];
        Arrays.stream(dp1).forEach(arr -> Arrays.fill(arr, -1));
        Arrays.stream(dp2).forEach(arr -> Arrays.fill(arr, -1));
        return solve(s, 0, k, dp1, dp2);
    }

    int solve(String s, int idx, int k, int[][] dp1, int[][] dp2) {
        if (k == 1) {
            return check(s, idx, s.length() - 1, dp2);
        }
        if (dp1[idx][k] != -1) {
            return dp1[idx][k];
        }
        int ans = Integer.MAX_VALUE;
        int limit = s.length() - ((k - 1) * 2);
        for (int i = idx + 1; i < limit; i++) {
            int v = check(s, idx, i, dp2) + solve(s, i + 1, k - 1, dp1, dp2);
            ans = Math.min(ans, v);
        }
        return dp1[idx][k] = ans;
    }

    int check(String s, int start, int end, int[][] dp2) {
        if (dp2[start][end] != -1) {
            return dp2[start][end];
        }
        int len = end - start + 1;
        int min = Integer.MAX_VALUE;
        for (int i = 1; i < len; i++) {
            if (len % i != 0) continue;
            int currentResult = 0;
            for (int j = 1; j <= i; j++) {
                int left = start + j - 1;
                int right = end - i + j;
                while (left <= right) {
                    if (s.charAt(left) != s.charAt(right)) {
                        currentResult++;
                    }
                    left += i;
                    right -= i;
                }
            }
            min = Math.min(min, currentResult);
        }
        return dp2[start][end] = min;
    }
}