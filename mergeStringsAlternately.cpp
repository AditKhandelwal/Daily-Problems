// You are given two strings word1 and word2. 
// Merge the strings by adding letters in alternating order, 
// starting with word1. If a string is longer than the other, 
// append the additional letters onto the end of the merged string.

// Return the merged string.

#include <iostream>

using namespace std;

string mergeAlternately(string word1, string word2) {
    int length = max(word1.length(), word2.length());
    string rV = "";
    for(int i=0; i<length; i++) {
        if(i < word1.length()) {
            rV += word1[i];
        }
        if(i < word2.length()) {
            rV += word2[i];
        }
    }
    return rV;
}

int main() {
  string str1 = "abc";
  string str2 = "pqr";

  cout << mergeAlternately(str1, str2);
  
}