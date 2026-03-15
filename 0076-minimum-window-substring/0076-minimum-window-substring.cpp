#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();

        unordered_map<char,int> mpp;
        unordered_map<char,int> cpp;

        for(auto it : t)
            cpp[it]++;

        int i = 0;
        int j = 0;

        int start = 0;
        int mini = INT_MAX;

        while(j < n){
            mpp[s[j]]++;

            bool f = false;

            
            for(auto &it : cpp){
                char ch = it.first;

                if(mpp[ch] < cpp[ch]){
                    f = true;
                    break;
                }
            }

            if(f){
                j++;
            }
            else{
                // shrink window
                while(i <= j){

                    bool breakFlag = false;

                    mpp[s[i]]--;

                    for(auto &it : cpp){
                        char ch = it.first;

                        if(mpp[ch] < cpp[ch]){
                            breakFlag = true;
                            break;
                        }
                    }

                    if(breakFlag){
                        if(j - i + 1 < mini){
                            mini = j - i + 1;
                            start = i;
                        }

                        j++;
                        i++;
                        break;
                    }

                    i++;
                }
            }
        }

        if(mini == INT_MAX) return "";
        return s.substr(start, mini);
    }
};