// Question Link : https://www.interviewbit.com/problems/sliding-window-maximum/

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {

    vector<int> res;
    if(B== 0)   return res;

    map<int, int> m;
    int n = A.size();
    int maxi = INT_MIN;

    for(int i =0;i<B;i++){
        m[A[i]]++;
        maxi = max(maxi, A[i]);
    }
    res.push_back(maxi);

    for(int i=1;i<=n-B;i++){
        m[A[i-1]]--;
        if(m[A[i-1]] == 0) m.erase(A[i-1]);
        m[A[B+i-1]]++;

        auto it = m.rbegin();
        res.push_back(it->first);
    }

    return res;
}

/*
// wrong output :


vector<int> Solution::slidingMaximum(const vector<int> &arr, int k) {
    
    vector<int> ans;
    int n = arr.size();
    
    int i=0;
    int j=0;
    queue<int> q;
    
    int rep = k;
    while(rep--) {
        while( q.size() > 0 && q.front() < arr[j] ) {
            q.pop();
        }
        q.push(arr[j]);
        
        j++;
    } 
    ans.push_back(q.front());
    
    while(j<n) {
        while( q.size() > 0 && q.front() < arr[j] ) {
            q.pop();
        }
        q.push(arr[j]);
        
        if(q.front() == arr[i]) { // (Part 3.3)
            q.pop();
        }
        i++;
        j++;
        
        ans.push_back(q.front());
    }
    
    
    // while(j<n) {
        
    //     // calculations (Part 1)
    //     while( q.size() > 0 && q.front() < arr[j] ) {
    //         q.pop();
    //     }
    //     q.push(arr[j]);
        
    //     // if condtion when window size less than k (Part 2)
    //     if( j-i+1 < k ) {
    //         j++;
    //     }
        
    //     // if condtion when window size equal to k (Part 3)
    //     if( j-i+1 == k ) {
            
    //         // ans (Part 3.1)
    //         ans.push_back(q.front());
            
    //         // slide the window (Part 3.2)
    //         i++;
    //         j++;
            
    //         // remove calculations of elements who are not present in window anymore
    //         if(q.front() == arr[i-1]) { // (Part 3.3)
    //             q.pop();
    //         }
    //     }
    // }
    
    return ans;
}

*/
