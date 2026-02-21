#include "../template.h"

class Solution {
public:
  /**
   * You are given an m x n integer matrix matrix with the following two
   * properties:
   *
   * Each row is sorted in non-decreasing order.
   * The first integer of each row is greater than the last integer of the
   * previous row.
   *
   * Given an integer target, return true if target is in matrix or false
   * otherwise.
   *
   * You must write a solution in O(log(m * n)) time complexity.
   */
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int left = 0, right = rows * cols - 1;
    while (left <= right) {

      int mid = left + (right - left) / 2;
      int row = mid / cols;
      int col = mid % cols;
      int curr = matrix[row][col];

      if (curr == target) {
        return true;
      }

      if (curr < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }
};

int main(void) {
  fast;

  Solution sol;

  vector<vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  int target = 3;
  bool res = sol.searchMatrix(matrix, target);
  if (res) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
}
