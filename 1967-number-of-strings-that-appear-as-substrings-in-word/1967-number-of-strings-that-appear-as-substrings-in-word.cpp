class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
           
               // p->no of patterns ,l-->length of each pattern

                unordered_map<string,int>mpp;//O(p*l)  sc
                unordered_set<string>seen;//O(p*l)  sc

                for(auto it:patterns)mpp[it]++; // O(p*l)
                
                 int n=word.size();

                 string s="";
                 int cnt=0;
                 for(int i=0;i<n;i++){//O(n)
                       for(int j=i;j<n;j++){//O(n)
                             s+=word[j];
                             if(mpp.count(s)&&!seen.count(s)){//O(s.length)
                                cnt+=mpp[s];  
                                seen.insert(s);// mark vis  //O(n)
                             }
                       }
                       s="";
                 }

                 // overall tc->O(p*l+n3)

                 
                 return cnt;
                   
    }
};