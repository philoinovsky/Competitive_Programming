#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        vector<int> presum(nums.size()+1,0);
        for(int i = 0; i < nums.size(); i++){
            presum[i+1] = presum[i] + nums[i];
        }
        int right = 0;
        map<int,int> m;
        m[0] = 0;
        int cnt = 0;
        for(int i = 1; i < nums.size() + 1; i++){
            if(m.find(presum[i]-target) != m.end()){
                if(m[presum[i]-target] > right){
                    cnt++;
                } 
            }
            m[presum[i]] = i;
        }
        return cnt;
    }
};

int main(){
    Solution sol;
    vector<int> v = {1,1,1,1,1};
    sol.maxNonOverlapping(v,2);
    return 0;
}