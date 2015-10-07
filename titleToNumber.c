int titleToNumber(char* s) {
    int i, n, number;

    i = number = 0;
    while(s[i] != '\0')
    {
        number = number * 26 + s[i] - 64;
        i++;
    }
    return number;
}
