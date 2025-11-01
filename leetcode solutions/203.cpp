
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head!=nullptr) {
            ListNode* temp = head;
            while(temp != nullptr) {
                if(head->val == val) {
                    ListNode* curr = head;
                    head = head->next;
                    delete curr;
                    
                    if(head == nullptr) {return head;}
                    temp = head;
                } else if(temp->next && temp->next->val == val) {
                    ListNode* node = temp->next;
                    temp->next = node->next;
                    delete node;
                   
                } else {
                    temp = temp->next;
                }
                
            }
        }
        return head;
    }
};