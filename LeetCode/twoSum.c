int* twoSum(int* nums, int numSize, int target, int* returnSize){
    int* ans = malloc(2 * sizeof(int));
    *returnSize = 2;
    for(int i=0;i<numSize-1;i++){
        if(nums[i]>target)
            continue;
        for(int j=i+1;j<numSize;j++){
            if(nums[i] + nums[j] == target){
                ans[0] = i; ans[1] = j;
                break;
            }
        }
    }
    return ans;
}