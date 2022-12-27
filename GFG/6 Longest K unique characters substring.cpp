class Solution {
public:
    
    int longestKSubstr(string s, int k) {
        
        unordered_map<char, int> m; // Better than normal map
        
        int cnt = 0; // to store count of unique characters in window
        int ans = -1; // bcoz they said "If there is no possible substring then print -1."
        
        int j=0;
        for(int i=0; i<s.length(); i++) {
            
            m[s[i]]++; // In Map :  char -> key AND it's count int window -> value
            
            // if new entry in map, so it's a unique character
            if(m[s[i]] == 1) cnt++; 
            
            if(cnt == k) { // Given condition in Problem
                
                int size = i-j+1; // size of the longest possible substring
                ans = max(ans, size); // find maximum
                
            }
            else if(cnt > k) {
                
                // while loop -> until we have equal or less number of unique characters in window
                while(cnt > k) { 
                    m[s[j]]--; // Remove entry from map
                    
                    // If count of some character in window reduces to zero, then Reduce count of 'unique characters'
                    if(m[s[j]] == 0) cnt--;
                    
                    j++;
                }
            }
        }
        return ans;
    }
  
};
