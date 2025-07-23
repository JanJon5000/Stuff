int removeDuplicates(int* nums, int numsSize) {
    int k = 1;
    int before = *nums;
    for(int i=0;i<numsSize;i++){
        if(before != *(nums + i)){
            *(nums+k) = *(nums+i);
            before = *(nums+k);
            k++;
        }
    }
    return k;
}