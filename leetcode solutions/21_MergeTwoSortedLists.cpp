
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        
        if(list1 == nullptr) {
            if(list2 == nullptr) {
                return head;
            } else {
                return list2;
            }
        } else if(list2 == nullptr) {
            if(list1 == nullptr) {
                return head;
            } else {
                return list1;
            }
        }
        
        ListNode* temp1 = list1, *temp2 = list2;

        if(temp1->val <= temp2->val) {
            head = temp1;
            temp1 = temp1->next;
        } else {
            head = temp2;
            temp2 = temp2->next;
        }

        ListNode* temp = head;

        while(temp1 != nullptr && temp2 != nullptr) {
            if(temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        temp->next = (temp1 != nullptr) ? temp1 : temp2;
        return head;
    }
};

