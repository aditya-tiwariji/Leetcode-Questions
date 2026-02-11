class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
             int n=players.size();
                 int m=trainers.size();

                 if(m==0)return 0;

                 sort(players.begin(),players.end());
                 sort(trainers.begin(),trainers.end());

                
                 int j=m-1;
                 int cnt=0;
                 for(int i=n-1;i>=0;i--)
                 {
                        if(players[i]<=trainers[j]){
                              cnt++;
                              j--;
                        }

                        if(j<0)return cnt;
                 }

                 return cnt;
    }
};