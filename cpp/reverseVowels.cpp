/*

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

*/





#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        
        if(s.length() <= 1){
            return s;
        }
        string::iterator first = s.begin();
        string::iterator last = s.end()-1;

        char ch;
        bool find_first = false;
        bool find_last = false;

        while( first <= last-1 ){

            if(*first == 'a' || *first == 'e' || *first == 'i' || *first == 'o' || *first == 'u' || *first == 'A' || *first == 'E' || *first == 'I' || *first == 'O' || *first == 'U'){
                find_first = true;
            }
            
            if(*last == 'a' || *last == 'e' || *last == 'i' || *last == 'o' || *last == 'u' || *last == 'A' || *last == 'E' || *last == 'I' || *last == 'O' || *last == 'U'){
                find_last = true;
            }
            
            if(find_first && find_last){
                swap(*first, *last);

                find_first = false;
                find_last = false;
                first++;
                last--;

            }else if(find_first && !find_last){
                last--;
            }else if(!find_first && find_last){
                first++;
            }else{
                first++;
                last--;
            }
        }
        
        return s;
    }
};

int main(){
    Solution s;
    string str = "hello";
    cout << s.reverseVowels(str) << endl;

}