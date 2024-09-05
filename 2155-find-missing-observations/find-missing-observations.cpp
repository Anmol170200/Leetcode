class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), s = 0;
        for( auto i : rolls ){
            s += i;
        }
        
        int total = mean*(n+m);
        int x = total - s, p = 6*n;
        
        if( (x < n) || ( x > p ) ){
            return {};
        }
        
        vector<int> ans( n, 1 );
        x -= n;
        while( x ){
            for( int i = 0 ; (x > 0 ) && i < n ; i++ ){
                if( x >= 5 ){
                    ans[i] += 5;
                    x -= 5;
                }
                else{
                    ans[i] += x;
                    x = 0;
                    break;
                }
            }
        }
        
        return ans;
    }
};