class Solution {
public:
    bool parseBoolExpr(string expression) {
            
                int n=expression.size();

                stack<char>st;

                for(int i=0;i<expression.size();i++)
                {
                      if(expression[i]==')'){
                          
                             int cntf=0;
                             int cntt=0;
                               while(!st.empty()&&st.top()!='&'&&st.top()!='|'&&st.top()!='!'){
                                        
                                          if(st.top()=='f')cntf++;
                                          if(st.top()=='t')cntt++;
                                          st.pop();
                               }

                               if(!st.empty()&&st.top()=='&'){
                                   if(cntf>0){
                                       st.pop();
                                       st.push('f');
                                   }
                                   else{
                                     st.pop();
                                     st.push('t');
                                   }
                               }
                               else if(!st.empty()&&st.top()=='|'){
                                   if(cntt>0){
                                      st.pop();
                                      st.push('t');
                                   }
                                   else{
                                     st.pop();
                                     st.push('f');
                                   }
                               }
                               else{
                                   if(!st.empty()){
                                    st.pop();
                                    if(cntt>0){
                                          st.push('f');
                                    }
                                    else{
                                         st.push('t');
                                    }
                                   }
                                    
                               }
                      }
                      else{
                         st.push(expression[i]);
                      }
                }

                if(!st.empty()&&st.top()=='f')return false;
                return true;
    }
};       