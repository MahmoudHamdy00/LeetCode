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
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforeStart=nullptr;
        ListNode* beforeEnd=nullptr;
        ListNode* afterStart=nullptr;
        ListNode* afterEnd=nullptr;
        
        while(head!=nullptr){
            ListNode* next=head->next;
            if(head->val<x){
                if(beforeStart==nullptr){
                    beforeStart=head;
                    beforeEnd=beforeStart;
                }
                else {
                    beforeEnd=beforeEnd->next=head;
                }
            }
            else{
                if(afterStart==nullptr){
                   afterStart=head;
                    afterEnd=afterStart;
                }
                else {
                    afterEnd=afterEnd->next=head;
                }
            }
            head=next;
        }
        if(afterEnd)
        afterEnd->next=nullptr;
        if(beforeStart==nullptr)return afterStart;
        beforeEnd->next=afterStart;
        return beforeStart;
    }
};