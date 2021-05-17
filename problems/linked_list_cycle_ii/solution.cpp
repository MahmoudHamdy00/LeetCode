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
    ListNode *detectCycle(ListNode *head) {
        
        while(head!=nullptr&&head->next!=nullptr){
            cout<<head->next->val<<" "<<head->val<<":"<<head->next<<" "<<head<<" "<<head->next-head<<endl;
            if(head->next-head<=0)            
                return head->next;
            head=head->next;
        }
       
        return nullptr;
    }
};