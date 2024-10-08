// 1717. Maximum Score From Removing Substrings
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a string s and two integers x and y. You can perform two types of operations any number of times.

// Remove substring "ab" and gain x points.
// For example, when removing "ab" from "cabxbae" it becomes "cxbae".
// Remove substring "ba" and gain y points.
// For example, when removing "ba" from "cabxbae" it becomes "cabxe".
// Return the maximum points you can gain after applying the above operations on s.

 

// Example 1:

// Input: s = "cdbcbbaaabab", x = 4, y = 5
// Output: 19
// Explanation:
// - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
// - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
// - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
// - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
// Total score = 5 + 4 + 5 + 5 = 19.
// Example 2:

// Input: s = "aabbaaxybbaabb", x = 5, y = 4
// Output: 20
 

// Constraints:

// 1 <= s.length <= 105
// 1 <= x, y <= 104
// s consists of lowercase English letters.


// The solution utilises the best O(1) space complexity logic
// usign counters for a and b we pair them up
#include <iostream>
#include <algorithm>
using namespace std;
int MaxPoints(string s, int x, int y){
    if(x < y){
        reverse(s.begin(), s.end());
        int temp = x;
        x = y; y = temp;
    }
    int aCount = 0; int bCount = 0;
    int points = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'a'){
            aCount++;
        }
        else if(s[i] == 'b'){
            if(aCount){
                aCount--;
                points += x;
            }
            else{
                bCount++;
            }
        }
        else{
            points += min(aCount, bCount)*y;
            aCount = bCount = 0;
        }
    }
    points += min(aCount, bCount)*y;
    return points;

}
int main(){
    return 0;
}