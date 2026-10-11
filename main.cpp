#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // dp[i][j] = expected days to eat j more apples when we have i apples
    // We need dp[n][m]
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0.0));
    
    // Base case: if we need to eat 0 more apples, it takes 0 more days
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0.0;
    }
    
    // Fill the DP table
    for (int i = 1; i <= n; i++) {  // current number of apples
        for (int j = 1; j <= m; j++) {  // apples still needed
            double sum = 0.0;
            int max_k = min(i, j-1);  // k from 1 to max_k: we don't finish in this day
            // For k = 1 to max_k: we eat k apples and continue
            for (int k = 1; k <= max_k; k++) {
                sum += dp[i - k][j - k];
            }
            // We always spend 1 day
            // With probability max_k/i we continue, with probability (i-max_k)/i we finish
            dp[i][j] = 1.0 + sum / i;
        }
    }
    
    cout << fixed << setprecision(2) << dp[n][m] << endl;
    
    return 0;
}