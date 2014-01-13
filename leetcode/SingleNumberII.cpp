class Solution {
public:
    int singleNumber(int A[], int n) {
        /*int zero, one, two, nzero, none, ntwo;
        zero = ~0;
        one = 0;
        two = 0;
        for (int i = 0; i < n; i++) {
            none = (zero & A[i]) | (one & ~A[i]);
            ntwo = (one & A[i]) | (two & ~A[i]);
            nzero = (two & A[i]) | (zero & ~A[i]);
            one = none;
            two = ntwo;
            zero = nzero;
        }*/
		int one, two, three;
        one = 0;
        two = 0;
        for (int i = 0; i < n; i++) {
            two |= one & A[i];
            one ^= A[i];
            three = ~(one & two);
            one &= three;
            two &= three;
        }
        return one;
    }
};
