
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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 1;
        while(temp!=nullptr) {
            temp = temp->next;
            count++;
        }
        temp = head;
        if(head!=nullptr) {           
            for(int i = 1; (count%2 != 0)? i <= count/2: i < count/2; i++) {
            temp = temp->next;
            } 
        }       
        return temp; 
    }          
};