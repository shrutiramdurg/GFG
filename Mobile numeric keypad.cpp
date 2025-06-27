class Solution {
public:
    int getCount(int n) {
        if (n == 1) return 10;

        vector<vector<int>> moves(10);
        moves[0] = {0, 8};
        moves[1] = {1, 2, 4};
        moves[2] = {2, 1, 3, 5};
        moves[3] = {3, 2, 6};
        moves[4] = {4, 1, 5, 7};
        moves[5] = {5, 2, 4, 6, 8};
        moves[6] = {6, 3, 5, 9};
        moves[7] = {7, 4, 8};
        moves[8] = {8, 5, 7, 9, 0};
        moves[9] = {9, 6, 8};

        vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
        
        for (int d = 0; d <= 9; d++)
            dp[1][d] = 1;

        for (int i = 2; i <= n; i++) {
            for (int d = 0; d <= 9; d++) {
                for (int prev : moves[d]) {
                    dp[i][d] += dp[i - 1][prev];
                }
            }
        }

        long long ans = 0;
        for (int d = 0; d <= 9; d++)
            ans += dp[n][d];

        return ans;
    }
};
