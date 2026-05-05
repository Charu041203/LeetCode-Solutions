class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) {
            return nullptr;
        }

        int l = 0;
        ListNode* curr = head;
        while(curr) {
            l++;
            curr = curr->next;
        }

        k = k % l;

        if(k == 0) {
            return head;
        }

        ListNode* tail = head;
        while(tail->next) {
            tail = tail->next;
        }

        curr = head;
        ListNode* prev = nullptr;

        for(int i = 0; i < (l - k); i++) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = nullptr;
        tail->next = head;

        return curr;
    }
};