class Solution {
public:
    bool sumGame(string num) {
        
              int n=num.size();

              int cntL=0,cntR=0;
              int sumL=0,sumR=0;

              for(int i=0;i<n;i++){
                      if(i<n/2){
                           if(num[i]=='?')cntL++;
                           else sumL+=num[i]-'0';
                      }
                      else{
                          if(num[i]=='?')cntR++;
                          else sumR+=num[i]-'0';
                      }
              }
              if(sumL>sumR&&cntL>cntR)return true;
              if(sumR>sumL&&cntR>cntL)return true;

              int diff=abs(sumL-sumR);
              int cntD=abs(cntL-cntR);

              if(diff==0&&cntD==0)return false;
              if(diff<9&&cntD>0)return true;

               bool turn=1;
              while(cntD>0){
                   if(turn){
                       cout<<diff;
                       if(diff<9)return true;
                       cntD--;
                       if(cntD==0){
                           return true;
                       }
                       turn=!turn;
                   }
                   else{
                      diff-=9;
                      cntD--;
                      if(cntD==0){
                           if(diff>0)return true;
                           else return false;
                      }
                      turn=!turn;
                   }
              }

             
              return true;
                    
              

    }
};