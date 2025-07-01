#include <bits/stdc++.h>
using namespace std;  

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {  
        set<char> result; 
        int l = 0; 
        int maxlen = 0;
        for(int r = 0; r < s.length(); r++)
        { 
            while(result.contains(s.at(r)))
            { 
                result.erase(s.at(l)); 
                l++;
            }
            result.insert(s.at(r));
            maxlen = max(maxlen, (r - l)+1);

        }
        return maxlen;
    }
};