class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while (headA != nullptr) {
            ListNode *pB = headB;
            while (pB != nullptr) {
                if (headA == pB) return headA;
                pB = pB->next;
            }
            headA = headA->next;
        }
        return nullptr;
    }
};
