class Solution {
public:
    bool judgeCircle(string moves) {
           
             map<char,int>mpp;
             for(auto it:moves)mpp[it]++;
             if(mpp['U']==mpp['D']&&mpp['L']==mpp['R'])return true;
             return false;
    }
};