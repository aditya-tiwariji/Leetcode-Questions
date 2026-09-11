class Solution {
public:
    int totalNumbers(vector<int>&digits) {
        
          set<int>seen;
          int n = digits.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i != j && i != k && j != k) {
                        if (digits[i] != 0) {
                            if (digits[k] % 2 == 0) {
                                int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                                seen.insert(number);
                            }
                        }
                    }
                }
            }
        }

       return seen.size();

         

        

    }
};