// Question Link : https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k) {
        
        vector<long long> ans;
        queue<long long> q; // to store only negative elements 'present' in 'Window'
        
        // first sliding window
        long long int i = 0, j = 0;
        while(j-i+1 <= k) { // until window size equal to 'k'
            if(arr[j] < 0) q.push(arr[j]);
            j++;
        }
        
        if(q.empty()==true) ans.push_back(0); // if queue is empty, push '0' in ans
        else ans.push_back(q.front()); // else push front element of queue
        
        // next sliding windows
        while(j<n) { // traverse whole array
            
            if(arr[j] < 0) q.push(arr[j]); // push negative elements into queue
            j++; i++; // increse both i and j to maintain window size equal to 'k'
            
            // if element at the top queue is not a part of the current window anymore
            if(arr[i-1] == q.front()) q.pop(); // then remove it from queue
            
            if(q.empty()==true) ans.push_back(0); // if queue is empty, push '0' in ans
            else ans.push_back(q.front()); // else push front element of queue
        }
        return ans;
 }
