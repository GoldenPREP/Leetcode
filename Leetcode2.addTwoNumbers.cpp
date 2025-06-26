#include <iostream> 
#include <vector> 
#include <string> 
using namespace std; 

/**
 * Definition for singly-linked list.
 * struct ListNode { 
 *     
 *     the variable for setting a value to a node
 *     int val; 
 *
 *     To move to next node
 *     ListNode *next; 
 *
 *     Constructor for empty SLL
 *     ListNode() : val(0), next(nullptr) {} 
 *     
 *     Constructor to initilize a SLL with begining value of x
 *     ListNode(int x) : val(x), next(nullptr) {} 
 *      
 *     sets next node to the value x
 *     ListNode(int x, ListNode *next) : val(x), next(next) {} 
 * };
 */
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* temp = new ListNode(); 
        ListNode* result = temp;
        int l1s = 0; 
        int l2s = 0; 
        int sum = 0; 
        int carry = 0;  
        //read each value then add to l1 int by adding to the variable 
        //multiply my count starting at 1 then muliply by 10 for each
        //number in the next place ex: 2 x 1 = 2 + 4 x 10 = 
        // 42 + 3 x 100 = 142 example was [2,4,1]
        while(l1 != nullptr || l2 != nullptr || carry != 0) 
        { 
            if (l1) 
            { 
                l1s += (l1 != nullptr) ? (l1->val) : 0; 
                l1 = l1->next;
            }
            if (l2)
            {
                l2s += (l2 != nullptr) ? (l2->val) : 0;
                l2 = l2->next;  
            } 
            int sum = l1s + l2s + carry;
            carry = sum / 10; 
            int total = sum % 10; 
            temp->next = new ListNode(total); 
            temp = temp->next;
        }  
        ListNode* res = result->next;
        delete result;
        return res;
    }  
  
};