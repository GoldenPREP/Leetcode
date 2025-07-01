#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;  
        double median; 
        int s1 = nums1.size();
        int s2 = nums2.size();  
        int i = 0, j = 0;
        
        while(i < s1 && j < s2) 
        { 
            if(nums1.at(i) < nums2.at(j)) 
            { 
                result.push_back(nums1[i]);
                i++;
            } 
            else 
            { 
                result.push_back(nums2[j]); 
                j++;
            }
        } 

        while(i < s1) 
        { 
            result.push_back(nums1.at(i)); 
            i++; 
        }

        while(j < s2)
        { 
            result.push_back(nums2.at(j));
            j++;
        }

        // if size = 4 4 % 2 = 0: result.at(2) + result.at(1) = median 
        int rs = result.size();
        if(rs % 2 == 0) 
        { 
            median = (result.at((rs / 2)) + result.at((rs / 2) - 1))/2.0; 
        } 
        else 
        { 
            median = result.at(rs / 2);
        }
        
        return median;
        
    }
};