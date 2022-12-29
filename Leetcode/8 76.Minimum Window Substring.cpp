# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
- Sliding Window (Type : variable window)

# Approach
<!-- Describe your approach to solving the problem. -->
##### ***✅ Use of unordered map***
- Traverse 't' and find the count of all characters

##### ***✅ Use of 'startIndex' and 'endIndex' variable***
- we are storing start and end indexes of answer string
- to later on return the string

##### ***✅ Use of 'size' and 'minSize' variable***
- To find minimum window substring, 
- We have to compare between sizes

##### ***✅ Use of 'Bool Flag' variable***
- 1 :-
- If here 'flag == false', means we never actually got answer window
- so because of that, now the valuse in 'startIndex', 'endIndex' are
- 0 and 0 (The values they are intialized with) so return empty string
- 2 :-
- Else here 'flag == true' means we actually got answer window
- so use 'startIndex' and 'endIndex' to find Answer substring

***If you find this helpful, Please Upvote 🔼
Thank You !***

### ***C++ Code :***
```
class Solution {
public:
    
    string minWindow(string s, string t) {
        
        // Base Case
        if(s.length() < t.length()) return "";
        
        unordered_map<char, int> m;
        for(int i=0; i<t.length(); i++) m[t[i]]++;
        int count = m.size();
        
        int startIndex = 0, endIndex = 0;
        bool flag = false;
        
        int size;
        int minSize = INT_MAX;
        
        int i=0, j=0;
        while(j<s.length()) {
            
            // if(m[s[j]] > 0) { // Dont check like this (in this Que)
            // bcoz here, we are going to use 'negative count' of key as well
            if( m.find(s[j]) != m.end() ) { // check like this
                m[s[j]]--; // using 'j' pointer
                if(m[s[j]] == 0) count--;
            }
            
            if(count == 0) {
                
                while(count == 0) {
                    if( m.find(s[i]) != m.end() ) { // Check with 'i' pointer
                        m[s[i]]++;
                        if(m[s[i]] == 1) count++;
                    }
                    i++;
                }
                
                size = j-i; // Actually it is : size = j-(i-1)+1;
                
                // change value of 'startIndex' & 'endIndex' only when
                // 'size' is less than 'minSize'
                if(size < minSize) {
                    minSize = size;
                    startIndex = i-1;
                    endIndex = j;
                    
                    flag = true;
                }
            }
            j++;
        }
        
        if(flag == false) return "";
        
        return s.substr(startIndex, endIndex-startIndex+1);
    }
};

```
