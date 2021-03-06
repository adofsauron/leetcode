/*

	Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

	Ensure that numbers within the set are sorted in ascending order.


	Example 1:

	Input: k = 3, n = 7

	Output:

	[[1,2,4]]

	Example 2:

	Input: k = 3, n = 9

	Output:

	[[1,2,6], [1,3,5], [2,3,4]]

*/

/*
    和I、II一样，暴搜就能过了
*/


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        int a[9] = {1,2,3,4,5,6,7,8,9};
        int tmp[9];
        vector<vector<int> > res;
        dfs(0,0,k,a,tmp,res,n);
        return res;
    }
    
    void dfs(int cur, int depth, int k, int* a, int *tmp, vector<vector<int> > &res, int target)
    {
        if(depth == k)
        {
            if(target == 0)
            {
                vector<int> t;
                
                for(int i = 0;i < k;i++)    
                	t.push_back(tmp[i]);
                
                res.push_back(t);
            }
            return ;
        }

        for(int i = cur;i < 9;i++)
        {
            if(target - a[i] < 0)   
            	break;
            
            tmp[depth] = a[i];
            dfs(i + 1,depth + 1,k,a,tmp,res,target - a[i]);
        }
    }
};

