/*
	Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

	The same repeated number may be chosen from C unlimited number of times.

	Note:
	All numbers (including target) will be positive integers.
	Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
	The solution set must not contain duplicate combinations.
	For example, given candidate set 2,3,6,7 and target 7, 
	A solution set is: 
	[7] 
	[2, 2, 3] 
*/
`
/*
    暴搜就能过了
*/


class Solution 
{
public:

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector< vector<int> > res;
        vector<int> tmp;
        dfs(0, 0, candidates, tmp, res, target);
        return res;
    }

    void dfs(int cur, int depth, vector<int> &a, vector<int> tmp, vector< vector<int> > &res, int target)
    {
        if(target == 0)
        {
            res.push_back(tmp);
            return ;
        }

        for(int i = cur; i < a.size(); i++)
        {
            if(target - a[i] < 0)    //两个剪枝，当前数大于目标值或当前数在该层已经被搜过要跳过
            	break;

            if(i != cur && a[i] == a[i-1])  
            	continue;

            if(tmp.size() == depth)     
            	tmp.push_back(a[i]);
            else    
            	tmp[depth] = a[i];

            dfs(i, depth + 1, a, tmp, res, target-a[i]);
        }
    }
};
