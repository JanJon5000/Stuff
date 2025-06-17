#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000
int romanSign(char sign){
    switch (sign){
    case 'I':
        return I;
    case 'X':
        return X;
    case 'V':
        return V;
    case 'C':
        return C;
    case 'D':
        return D;
    case 'M':
        return M;  
    case 'L':
        return L; 
    default:
        return 0;
    }
}

int romanToInt(char* s) {
    int ans = 0;
    char prevSign = '0';
    short i = 0;
    while(*s != '\0'){
        if(romanSign(*s)>romanSign(prevSign)){
            ans += romanSign(*s) - 2*romanSign(prevSign);
        }else{
            ans += romanSign(*s);
        }
        prevSign = *s;
        *s++;
    }
    return ans;
}
