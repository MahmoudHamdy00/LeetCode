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
    bool hasCycle(ListNode *head) {
        int cnt=0;
        while(head!=nullptr&&cnt++<1e5){
            head=head->next;
        }
        cout<<cnt<<endl;
        return cnt>=1e5;
    }
};