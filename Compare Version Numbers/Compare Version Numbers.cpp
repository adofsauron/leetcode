/*

	Compare two version numbers version1 and version2.
	If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

	You may assume that the version strings are non-empty and contain only digits and the . character.
	The . character does not represent a decimal point and is used to separate number sequences.
	For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

	Here is an example of version numbers ordering:

	0.1 < 1.1 < 1.2 < 13.37

*/

/*
    比较版本号的大小
    从左到右依次比较被'.'分割成的区域，如果大小不等就直接返回结果，大小相同再比较下一个
    每个区域的字符串化成数字进行比较
*/

class Solution 
{
public:
    int compareVersion(string version1, string version2) 
    {
        int i = 0,j = 0;

        while(i < version1.size() || j < version2.size())
        {
            int num1 = 0,num2 = 0;

            while(i < version1.size() && version1[i] != '.')    
            	num1 = num1 * 10 + version1[i++] - '0';

            while(j < version2.size() && version2[j] != '.')    
            	num2 = num2 * 10 + version2[j++] - '0';

            i++;
            j++;

            if(num1 > num2)     
            	return 1;

            if(num1 < num2)     
            	return -1;
        }

        return 0;
    }
};

