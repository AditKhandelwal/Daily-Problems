// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example Input: [1, 2, 3, 4, 5]
// Example Output: [120, 60, 40, 30, 24]

#include <iostream>

using namespace std;


void printArr(vector<int> A) {
  cout << "[";
  for(int i=0; i<A.size(); i++) {
    if (i!=A.size()-1) {
      cout << A[i] << ", ";
    }
    else {
      cout << A[i] << "]";  
    }
  }
}

void simpleSolution(vector<int>& A) {
  int product = 1;
  vector<int> rA(A.size());

  for(int i=0; i<A.size(); i++) {
    product *= A[i];
  }

  float temp = product;

  for(int i=0; i<A.size(); i++) {
    temp /= A[i];
    rA[i] = temp;
    temp = product;
  }

  printArr(rA);
  cout << endl;
}

void noDivSolution(vector<int> A) {
  vector<int> rV(A.size());
  for(int i=0; i<A.size(); i++) {
    int product = 1;
    for(int j=0; j<A.size(); j++) {
      if(i != j) {
        product *= A[j];
      }
    }
    rV[i] = product;
  }

  printArr(rV);
  cout << endl;
}

void idealSolution(vector<int> A) {
  vector<int> left(A.size());
  vector<int> right(A.size());
  vector<int> rV(A.size());

  left[0] = 1;
  right[A.size()-1] = 1;

  // Calculate left products
  for(int i=1; i<A.size(); i++) {
    left[i] = A[i-1] * left[i-1];
  }

  // Calculate right products
  for(int j=A.size()-2; j>=0; j--) {
    right[j] = A[j+1] * right[j+1];
  }

  // Calculate final products
  for(int k=0; k<A.size(); k++) {
    rV[k] = left[k] * right[k];
  }

  printArr(rV);
  cout << endl;
}

int main() {
  int arrSize;
  cin >> arrSize;
  vector<int> nums;
  for(int i=0; i<arrSize; i++) {
    int input;
    cin >> input;
    nums.push_back(input);
  }

  simpleSolution(nums);
  noDivSolution(nums);
  idealSolution(nums);

}