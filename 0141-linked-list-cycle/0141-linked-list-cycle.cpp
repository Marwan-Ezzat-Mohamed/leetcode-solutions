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
//         unordered_map<ListNode*,int>mp;
//         while(head){
//             if(mp[head]){
//                 return true;
//             }
//             mp[head]++;
//             head= head->next;
//         }
        
//         return false;
        
        ListNode *fast,*slow;
        fast = head;
        slow = head;
        
        while(fast!=nullptr and slow!=nullptr and fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
        
    }
};