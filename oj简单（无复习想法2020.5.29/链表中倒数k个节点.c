//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//
//
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

/**
 * 
 * @param pListHead ListNode类 
 * @param k int整型 
 * @return ListNode类
 */
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k ) {
    // write code here
    
    struct ListNode*low=pListHead,*fast=pListHead;
    int i=0;
    for(i=0;i<k;i++)
    {
       if(fast==NULL)
    {
        return NULL;
    }
        fast=fast->next;
    }
     
    while(fast)
    {
        low=low->next;
        fast=fast->next;
    }
    return low;
}