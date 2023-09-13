/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *dummy =head;
        
        
        unordered_map<Node*,Node*>mp;
        while(dummy){
            Node *newNode = new Node(dummy->val);
            mp[dummy] = newNode;
            dummy = dummy->next;
        }
        dummy= head;
        while(dummy){
            Node *cur = mp[dummy];
            cur->next = mp[dummy->next];
            cur->random = mp[dummy->random];
            dummy = dummy->next;
        }
        
        return mp[head];
    }
};