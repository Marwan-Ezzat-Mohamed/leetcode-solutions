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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *dummy = ans;
        int carry=0;
        while(l1 || l2){
         
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0 ;
            int sum = a+ b+carry;
            ans->next = new ListNode(sum % 10);
            ans = ans->next;
            carry = sum / 10;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        
       if (carry)
            ans->next = new ListNode(carry);
        
        return dummy->next;
    }
};