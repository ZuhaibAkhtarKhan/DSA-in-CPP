
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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int count = -1;
        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }
        temp = head;
        int decimal = 0;
        while(temp != nullptr) {
            if(temp->val == 1) {
                int pow = count;
                while(pow > 0) {
                    temp->val = temp->val*2;
                    pow--;
                }
            }
            count--;           
            decimal += temp->val;
            decimal++;
            temp = temp->next;
        }

        return decimal;
    }
};