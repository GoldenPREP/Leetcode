#include <iostream> 
#include <vector> 
#include <string> 
using namespace std; 

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;  // grouped string 
        int size = s.size();
        int curr = 0;  // starting index of each group
        // split string    
        // need to iterate through the whole string
        while (curr < s.size()) 
        {  
            //add the string from position current, and length of k 
            //example string = "watwatwa" k = 2 first group is "wa" 
            //position = 0 (curr) length k = 2 (s.[0] + s.[1])
            res.push_back(s.substr(curr, k)); 
            curr += k;
        }
        // try to fill in the last group 
        // if the size is divisable by number k, the number of fill characters needed is 0 aka size % k 
        // otherwise the fillnum is the number k - mod of the size by k 
        // ex: k=3 size = 11  3 - (11 % 3 = 2) = 1 you add one k to the last string in the vector
        int fillnum = (size % k) == 0 ? (size % k) : k - (size % k); 
        for (int i = 0; i < fillnum; i++) 
        { 
            res.back() += fill;
        }
        return res;
    }
};

int main() {   
    //Test case 1; 
    //Expected Output
    //["abc","def","ghi"] 
    string s = "abcdefghi"; 
    int k = 3;
    char fill = 'x';

    //Test case 2;  
    //Expected Output
    //["abc","def","ghi","jxx"]
    //string s = "abcdefghij"; 
    //int k = 3;
    //char fill = 'x'; 
     
    Solution Result;
    vector<string> result = Result.divideString(s, k, fill);
    int GroupNumber = (s.size() % k == 0) ? s.size() / k : (s.size() / k) + 1;
    int curr = 0; 
    cout << "[";
    while(curr < GroupNumber) 
    { 
        cout << "\"" << result.at(curr) << "\"";
        if(curr + 1 != GroupNumber) cout << ","; 
        curr++;
    } 
    cout << "]";
    return 0;
}