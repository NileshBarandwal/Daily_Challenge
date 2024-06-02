# C code

void reverseString(char* s, int sSize) {
    for(int i = 0; i<sSize/2; i++){
        int temp = s[i];
        s[i] = s[sSize - i - 1 ];
        s[sSize - i - 1] = temp;
    }
}