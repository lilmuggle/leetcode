class Solution {
public:
    string intToRoman(int num) {
        int i, res;
        string str;
        for(i = 1; i <= 1000; i *= 10) {
            res = num * i / 1000;
            num = num - res * 1000 / i;
            switch (res) {
            case 4:
                if(i == 10)
                    str += "CD";
                else if(i == 100)
                    str += "XL";
                else
                    str += "IV";
                break;
            case 9:
                if(i == 10)
                    str += "CM";
                else if(i == 100)
                    str += "XC";
                else
                    str += "IX";
                break;
            default:
                if(res < 4) {
                    for(; res > 0; res--) {
                        if(i == 1)
                            str += "M";
                        else if(i == 10)
                            str += "C";
                        else if(i == 100)
                            str += "X";
                        else
                            str += "I";
                    }
                }
                else {
                    if(i == 10)
                        str += "D";
                    else if(i == 100)
                        str += "L";
                    else
                        str += "V";
                    for(; res > 5; res--) {
                        if(i == 10)
                            str += "C";
                        else if(i == 100)
                            str += "X";
                        else
                            str += "I";
                    }
                }
                break;
            }
        }
        return str;
    }
};

//After improvement
public static String intToRoman(int num) {
    String M[] = {"", "M", "MM", "MMM"};
    String C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    String X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    String I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}
