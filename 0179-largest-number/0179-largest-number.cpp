class Solution {
public:


string fun(string a, string b) {

    if (a == "") return b;
    if (b == "") return a;

    int i = 0;
    int j = 0;
    int n = a.size();
    int m = b.size();

    // Compare a+b and b+a using your character comparison style
    while (i < n + m && j < n + m) {

        char x, y;

        // Character from a+b
        if (i < n)
            x = a[i];
        else
            x = b[i - n];

        // Character from b+a
        if (j < m)
            y = b[j];
        else
            y = a[j - m];

        if (x != y) {
            if (x > y) {
                return a + b;
            }
            else {
                return b + a;
            }
        }

        i++;
        j++;
    }

    return a + b;
}


string largestNumber(vector<int>& nums) {

    int n = nums.size();

    vector<string> arr;

    for (int i = 0; i < n; i++) {

        string s = to_string(nums[i]);

        bool inserted = false;

        // Find correct position for s
        for (int j = 0; j < arr.size(); j++) {

            // Your fun() tells us which concatenation is larger
            if (fun(s, arr[j]) == s + arr[j]) {
                arr.insert(arr.begin() + j, s);
                inserted = true;
                break;
            }
        }

        if (!inserted) {
            arr.push_back(s);
        }
    }

    string p = "";

    for (int i = 0; i < arr.size(); i++) {
        p += arr[i];
    }

    if (p[0] == '0') return "0";

    return p;
}


};
