/*

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive. For example, given the range [5, 7], you should return 4. 

*/

/*
    仔细想想我们只要找m和n的最高不同位bit-1就可以了
    因为n和m之间一定会出现一个0~bit-1位都是0的数
    那么答案就是bit位以下的都是0，bit位及以上的和m,n一样
*/

class Solution 
{
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        int bit = 0;

        while(m != n)
        {
            m = m >> 1;
            n = n >> 1;
            bit++;
        }

        return m << bit;
    }
};


