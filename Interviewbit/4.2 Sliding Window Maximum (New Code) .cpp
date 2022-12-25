
// Question Link : https://www.interviewbit.com/problems/sliding-window-maximum/
// Code Like Aditya Versam Said in his Video

#include <bits/stdc++.h> // Adding this Bcoz of 'list'
vector<int> Solution::slidingMaximum(const vector<int> &nums, int k) {
        
    vector<int> ans;
    list<int> l;
    int i=0;
    int j=0;
    
    if (k>nums.size()) { // edge case
        ans.push_back(*max_element(l.begin(),l.end()));
        return ans;
    }
    
    while (j<nums.size()) {
        
        // calculations (Part 1)
        while(l.size()>0 && l.back() <nums[j]) {
            l.pop_back();
        }
        l.push_back(nums[j]);
        
        // if condtion when window size less than k (Part 2)
        if ((j-i+1)<k) 
            j++;
        else if (j-i+1==k) // if condtion when window size equal to k (Part 3)
        {
            // ans (Part 3.1)
            ans.push_back(l.front()); 
            
            // remove calculations of elements who are not present in window anymore (3.2)
            if (l.front()==nums[i]) l.pop_front();
            
            // slide the window (Part 3.3)
            i++;
            j++;
        }
        
    }
    return ans;
}
