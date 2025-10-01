#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL && l2 == NULL)
        return NULL;

    if (l1 == NULL) {
        return l2;
    }
    
    if (l2 == NULL) {
        return l1;
    }

    int sum = l1->val + l2->val;
    l1->val = sum % 10;

    int carry = sum / 10;

    l1->next = addTwoNumbers(l1->next, l2->next);

    if (carry > 0) {
        struct ListNode* carryNode = malloc(sizeof(struct ListNode));
        carryNode->val = carry;
        carryNode->next = NULL;
        l1->next = addTwoNumbers(l1->next, carryNode);
    }

    return l1;
}