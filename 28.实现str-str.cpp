
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现strStr()
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len2 = needle.length();
        if (len2 == 0) {
            return 0;
        }
        int len1 = haystack.length();

        for (int i = 0; i <= (len1 - len2); i++) {
            int j = 0;
            for (; j < len2; j++) {
                if (haystack[i+j] != needle[j]) {
                    break;
                } 
            }
            if (j == len2) {
                return i;
            }
        }
        return -1;
    }
};

void func() {
    ClassA a;
    ClassA *p = new ClassA;
}

