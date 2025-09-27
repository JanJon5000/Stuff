#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char* addBinary(char* a, char* b) {
    int ansLen = strlen(a) > strlen(b) ? strlen(a)+1 : strlen(b)+1;
    char* ans = malloc((ansLen + 1) * sizeof(char));
    ans[ansLen] = '\0';
    char* shorter = malloc((ansLen+1) * sizeof(char));
    char* bigger = strlen(a) > strlen(b) ? a : b;
    int j = ansLen-2;
    int n = 0;
    if(strlen(a) > strlen(b))
        for(int i=strlen(b)-1;i>=0;i--){
            if(j>0){
                shorter[j] = b[i];
                j--;
            }
            else break;
        }
    else if(strlen(a) < strlen(b))
        for(int i=strlen(a)-1;i>=0;i--){
            if(j>0){
                shorter[j] = a[i];
                j--;
            }
            else break;
        }
    else
        for(int i=strlen(a)-1;i>=0;i--){
            shorter[j] = a[i];
            j--;
        }
    while(j>=0){
        shorter[j] = '0';
        j--;
    }

    int carry = 0;
    for(int i=strlen(bigger)-1;i>=0;i--){
        ans[i+1] = ((bigger[i]-48+shorter[i]-48+carry)%2)+48;
        carry = (bigger[i]-48+shorter[i]-48+carry) >= 2 ? 1 : 0;
        printf("%c + %c + %d = %c r.%d\n", bigger[i], shorter[i], carry, ans[i], carry);
    }
    ans[0] = carry + 48;

    if(carry != 1){
        for(int i=0;i<strlen(ans)-1;i++)
            ans[i] = ans[i+1];
        ans[strlen(ans)-1] = '\0';
    }
        
    return ans;
}

int main(){
    char a[] = "11010";
    char b[] = "11011";
    char* ans = addBinary(a, b);
    return 0;
}