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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *merged,*tmp;
        merged = new ListNode();
        tmp = merged;
        while(list1!=nullptr and list2!=nullptr)
        {
            if (list1->val > list2->val){
                tmp->next= list2;
                list2 = list2->next;
            }
            
             else {
                tmp->next= list1;
                list1 = list1->next;
                
            }  
            tmp = tmp->next;
        }
        
        if(list1) tmp->next = list1;
        if(list2) tmp->next = list2;
        
   
        return merged->next;
    }
};