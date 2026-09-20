class Solution { 
public: 
    bool isPalindrome(string s) { 
         
        stringstream ss(s); 
 
        string word; 
        vector<char> ans; 
 
        while(ss >> word) { 
                    
            for(auto it : word) { 
               

                if(isalnum(it)){
                     it = tolower(it);
                     ans.push_back(it);
                }
            }
        }

        int i = 0;
        int j = ans.size() - 1;

        while(i <= j) {
                   
            if(ans[i] != ans[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};