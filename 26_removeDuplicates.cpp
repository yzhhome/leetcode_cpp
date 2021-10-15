/*
    26. 删除有序数组中的重复项
    https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
*/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums){
    int n = nums.size();
    if (n == 0) return 0;

    //slow为慢指针, fast为快指针
    int slow = 0, fast = 1;
    while (fast < n)
    {
        if (nums[fast] != nums[slow]){
            slow++;
            // nums[slow]为不重复的元素
            nums[slow] = nums[fast];
        }
        fast++;        
    }
    return slow + 1;
}

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout<<removeDuplicates(nums)<<endl;
    system("pause");
    return 0;
}
