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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* tmp=head,*prv=nullptr;
        int i=0;
        while(tmp){
            ++i;
            if(i==left){
                ListNode* ed=tmp,*st=prv;
                while(i++<=right){
                    auto nxt=tmp->next;
                    tmp->next=st;
                    
                    st=tmp;
                    tmp=nxt;
                }
                if(prv)
                    prv->next=st;
                if(left==1)head=st;
                if(tmp)
                    ed->next=tmp;
                else ed->next=nullptr;
            }
            prv=tmp;
            if(tmp)
                tmp=tmp->next;
        }
        return head;
    }
};