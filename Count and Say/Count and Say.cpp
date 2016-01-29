/*

	The count-and-say sequence is the sequence of integers beginning as follows:
	1, 11, 21, 1211, 111221, ...

	1 is read off as "one 1" or 11.
	11 is read off as "two 1s" or 21.
	21 is read off as "one 2, then one 1" or 1211.
	Given an integer n, generate the nth sequence.

	Note: The sequence of integers will be represented as a string.

*/

class Solution 
{
public:
    string countAndSay(int n) 
    {
        string s[2];
        int cur = 0;
        s[cur] = "1";

        for(int i = 2; i <= n; i++)
        {
            s[cur^1] = "";

            for(int j = 0; j<s[cur].size(); j++)
            {
                int cnt = 0;
                int k;
                
                for( k=j ; j<s[cur].size() && s[cur][j] == s[cur][k]; k++)     
                	cnt++;
                
                j = k-1;
                s[cur^1] += static_cast<char>('0'+cnt);
                s[cur^1] += s[cur][j];
            }

            cur ^= 1;
        }

        return s[cur];
    }
};

