#include <string.h>
int strStr(char* haystack, char* needle) {
    if(strlen(needle) > strlen(haystack))
        return -1;
    int needleLen = strlen(needle);
    int haystackLen = strlen(haystack);
    int firstOcc = -1;
    int i, j = 0;
    short flag = 1;
    while(*(haystack + i) != '\0'){
        if(haystackLen - i < needleLen)
            break;
        flag = 1;
        j = 0;
        while(*(needle + j) != '\0' && *(haystack + i + j) != '\0'){
            if(*(needle + j) != *(haystack + i + j)){
                flag = 0;
                break;
            }
            j++;
        }
        if(flag){
            firstOcc = i;
            break;
        }
        i++;
    }
    return firstOcc;
}