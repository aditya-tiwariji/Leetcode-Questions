class Solution {
public:
    static bool cmp(string str1,string str2)
    {
        return str1+str2 > str2+str1;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();

        vector<string>v;

        for(int i=0;i<n;i++)
        {
            string temp = to_string(nums[i]);
            v.push_back(temp);
        }

        sort(v.begin(),v.end(),cmp);

        string ans="";
        for(int i=0;i<n;i++)
        {
            ans += v[i];
        }

        return ans[0]=='0'? "0" : ans;
    }
};