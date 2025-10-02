// #include <stdio.h>
// #include <math.h>
// struct node{
//     int value, key;
//     struct node* next;
// };

// void setNode(struct node* n, int key,  int value){
//     n->value = value;
//     n->key = key;
//     n->next = NULL;
// }

// struct hashMap {
//     int capacity;
//     struct node** arr;
// };

// struct hashMap* initializeHashMap(int capacity){
//     struct hashMap *ans = malloc(sizeof(struct hashMap));
//     ans->capacity = capacity;
//     ans->arr = malloc(capacity * sizeof(struct node));
//     return ans;
// }

// void insert(struct hashMap* map, struct node* n, int target){
//     struct node* placeholder = *((map->arr)+(abs(target-n->value)%target));
//     while(placeholder->next != NULL){
//         placeholder = placeholder->next;
//     }
//     placeholder->next = n;
// }

// struct node* get(int value, struct hashMap* map, int target, struct node* n){
//     return *((map->arr)+(abs(target-n->value)%target));
// }

// int* twoSum(int* nums, int numSize, int target, int* returnSize){
//     int* ans = malloc(sizeof(int));
//     struct hashMap h* = initializeHashMap(target-1);
//     for(int i=0;i<numSize;i++){
//         if(get(nums[i], h, target, ))
//     }
//     return ans;
// }
int* twoSum(int* nums, int numSize, int target, int* returnSize){
    int* ans = malloc(2 * sizeof(int));
    *returnSize = 2;
    for(int i=0;i<numSize-1;i++){
        for(int j=i+1;j<numSize;j++){
            if(nums[i] + nums[j] == target){
                ans[0] = i; ans[1] = j;
                break;
            }
        }
    }
    return ans;
}