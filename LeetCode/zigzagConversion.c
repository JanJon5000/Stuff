#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char* convert(char* s, int numRows) {
    if(numRows == 1)
        return s;
    int len = strlen(s);
    char* ans = malloc(len + 1);
    ans[len] = '\0';
    char reference[numRows][len + 1];
    memset(reference, 0, sizeof(reference));
    int i = 0;
    int j = 0, k = 0;
    while(s[i] != '\0'){
        while(s[i] != '\0' && j<numRows){
            reference[j][k] = s[i];
            j++; i++;
        }
        j-=2;k++;
        while(s[i] != '\0' && j>0){
            reference[j][k] = s[i];
            i++;j--;k++;
        }
    }
    i=0;
    for(int j=0;j<numRows;j++){
        for(int k=0;k<len + 1;k++){
            if(reference[j][k] == 44 || reference[j][k] == 46 || (reference[j][k] >= 65 && reference[j][k] <= 90) || (reference[j][k] >= 97 && reference[j][k] <= 122)){
                ans[i] = reference[j][k]; i++;
            }
        }
    }
    return ans;
}