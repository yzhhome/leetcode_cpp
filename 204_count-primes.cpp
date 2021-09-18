/*
    204. 计数质数（统计素数）
    素数是只能被1和自身整除的数
    https://leetcode-cn.com/problems/count-primes/
*/

#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n){
    vector<bool> isPrime(n , true);
    for (int i = 2; i * i < n; i++)
        if (isPrime[i])
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;

    int count = 0;
    for (int i = 2; i < n; i++)
        if (isPrime[i]) count++;
    return count;
}

int main(){
    cout<<countPrimes(10)<<endl;
    system("pause");
    return 0;
}