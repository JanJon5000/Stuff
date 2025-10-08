int lengthOfLastWord(char* s) {
    int last = 0;
    int counting = 0;
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == ' ' && counting != 0){
            last = counting;
            counting = 0;
        }else if(s[i] != ' ') counting++;        
        i++;    
    }
    last = counting == 0 ? last : counting;
    return last;
}