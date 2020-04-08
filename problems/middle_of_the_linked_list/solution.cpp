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
    ListNode* middleNode(ListNode* head) {
        int n=0;
        ListNode *tmp=head;
        while(tmp!=NULL){
            n++;
            tmp=tmp->next;
        }
        n=n/2;
        while(n--){
            head=head->next;
        }
        return head;
    }
};