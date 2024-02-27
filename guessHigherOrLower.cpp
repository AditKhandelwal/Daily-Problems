// We are playing the Guess Game. The game is as follows:

// I pick a number from 1 to n. You have to guess which number I picked.

// Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

// You call a pre-defined API int guess(int num), which returns three possible results:

// -1: Your guess is higher than the number I picked (i.e. num > pick).
// 1: Your guess is lower than the number I picked (i.e. num < pick).
// 0: your guess is equal to the number I picked (i.e. num == pick).
// Return the number that I picked.


// Problem is altered so I can run it in my own workspace
#include <iostream>

using namespace std;

int guess(int yourGuess, int numToGuess) {
  if(yourGuess < numToGuess) {
    return 1;
  }
  if(yourGuess > numToGuess) {
    return -1;
  }
  if(yourGuess == numToGuess) {
    return 0;
  }
  return 0;
}

int guessNumber(int n, int numToGuess) {
  long left = 1;
  long right = n;
  long mid = (right + left) / 2;

  while(left <= right) {
    mid = (right + left) / 2;

    if(guess(mid, numToGuess) == 0) {
        return mid;
    }
    else if(guess(mid, numToGuess) == 1) {
        left = mid + 1;
    }
    else if(guess(mid, numToGuess) == -1) {
        right = mid - 1;
    }
  }
  return 0;
}

int main() {
  int n = 50;
  int numToGuess = 6;

  cout << guessNumber(50, 6);
}
