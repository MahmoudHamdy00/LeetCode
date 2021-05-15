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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ret=head;
        int N=0;
        while(head&&++N)
            head=head->next;
        if(head)
            head->next=head->next->next;
        else 
            head==nullptr;
        head=ret;
        n=N-n;
        cout <<N<<" "<<n<<endl;
        if(n==0)return ret->next;
        while(head&&--n)
            head=head->next;
     //   cout<<head->val<<endl;
        if(head&&head->next)
            head->next=head->next->next;
        else 
            head==nullptr;
        return ret;
    }
};