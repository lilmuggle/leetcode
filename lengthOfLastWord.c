int lengthOfLastWord(char* s) {
    int last = 0, len = 0, i = 0;

    while(s[i])
    {
        if(s[i++] != ' ')
            last = ++len;
        else
            len = 0;
    }
    return last;
}
