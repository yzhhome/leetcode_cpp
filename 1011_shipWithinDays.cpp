/*
    1011. 在D天内送达包裹的能力
    https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/
*/

#include <iostream>
#include <vector>

using namespace std;

// weights重量的货物，以cap的运载能力，D天内能否完成运输
bool canFinish(vector<int> weights, int D, int caps){
    int i = 0;    
    for (int day = 0; day < D; day++){
        int maxCap = caps;
        while ((maxCap -= weights[i]) >= 0){
            i++;
            // 能装下货物
            if (i ==  weights.size())
                return true;
        }
    }
    return false;
}

// 货物重量的最大值
int getMax(vector<int> weights){
    int maxValue = 0;
    for (int n : weights){
        maxValue = max(maxValue, n);
    }
    return maxValue;
}

// 货物重量的和
int getSum(vector<int> weights){
    int sumValue = 0;
    for (int n : weights){
        sumValue += n;
    }
    return sumValue;
}

int shipWithinDays(vector<int> weights, int days){
    // 套用二分搜索左侧边界的算法框架
    int left = getMax(weights), right = getSum(weights) + 1;

    while (left < right){
        int mid = left + (right - left) / 2;
        if (canFinish(weights, days, mid)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;  
}

int main(){
    int D = 5;
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    cout<<shipWithinDays(weights, D)<<endl;
    system("pause");
    return 0;
}