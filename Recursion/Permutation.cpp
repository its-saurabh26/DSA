#include<bits/stdc++.h>
using namespace std;

void  solve(vector<int>nums,vector<vector<int>>& ans,int index){

    // base case 
    if(index >= nums.size()){
    ans.push_back(nums);
    return; 
    }

    for(int j  = index;j <nums.size();j++ ){
        swap(nums[index],nums[j]);
        solve(nums,ans,index+1);

        // backTrack
        swap(nums[index],nums[j]);
    }
}


int main(){
vector<int> nums ={1,2,3};
vector<vector<int>>ans;
int index = 0;
solve(nums,ans,index);

    return 0;
}