#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dp(int m, int n)
    {
        int** dp = new int*[m];
        for (int i = 0; i < m; i++) {
            dp[i] = new int[n];
        }

        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// 11 col 11 row
int main()
{
    int m, n;

    cin >> m >> n;

    Solution s;
    cout << "到达右上角共有 " << s.dp(m, n) << " 种走法" << endl;
}