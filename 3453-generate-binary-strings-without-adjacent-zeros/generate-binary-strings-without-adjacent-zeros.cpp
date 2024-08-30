class Solution {
public:
    vector<string> validStrings(int n) {
        if(n == 1)
        {
            return {"0","1"};
        }
        vector<string> v;
        vector<string> prev = validStrings(n - 1);

        for(string& str : prev)
        {
            if(str.back() == '1')
            {
                v.push_back(str + "0");
            }
            v.push_back(str + "1");
        }
        return v;
    }
};