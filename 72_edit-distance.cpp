/*
    72. 编辑距离
    https://leetcode-cn.com/problems/edit-distance/
*/

#include <iostream>
#include <vector>

using namespace std;

// 最小编辑距离动态规划解法
int minDistance(string word1, string word2) {
    int l1 = word1.size();
    int l2 = word2.size();

    // dp初始化为全0的l1 * l2容器
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    // 第0列初始化为[0, l1]
    for (int i = 0; i <= l1; i++)
        dp[i][0] = i;

    // 第0行初始化为[0, l2]
    for (int j = 0; j <= l2; j++)
        dp[0][j] = j;

    for (int i = 1; i <= l1; i++){
        for (int j = 1; j <= l2; j++){
            // 两个字符相同，各自向前移动一个字符
            if (word1[i - 1] == word2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }                
            else{
                // 插入: dp[i][j - 1] 插入word2中的一个字符，j前移1
                // 删除: dp[i - 1][j] 删除word1中的一个字符，i前移1
                // 替换: dp[i - 1][j - 1] word1和word2中的字符进替换，i和j都前移1
                // 每次前移操作次数加1
                int minValue = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
                dp[i][j] = minValue + 1;
            }
        }
    }
    return dp[l1][l2];
}

int main(){
    cout << minDistance("horse", "ros") << endl;
    system("pause");
    return 0;
}