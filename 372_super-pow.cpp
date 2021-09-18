/*
    372. 超级次方
    计算a的b幂次方对1337取模，a是一个正整数，
    b是一个非常大的正整数且会以数组形式给出。
    https://leetcode-cn.com/problems/count-primes/
*/

#include <iostream>
#include <vector>

using namespace std;

int base = 1337;

// 计算 a 的 k 次方然后与 base 求模的结果
int mypow(int a, int k){
    a %= base;
    int res = 1;
    for (int i = 0; i < k; i++){
        res *= a;
        res %= base;
    }
    return res;
}

// 根据幂运算的性质计算a^k
// k为奇数时, a^k = a * a^(k-1)
// k为偶数时，a^k = (a^(k/2))^2
int mypow2(int a, int k){
    if (k == 0) return 1;
    a %= base;

    // k为奇数
    if (k % 2 == 1)
        return (a * mypow2(a, k-1)) % base;
    else{
        int sub = mypow2(a, k/2);
        return (sub * sub) % base;
    }
}

// 根据以下规则求a^b % k
// ab % k = (a%k)(b%k)%k
// a^1234567 % k = (a^1234560 % k) * (a^7 % k) % k = (a^123456 % k)^10 % k * (a^7 % k) % k
int superPow(int a, vector<int>& b){
    if (b.empty()) return 1;

    //取出b中最后一个数
    int last = b.back();
    b.pop_back();

    // 根据幂运行规则分解为两部分
    int part1 = mypow(a, last);    
    int part2 = mypow(superPow(a, b), 10);

    // 两部分乘法都要求模
    return (part1 * part2) % base;  
}

int main(){
    int a = 2;
    vector<int> b{1, 0};
    cout<<superPow(a, b)<<endl;
    system("pause");
    return 0;
}
