class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> ans;

        string l = to_string(low);
        int len = l.length();

        string h = to_string(high);

        string s = "";
        for (int i = 1; i <= len; i++)
            s += (i + '0');

        while (true) {

            int x = stoi(s);

            if (x >= low && x <= high)
                ans.push_back(x);

            if (x > high)
                break;

            if (s[len - 1] == '9') {

                len++;

                
                if (len > h.size() || len > 9)
                    break;

                s = "";
                for (int i = 1; i <= len; i++)
                    s += (i + '0');
            }
            else {
                for (int i = 0; i < len; i++)
                    s[i]++;
            }
        }

        return ans;
    }
};