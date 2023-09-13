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
        ListNode* dummy = head;
        ListNode* ans = new ListNode(0,head);
        ListNode* ans2 = ans;
        int size=0;
        while(dummy!=nullptr){
            dummy = dummy->next;
            size++;
        }
        
        size-=n;
        while(size>0 and ans!=nullptr){
            ans = ans->next;
            size--;
        }
        if(ans and ans->next){
            ans->next = ans->next->next;
        }

        return ans2->next;
        
    }
};