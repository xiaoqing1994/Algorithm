#include<iostream>
#include<vector>
#include<limits>
#include<cmath>
using namespace std;

//----- The first solution used recursion, but time-consuming---
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int S) {
//         int ways =0;
//         s = S;
//         vector<int> copy(nums);
//         int num = copy.front();
//         ways += DFS(copy, num, 1);
//         // cout<<"ways = "<<ways<<endl;
//         ways += DFS(copy, -num, 1);
//         return ways;
//     }
//
//     int DFS(vector<int> nums, int sum, int ind){
//         if(ind == nums.size()){
//             if(sum ==s){
//                 // cout<<"return 1"<<endl;
//                 return 1;
//             }
//             else return 0;
//         }
//         else if(ind < nums.size()){
//             int num = nums[ind];
//             int leftdepth = DFS(nums, sum+num, ind+1);
//             // cout<<sum<<" turn right"<<endl;
//             int rightdepth = DFS(nums, sum-num, ind+1);
//
//             return leftdepth + rightdepth ;
//         }
//     }
// private:
//     int s;
// };

/*---------Use the dynamic program---------*/
int findTargetSumWays(vector<int>& nums, int s) {
   int sum = accumulate(nums.begin(), nums.end(), 0);
   return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1);
}

int subsetSum(vector<int>& nums, int s) {
  int dp[s + 1] = { 0 };
  dp[0] = 1;
  for (int n : nums)
     for (int i = s; i >= n; i--){
         dp[i] += dp[i - n];
         // cout<<"i is " <<i <<" "<<dp[i]<<endl;
     }
  return dp[s];
}

int main(){
  vector<int> nums{33,36,38,40,25,49,1,8,50,13,41,50,29,27,18,25,37,8,0,48};
  int s = 0;
  Solution so;
  int result = so.findTargetSumWays(nums,s);
  cout<<"The result is "<<result<<endl;
  return 0;
  system("pause");
}
