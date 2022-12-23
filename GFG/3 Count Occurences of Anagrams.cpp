// Question Link : https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

class Solution{
public:

	int search(string pat, string txt) {
	    
	    int k = pat.length(); // Window Size
	    int n = txt.length();
	    
	    unordered_map<char, int> pattern, m;
	    
	    // count number of Occurences of each 'char' in string 'pat'
	    for(int i=0; i<k; i++) pattern[pat[i]]++;
	    
	    int count = pattern.size(); // to store total number of distinct elements
	    int ans = 0, i=0, j=0;
	    
	    // first sliding window
	    while(j-i+1 <= k) { // until window size equal to 'k'
	        
	        // Remove element from map (Bcoz currently it is present in window)
	        pattern[txt[j]]--;
	        
	        // Decrease the count of distinct elements
	        if(pattern[txt[j]] == 0) count--;
	        
	        j++;
	    }
	    
	    if(count == 0) ans++;
	   
	    // next sliding windows
	    while(j<n) { // traverse whole 'txt' string
	       
	        // Put element back into map (Bcoz currently it is not present in window)
	        pattern[txt[i]]++; 
	        // For New Entry in Map -> Increase the count of distinct elements
	        if(pattern[txt[i]] == 1) count++; 
	        
	        // Remove element from map (Bcoz currently it is present in window)
	        pattern[txt[j]]--;
	        // Decrease the count of distinct elements
	        if(pattern[txt[j]] == 0) count--; 
	        
	        if(count == 0) ans++; // Count than substring into ans
	        
	        j++; i++; // move sliding window forward
	    }
	    
	    return ans;
	}

};
