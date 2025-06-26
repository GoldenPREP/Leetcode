#include <iostream> 
#include <vector>
using namespace std; 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    { 
        vector<int> indices = {};
        for(int i = 0; i < nums.size(); i++) 
        { 
            for(int j = 0; j < nums.size(); j++ ) 
            {
                if(i != j && ((nums.at(i) + nums.at(j)) == target)) 
                {
                    indices.push_back(i);
                    indices.push_back(j); 
                    return indices;
                } 
            }
        }  
        throw runtime_error("no numbers match the target");
    }
}; 

int main() 
{  
//Test case 1
//Expected output: [0,1]
   
    vector<int> answer = {2,7,11,15}; 
    int target = 9;

//Test case 2
//Expected output: [1,2]
/*   
    vector<int> answer = {3,2,4}; 
    int target = 6; 
*/
//Test case 3 
//Expected output: [0,1]
/*  
    vector<int> answer = {3,3}; 
    int target = 6;
*/
 
  Solution Result;
    vector<int> result = Result.twoSum(answer, target);
    cout << "[";
    for(int i = 0; i < result.size(); i++) 
    { 
        cout << result.at(i); 
        if(i != result.size()-1) cout << ",";
    }
    cout << "]";

    return 0;
}