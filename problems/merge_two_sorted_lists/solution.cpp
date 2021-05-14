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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr&&l2==nullptr)return l1;
        if(l1==nullptr||l2==nullptr)return l1==nullptr?l2:l1;
        ListNode* walk=new ListNode(0);
        ListNode* ret=walk ;
        while(l1&&l2){
            if(l1->val<l2->val)walk->next=new ListNode(l1->val),l1=l1->next;
            else walk->next=new ListNode(l2->val),l2=l2->next;
            walk=walk->next;
        }
        l1? walk->next=l1:walk->next=l2;
        return ret->next;
    }
};