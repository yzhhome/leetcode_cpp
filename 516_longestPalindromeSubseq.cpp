/*
    516. 最长回文子序列
    https://leetcode-cn.com/problems/longest-palindromic-subsequence/
*/

#include <iostream>
#include <vector>

using namespace std;

int longestPalindromeSubseq(string s) {
    int n = s.size();

    // dp数组全部初始化为0
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base case
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    // 反向进行遍历
    // i: [n-2, 0]  j: [i+1, n)
    for (int i = n - 2; i >= 0; i--)
        for (int j = i + 1; j < n; j++){

            // 相等的情况说明在回文子序列中
            // 此时i往后移，j往前移
            // dp[i][j]为dp[i + 1][j - 1]的长度
            // 再加上相等的两个字符长度
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;

            // 不相等的情况说明不在回文子序列中
            // 比较s[i + 1][j]和s[i][j - 1]谁的回文子序列更长
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }

    // 第一行最后一个元素
    return dp[0][n -1];
}

int main(){
    cout<<longestPalindromeSubseq("cbxabyc");
    system("pause");
    return 0;
}