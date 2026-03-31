class Solution {
public:
    string generateString(string str1, string str2) {
              int n=str1.size();
              int m=str2.size();

              int N=n+m-1;

              string Word(N,'$');
              // step1 : fill 'T' 
              for(int i=0;i<n;i++)
              {
                 if(str1[i]=='T'){// fill with str2
                          int k=i;
                          for(int j=0;j<m;j++)
                          {
                               if(Word[k]!='$'&&Word[k]!=str2[j])return "";

                               Word[k]=str2[j];
                               k++;
                          }
                 }
              }


              // step 2:fill remaining with 'a'

              vector<bool>canChange(N,false);

              for(int i=0;i<N;i++)
              {
                   if(Word[i]=='$'){
                          Word[i]='a';
                          canChange[i]=true;
                   }
              }
              // step3 : check for 'F'

              for(int i=0;i<n;i++)
              {
                     if(str1[i]=='F'){

                            string sub=Word.substr(i,m);
                          
                            if(sub==str2){
                                    bool ok=false;
                                    for(int k=i+m-1;k>=i;k--)
                                    {
                                            if(canChange[k]){
                                                   Word[k]='b';
                                                   ok=true;
                                                   break;
                                            }
                                    }
                                     if(!ok)return "";
                            }
                                
                     }
              }

              return Word;





    }
};