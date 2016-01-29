/*

	Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

	Each number in C may only be used once in the combination.

	Note:
	All numbers (including target) will be positive integers.
	Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
	The solution set must not contain duplicate combinations.
	For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
	A solution set is: 
	[1, 7] 
	[1, 2, 5] 
	[2, 6] 
	[1, 1, 6] 

*/

/*
    和I一样，暴搜就能过了
*/


class Solution 
{
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());

        vector<vector<int> > res;
        vector<int> tmp;
        
        dfs(0, 0, candidates, tmp, res, target);

        return res;
    }

    void dfs(int cur,int depth,vector<int> &a,vector<int> tmp,vector<vector<int> > &res,int target)
    {
        if(target == 0)
        {
            res.push_back(tmp);
            return ;
        }

        for(int i = cur;i < a.size();i++)
        {
            if(target - a[i] < 0)    //两个剪枝，当前数大于目标值或当前数在该层已经被搜过要跳过
            	break;
            
            if(i != cur && a[i] == a[i-1])  
            	continue;

            if(tmp.size() == depth)     
            	tmp.push_back(a[i]);
            else    
            	tmp[depth] = a[i];
            
            dfs(i + 1, depth + 1, a, tmp, res, target - a[i]);   //避免重复所以这里是i + 1
        }
    }
};

