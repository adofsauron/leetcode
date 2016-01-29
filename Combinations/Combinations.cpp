/*

	Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

	For example,
	If n = 4 and k = 2, a solution is:

	[
	  [2,4],
	  [3,4],
	  [2,3],
	  [1,2],
	  [1,3],
	  [1,4],
	]

*/

/*
    比较基础的题，直接dfs k层就可以了，如果在当前层发现剩下的数凑不齐k个就回溯
*/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) 
    {
        vector<vector<int> > res;
        int *a = new int[k];
        dfs(res,a,0,k,0,n);
        delete [] a;
        return res;
    }

    void dfs(vector<vector<int> > &res,int *a,int depth,int k,int cur,int n)
    {
        if(depth == k)
        {
            vector<int> tmp;
            
            for(int i = 0;i < k;i++)    
            	tmp.push_back(a[i]);
            
            res.push_back(tmp);
            return ;
        }

        for(int i = cur;i < n;i++)
        {
            if(n - cur < k - depth)      //剩下的数凑不齐k个，回溯
            	return ;   

            a[depth] = i + 1;
            dfs(res, a, depth + 1, k, i + 1, n);
        }
    }
};
