#include <stdio.h>
int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    int replaceIndex = numsSize-1;
    int placeholder = 0;
    short flag = 0;
    for(int i=0;i<numsSize;i++)
        if(*(nums+i) == val)
            k++;
    for(int i=0;i<numsSize;i++){
        for(int j=numsSize-1;j>numsSize-1-k;j--){
            // printf("%d ", *(nums+j));
            if(*(nums+j) != val){
                flag = 1;
                break;
            }
        }
        // printf("\n");
        if(flag == 0)
            break;
        if(i >= replaceIndex)
            break;
        if(*(nums+i) == val){
            while(*(nums+replaceIndex) == val && replaceIndex-1>=0)
                replaceIndex--;
            placeholder = *(nums+replaceIndex);
            *(nums+replaceIndex) = *(nums+i);
            *(nums+i) = placeholder;
            replaceIndex--;
        }
        flag = 0;
        // for(int k=0;k<numsSize;k++){
        //     printf("%d ", *(nums+k));
        // }
        // printf("\n");
    }
    return (numsSize - k);
}

int main(){
    int tab[] = {0,4,4,0,4,4,4,0,2};
    int k = removeElement(tab, 9, 4);
    // printf("%d\n", k);
    // printf("\n");
}