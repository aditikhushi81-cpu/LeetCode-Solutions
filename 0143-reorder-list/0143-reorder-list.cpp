class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        // 1. Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse the second half
        ListNode* curr = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. Merge both halves
        ListNode* first = head;
        ListNode* second = prev;

        while (second != NULL) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};