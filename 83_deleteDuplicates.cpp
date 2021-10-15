/*
    83. 删除排序链表中的重复元素
    https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head){
    if (head == nullptr) return nullptr;

    // slow为慢指针，fast为快指针
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast != nullptr){
        if (fast->val != slow->val){            
            slow->next = fast;
            slow = slow->next;
        }
        fast = fast->next;
    }
    // 断开与后面重复元素的连接
    slow->next = nullptr;
    return head;
}
