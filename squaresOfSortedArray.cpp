#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
  for(int i=0; i<nums.size(); i++) {
    nums[i] = abs(nums[i]) * abs(nums[i]);
  }

  sort(nums.begin(), nums.end());
  return nums;
}


int main() {
  // TEST CASE 1
  // Input: {-4, -1, 0, 3, 10}
  vector<int> nums1;
  nums1.push_back(-4);
  nums1.push_back(-1);
  nums1.push_back(0);
  nums1.push_back(3);
  nums1.push_back(10);
  // Output: {0, 1, 9, 16, 100}
  vector<int> nums1Expected;
  nums1.push_back(0);
  nums1.push_back(1);
  nums1.push_back(9);
  nums1.push_back(16);
  nums1.push_back(100);

  bool test1 = (sortedSquares(nums1) == nums1Expected);

  // TEST CASE 2
  // Input: {-7, -3, 2, 3, 11}
  vector<int> nums2;
  nums1.push_back(-7);
  nums1.push_back(-3);
  nums1.push_back(2);
  nums1.push_back(3);
  nums1.push_back(11);

  // Output: {4, 9, 9, 49, 121}
  vector<int> nums2Expected;
  nums1.push_back(4);
  nums1.push_back(9);
  nums1.push_back(9);
  nums1.push_back(49);
  nums1.push_back(121);

  bool test2 = (sortedSquares(nums2) == nums2Expected); 

  if(test1) {
    cout << "TEST CASE 1: PASSED" << endl;
  }
  else {
    cout << "TEST CASE 1: FAILED" << endl;
  }

  if(test2) {
    cout << "TEST CASE 2: PASSED" << endl;
  }
  else {
    cout << "TEST CASE 2: FAILED" << endl;
  }
}