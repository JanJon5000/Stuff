#include <string.h>
#include <stdio.h>
char* longestPalindrome(char* s) {
    int len = strlen(s);
    int msLen = len*2+4;
    char* ms = malloc(msLen);
    int i=0, j=1;
    ms[0] = '@';
    ms[msLen-1] = '\0';
    ms[msLen-2] = '$';
    while(s[i] != '\0'){
        ms[j] = '#';
        ms[++j] = s[i];
        i++;
        j++;
    }
    ms[j] = '#';
    int r= 0, l = 0;
    int *p = calloc(msLen-1, sizeof(int));
    for(int i=1;i<msLen-2;++i){
        int mirror = l + r - i;
        if (i < r)
            p[i] = r - i > p[mirror] ? p[mirror] : r - i;
        while(ms[i + 1 + p[i]] == ms[i - 1 - p[i]])
            ++p[i];
        if(i + p[i] > r){
            l = i - p[i];
            r = i + p[i];
        }
    }
    int start = 0;
    int maxLen = 0;
    for(int i=0;i<len;i++){
        int oddLen = getLongest(i, 1, p);
        if (oddLen > maxLen) {
            maxLen = oddLen;
            start = i - maxLen / 2;
        }

        int evenLen = getLongest(i, 0, p);
        if (evenLen > maxLen) {
            maxLen = evenLen;
            start = i - maxLen / 2 + 1;
        }
    }
    char* ans = malloc(maxLen);
    j = 0;
    for(int i=start;i<maxLen;i++){
        ans[j] = s[i];
        j++;
    }
    return ans;  
}

int getLongest(int cen, int odd, int* p) {
        int pos = 2 * cen + 2 + !odd;
        return p[pos];
}