/*

LeetCode Problem - 2
Add two numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/




/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned long long num1 = 0, num2 = 0, sum = 0,  val = 0, rem = 0;
        int power =0;
        int i =0, j = 0;
        ListNode *res, *node;
        res = NULL;
        node = NULL;

        //Extracting the first number
        do{
            num1 = num1 + l1->val * std::pow(10,i);
            l1=l1->next, ++i;
        }while (l1 != NULL);


        //Extracting the second number
        do{
            num2 = num2 + l2->val * std::pow(10,j);
            l2=l2->next, ++j;
        }while (l2 != NULL);

        sum = num1 + num2;
        unsigned long long number = sum;
        int digits = 0;

        do {
            number /= 10;
            digits++;
        } while (number != 0);

        if (digits == 1)
        {
            res = new ListNode(sum);
            return res;
        }

        do {
            power = std::pow(10, digits - 1);
            val = (unsigned long long)(sum % power);  //val = 0
            std::cout << "Val - " <<val << "\t";
            rem = (unsigned long long) (sum / power);  // rem = 1

            sum = val;  // sum = 0
            std::cout << "rem - "<<rem << "\n";
            std::cout << "Sum - " <<sum << "\t";

            res = new ListNode(rem);

            if (node == NULL){
                node = res;
            }
            else{
                res->next = node;
                node = res;
            }

            digits--;

        }while (digits > 0);

        return node;
    }
};
