// Question Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
      
    // This is sliding window question (type : variable window) 
    int lengthOfLongestSubstring(string s) {
        
        // we are using map of <string, int> instead of <char, int>
        // bcoz in 'Constraints' They said : 
        // s consists of English letters, 'digits', 'symbols' and spaces.
        // and for 'digits', 'symbols' we cant use 'char' so we are using 'string' 
        unordered_map<string, int> m;
        int maxLength = 0;

        int i=0, j=0;
        while(j<s.length()) {
            
            // For Taking entry of 'char' in map as a 'string'
            // we use 'substr()' function
            string s2 = s.substr(j, 1); // using 'j' pointer
            m[s2]++;
            
            // If All Elements are unique
            if(m.size() == j-i+1) {
                maxLength = max(maxLength, j-i+1);                
            }
            // Else If All Elements are not unique
            else if(m.size() < j-i+1) {
                
                // deleting entry of elements from map
                // The elements which are present at left side of window
                while(m.size() < j-i+1) {
                    string temp = s.substr(i, 1); // using 'i' pointer
                    m[temp]--;
                    i++; // increase 'i' pointer
                    
                    // if count of element in window reduces to 'zero'
                    // delete entry from map (so that it will reduce map's size)
                    if(m[temp] == 0) m.erase(temp); 
                }
            }
            j++; // increase 'j' pointer
        }
        return maxLength;
    }
    
};
