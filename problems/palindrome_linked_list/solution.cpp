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
        vector<int>v,v2;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        v2=v;
        reverse(v.begin(),v.end());
        return v==v2;
    }
};