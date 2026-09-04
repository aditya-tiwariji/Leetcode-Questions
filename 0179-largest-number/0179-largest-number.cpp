class Solution {
public:


// Your fun() idea:
// Decide which string should come first.
bool fun(string a, string b) {

    string x = a + b;
    string y = b + a;

    if (x > y)
        return true;   // a should come before b

    return false;      // b should come before a
}

string largestNumber(vector<int>& nums) {

    int n = nums.size();

    // Keep numbers separate
    vector<string> arr;

    for (int i = 0; i < n; i++) {
        arr.push_back(to_string(nums[i]));
    }

    // Arrange using your fun() comparison
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            // If arr[j] should NOT come before arr[j+1]
            if (!fun(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    // Now merge everything
    string p = "";

    for (int i = 0; i < n; i++) {
        p += arr[i];
    }

    // Handle cases like [0,0]
    if (p[0] == '0')
        return "0";

    return p;
}


};
