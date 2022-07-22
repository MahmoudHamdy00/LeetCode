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
        ListNode* l=new ListNode(0),*r=new ListNode(0),*L=nullptr,*R=nullptr;
        while(head){
            if(head->val<x){
                l->next=new ListNode(head->val);
                if(L==nullptr)
                    L=l->next;
                l=l->next;          
            }
            else{
                r->next=new ListNode(head->val);
                if(R==nullptr)R=r->next;
                r=r->next;
            }
            head=head->next;
        }
        if(!L)return R;
        l->next=R;
        return L;
    }
};