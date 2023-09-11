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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* newList = nullptr;
        ListNode* current = head;
        
        while(current!=nullptr){
            ListNode* tmp = current->next; 
            current->next = newList;
            newList = current;
            current = tmp;                        
        }
        
        return newList;
        
    }
};