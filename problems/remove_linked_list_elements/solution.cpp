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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)return NULL;
        ListNode *cur=head,*prv=head;
        while(head!=NULL&&head->val==val){
            cur=head;
            head=head->next;
          //  delete cur;
            
        }
        for(cur=head;cur!=NULL;cur=cur->next){
            if(cur->val==val){
                prv->next=cur->next;
              //  delete cur;
                cur=prv;
            }
            prv=cur;
        }
        return head;
    }
};