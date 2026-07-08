class Solution {
public:
    bool isValid(string s) {
        
            

            stack<char>st;
            
           for(auto it:s){
                if(it=='('||it=='['||it=='{')st.push(it);
                else{

                    if(st.empty())return false;

                    char a=st.top();
                    char b=it;

                    if(b==')'){
                          if(a=='(')st.pop();
                          else return false;
                    }
                    else if(b==']'){
                          if(a=='[')st.pop();
                          else return false;
                    }
                    else{
                          if(b=='}'){
                              if(a=='{')st.pop();
                              else return false;
                          }
                    }
                }
           }

           if(st.empty())return true;
           return false;
    }
};