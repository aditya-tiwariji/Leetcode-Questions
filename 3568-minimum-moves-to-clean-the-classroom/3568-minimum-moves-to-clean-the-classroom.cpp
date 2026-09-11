class Solution { 
public: 
using p=pair<int,pair<int,pair<int,pair<int,int>>>>; 

vector<vector<vector<int>>>v; 
vector<vector<int>>dir={{0,-1},{-1,0},{0,1},{1,0}}; 
 
    int minMoves(vector<string>& classroom, int energy) { 
               
               int n=classroom.size(); 
               int m=classroom[0].size();

               int cntL=0; 
               int sx=0; 
               int sy=0; 
 
             
               vector<vector<int>>id(n,vector<int>(m,-1));

               for(int i=0;i<n;i++) 
               { 
                   for(int j=0;j<classroom[i].size();j++) 
                   { 
                          if(classroom[i][j]=='L'){
                                 id[i][j]=cntL;
                                 cntL++;
                          }
                          else if(classroom[i][j]=='S'){ 
                                 sx=i; 
                                 sy=j; 
                          } 
                   } 
               } 
                   
               int fullMask=(1<<cntL)-1;

               v.assign(n,vector<vector<int>>(m,vector<int>(1<<cntL,-1)));    
               
               queue<p>q; 
 
               q.push({sx,{sy,{0,{energy,0}}}});//{x,y,mask,energy,steps} 
 
               while(!q.empty()){       
                         
                         int x=q.front().first; 
                         int y=q.front().second.first; 
                         int mask=q.front().second.second.first; 
                         int e=q.front().second.second.second.first; 
                         int steps=q.front().second.second.second.second; 
                         
                         q.pop(); 
 
                         if(mask==fullMask)
                             return steps; 
 
                         for(auto it:dir){ 
                                
                                int nx=x+it[0]; 
                                int ny=y+it[1]; 
 
                                if(nx<0||nx>=n||ny<0||ny>=m||classroom[nx][ny]=='X')
                                    continue; 

                                int nmask=mask;
                                int ne=e-1;

                                if(ne<0)
                                    continue;

                               
                                if(classroom[nx][ny]=='L'){
                                    nmask = mask | (1<<id[nx][ny]);
                                }

                               
                                if(classroom[nx][ny]=='R'){
                                    ne=energy;
                                }

                                
                                if(ne<=v[nx][ny][nmask])
                                    continue;

                                v[nx][ny][nmask]=ne;
                                 
                                q.push({nx,{ny,{nmask,{ne,steps+1}}}}); 
                         } 
               } 

               return -1; 
    } 
};