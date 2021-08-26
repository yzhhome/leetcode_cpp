/*
    1143. 最长公共子序列
    https://leetcode-cn.com/problems/longest-common-subsequence/
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// text1[0..i-1] 和 text2[0..j-1]，它们的 LCS 长度是 dp[i][j]
int longestCommonSubsequence(string text1, string text2){
    int m = text1.size(), n = text2.size();

    // dp数组全部初始化为0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // 找到一个属于LCS中的元素
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // 至少有一个字符不在 LCS 中
                // 取当前位置的左边和上边的 LCS
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    cout << longestCommonSubsequence("abcde", "ace") << endl;
    system("pause");
    return 0;
}
