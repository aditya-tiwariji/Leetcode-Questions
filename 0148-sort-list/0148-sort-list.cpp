class Solution {
public:

    ListNode* merge(ListNode* i, ListNode* j) {

        ListNode* prev = new ListNode(-1);
        ListNode* cur = prev;

        while(i && j) {

            if(i->val <= j->val) {
                cur->next = i;
                cur = i;
                i = i->next;
            }
            else {
                cur->next = j;
                cur = j;
                j = j->next;
            }
        }

        while(i) {
            cur->next = i;
            cur = i;
            i = i->next;
        }

        while(j) {
            cur->next = j;
            cur = j;
            j = j->next;
        }

        return prev->next;
    }

    ListNode* mergeSort(ListNode* l, ListNode* r) {

        if(l == r) {
            return l;
        }

        ListNode* slow = l;
        ListNode* fast = l;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow;
        ListNode* nx = mid->next;

        mid->next = NULL;

        ListNode* left = mergeSort(l, mid);
        ListNode* right = mergeSort(nx, r);

        return merge(left, right);
    }

    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        ListNode* l = head;
        ListNode* r = head;

        // Find last node
        while(r->next) {
            r = r->next;
        }

        return mergeSort(l, r);
    }
};