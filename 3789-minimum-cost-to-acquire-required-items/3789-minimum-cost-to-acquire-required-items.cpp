class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
             long long  mini=min(need1,need2);

            long long  ans=(long long )mini*(min(costBoth,cost1+cost2));

             ans+=(long long)(need1-mini)*(min(costBoth,cost1));
             ans+=(long long )(need2-mini)*(min(costBoth,cost2));


             return ans;
    }
};