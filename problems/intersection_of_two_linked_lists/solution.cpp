/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto result1=getTail(headA);
        auto result2=getTail(headB);
        if(result1.second!=result2.second)return nullptr;
        ListNode *shortList,*longList;
        result1.first>result2.first?(longList=headA,shortList=headB):(longList=headB,shortList=headA);
        int dif=abs(result1.first-result2.first);
        while(dif--)longList=longList->next;

        while(longList){
           if(  longList==shortList)return longList;
            longList=longList->next;
            shortList=shortList->next;
        }
        return nullptr;
    }
    pair<int,ListNode *>getTail(ListNode *head) {
        if(head==nullptr)return {0,nullptr};
        int sz=0;
        while(head){
            ++sz;
            head=head->next;
        }
        return {sz,head};
    }
};