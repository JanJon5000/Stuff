int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i = digitsSize - 1;
    do{
        digits[i]++;
        if(digits[i] == 10 && digitsSize != 0)
            digits[i-1]++;
        i--;
    }while(i > 0 && digits[i] > 9);
    if(digits[0] == 10){
        int* ans = malloc(sizeof(int) * (digitsSize + 1));
        ans[0] = 1;
        for(int i=0;i<digitsSize;i++)
            if(digits[i] != 10)
                ans[i+1] = digits[i];
            else
                ans[i+1] = 0;
        *returnSize = digitsSize + 1;
        return ans;
    }
    *returnSize = digitsSize;
    return digits;
}