class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
           int n=moves.size();

           int cntL=count(moves.begin(),moves.end(),'L');
           int cntR=count(moves.begin(),moves.end(),'R'); 
           int cnt_=count(moves.begin(),moves.end(),'_');

           int diff=abs(cntL-cntR);
           return diff+cnt_;
    }
};