// Question Link : https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int N){
        
        long sum = 0;
        long maxSum = 0;
        
        int rep = k;
        int i = 0;
        while(rep--) {
            sum += arr[i];
            i++;
        }
        
        maxSum = sum;
        
        for(int j=i; j<N; j++) {
            sum -= arr[j-k];
            sum += arr[j];
            
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
