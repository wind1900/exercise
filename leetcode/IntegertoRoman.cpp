class Solution {
public:
    string intToRoman(int num) {
        string a, b, c, d;
        string g[] = {"", "M", "MM", "MMM"};
        string h[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string i[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string j[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        a = g[num / 1000];
        num = num % 1000;
        b = h[num / 100];
        num = num % 100;
        c = i[num / 10];
        d = j[num % 10];
        return a+b+c+d;
    }
};
