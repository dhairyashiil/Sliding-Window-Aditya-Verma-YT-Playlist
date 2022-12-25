/*

Problem Description:

Given an array containing N positive integers and an integer K. 
Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.

For Input:
1
7 5
4 1 1 1 2 3 5

your output is: 
4 

*/

class Solution {
public:
  
    int lenOfLongSubarr(int arr[], int n, int k) 
    { 
        int i=0;
        int j=0;
        
        long long sum = 0;
        int maxSize = 0;
        while(j<n) {
            
            sum += arr[j];
            
            if(sum < k) {
                j++;
            }
            else if (sum > k) {
                
                while(sum > k) {
                    sum -= arr[i];
                    i++;
                }
                j++;
            }
            else if (sum == k) {
                maxSize = max(maxSize, j-i+1);
                j++;
            }
            
        }
        return maxSize;
    } 

};
