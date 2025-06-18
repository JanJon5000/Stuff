#include <stdbool.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    bool isCommonLetter = true;
    short nLen = 0;
    char currentLetter;
    if(strsSize == 1)
        return strs[0];
    while(isCommonLetter){
        if(strs[0] != '\0')
            currentLetter = strs[0][nLen];
        if(strs[0] == '\0' && nLen == 0)
            return "";
        for(int i=0;i<strsSize;i++){
            if(strs[i][nLen] != currentLetter || strs[i][nLen] == '\0'){
                isCommonLetter = false;
                break;
            }
        }
        if(isCommonLetter) 
            nLen++;
    }
    char* ans = (char*)malloc((nLen + 1) * sizeof(char));
    for(int i=0;i<nLen;i++){
        ans[i] = strs[0][i];
    }
    ans[nLen] = '\0';
    return ans;
}