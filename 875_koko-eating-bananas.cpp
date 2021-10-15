/*
    875. 爱吃香蕉的珂珂
    https://leetcode-cn.com/problems/koko-eating-bananas/
*/

#include <iostream>
#include <vector>

using namespace std;

// n根香蕉以speed吃完需要的时间
int timeof(int n, int speed){    
    return (n /speed) + ((n % speed > 0) ? 1 : 0);
}

// piles堆香蕉，以speed的速度，H小时内能否吃完
bool canFinish(vector<int> piles, int speed, int H){
    // 累加吃每堆香蕉的时间
    int time = 0;
    for (int n: piles){
        time += timeof(n, speed);
    }    
    // 判断需要的时间是否小于指定的时间
    return time <= H;
}

// 每堆香蕉根数的最大值
int getMax(vector<int> piles){
    int maxValue = 0;
    for (int n : piles){
        maxValue = max(maxValue, n);
    }
    return maxValue;
}

int minEatingSpeed(vector<int> piles, int H){
    // 套用二分搜索左侧边界的算法框架
    int left = 1, right = getMax(piles) + 1;

    while (left < right){
        int mid = left + (right - left) / 2;
        if (canFinish(piles, mid, H)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;  
}

int main(){
    int H = 8;
    vector<int> piles = {3,6,7,11};
    cout<<minEatingSpeed(piles, H)<<endl;
    system("pause");
    return 0;
}