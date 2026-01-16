class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        int extra = 0;
        int num = (a | b )^ c;
        for (int i = 0; i < 31; i++) {
            if (num & (1 << i)) {
                count++;
            }
        }
        for (int i = 0; i < 31; i++) {
            if ((num&(a&b)) & (1 << i)) {
                extra++;
            }
        }
        return count+extra;
    }
    };