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
        if (head == NULL || head->next == NULL) return head;
        if(head->next->next == NULL){
            ListNode* temp = head->next;
            head->next->next = head;
            head->next = NULL;
            return temp;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* third = second->next;

        while(third != NULL){
            second->next = first;
            first = second;
            second = third;
            third = third->next;
        }
        second->next = first;
        head->next = NULL;
        return second;

    }
};