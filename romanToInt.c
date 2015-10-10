int romanToInt(char* s)
{
    int i, number;

    number = 0;
    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == 'I')
        {
            if(s[i + 1] != '\0' && s[i + 1] != 'I')
                number--;
            else
                number++;
        }
        else if(s[i] == 'V')
            number += 5;
        else if(s[i] == 'X')
        {
            if(s[i + 1] != '\0' && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                number -= 10;
            else
                number += 10;
        }
        else if(s[i] == 'L')
            number += 50;
        else if(s[i] == 'C')
        {
            if(s[i + 1] != '\0' && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                number -= 100;
            else
                number += 100;
        }
        else if(s[i] == 'D')
            number += 500;
        else if(s[i] == 'M')
            number += 1000;
    }
    return number;
}
