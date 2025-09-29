#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL)
        return list2;
    else if(list2 == NULL)
        return list1;
    
    if(list1->val <= list2->val){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }else{
        list2->next = mergeTwoLists(list2->next, list1);
        return list2;
    }
}