
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
    bool isPalindrome(ListNode* head) {
        if(head!=nullptr) {
            ListNode* reversed = new ListNode(head->val);
            {
                ListNode* temp = head;
                while(temp->next!=nullptr) {
                    ListNode* curr = new ListNode(temp->next->val);
                    curr->next = reversed;
                    reversed = curr;
                    temp = temp->next;
                }
            } 
            while(head!=nullptr) {
                if(head->val != reversed->val) {
                    return false;
                }
                head = head->next;
                reversed = reversed->next;
            }
            return true;
        }
        return false;
    }
};