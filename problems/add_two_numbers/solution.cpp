/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addHelper(l1,l2,0);
    }
    ListNode* addHelper(ListNode* l1, ListNode* l2,int carry){
        if(l1==NULL&&l2==NULL&&carry==0)return NULL;
        ListNode* ret=new ListNode(0);
        int val=carry;
        if(l1)val+=l1->val;
        if(l2)val+=l2->val;
        ret->val=val%10;
        ret->next=addHelper(l1?l1->next:NULL,l2?l2->next:NULL,val/10);
        return ret;
    }
};