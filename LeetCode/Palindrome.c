int isPalindrome(int x) {
    int copy = x;
    long maybePalindrome = 0;
    while(x > 0){
        maybePalindrome *= 10;
        maybePalindrome += x % 10;
        x /= 10;
    }
    if(maybePalindrome == copy)
        return 1;
    return 0;
}