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
    bool isPalindrome(ListNode* head) {
        ListNode* org=head;
        ListNode* rev=nullptr;
        while(head){
            ListNode* cur=new ListNode(head->val);
            cur->next=rev;
            rev=cur;
            head=head->next;
        }
        while(rev){
            if(org->val!=rev->val)return 0;;
            rev=rev->next;
            org=org->next;
        }
        return 1;
    }
  
};