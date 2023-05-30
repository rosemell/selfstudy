#define _CRT_SECURE_NO_WARNINGS 1
https://leetcode.cn/problems/middle-of-the-linked-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


 // struct ListNode* middleNode(struct ListNode* head){
 //     if(NULL==head->next)
 //     {
 //         return head;
 //     }
 //     struct ListNode* ret=head,*tail=head->next;
 //     int i=0;
 //     while(tail)
 //     {
 //         if(i%2==0)
 //         {
 //             ret=ret->next;
 //         }
 //         i++;
 //         tail=tail->next;

 //     }
 // return ret;
 // }
struct ListNode* middleNode(struct ListNode* head) {

    if (NULL == head->next)
    {
        return head;
    }
    struct ListNode* fast, * low;
    fast = head->next;
    low = head;
    while (fast && fast->next)
    {
        low = low->next;
        fast = fast->next->next;
    }
    if (fast != NULL)
    {
        return low->next;
    }
    else {
        return low;
    }
}