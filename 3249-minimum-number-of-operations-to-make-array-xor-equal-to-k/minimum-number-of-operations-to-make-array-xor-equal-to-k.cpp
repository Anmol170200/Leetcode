class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int finalXor = 0;
        for(int n : nums)
            finalXor ^= n;
        int cnt = 0;
        while(k || finalXor){
            if((k%2) != (finalXor % 2)) cnt++;
            k /= 2;
            finalXor /= 2;
        }
        return cnt;
    }
};