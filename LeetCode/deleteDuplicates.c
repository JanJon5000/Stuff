#include <stdio.h>
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    if(head->next->val == head->val){
        head->next = head->next->next;
        deleteDuplicates(head);
    }else{
        deleteDuplicates(head->next);
    }
    return head;
}