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
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return; // Nothing to reorder for empty or single-node lists
        }

        // Create a deep copy of the original list
        ListNode* copied = deepCopy(head);
        
        ListNode* newList = nullptr;
        ListNode* current = head;
        int size=0;
        while(current!=nullptr){
            ListNode* tmp = current->next; 
            current->next = newList;
            newList = current;
            current = tmp;      
             size++;
        }
        
        
        ListNode* ans = new ListNode(copied->val);
        copied= copied->next;
        *head = *ans;
        bool rev= true;
        size--;
        
         while(newList!=nullptr and copied!=nullptr){
             
             if (size==0)break;
             if (rev){
                 cout<<newList->val<<endl;
                 head->next = new ListNode(newList->val);
                 newList= newList->next;
             }else {
                   cout<<copied->val<<endl;
                 head->next = new ListNode(copied->val);
                 copied= copied->next;
             }
           
             rev  =! rev;
            size--;
             head= head->next;
        }
        
        head = ans->next;
 
        
        
    }

private:
    ListNode* deepCopy(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* new_head = new ListNode(head->val);
        ListNode* current_new = new_head;
        ListNode* current_original = head->next;

        while (current_original) {
            current_new->next = new ListNode(current_original->val);
            current_new = current_new->next;
            current_original = current_original->next;
        }

        return new_head;
    }
};
