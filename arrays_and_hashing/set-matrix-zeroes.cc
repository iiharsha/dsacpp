#include "../template.h"

class Solution {
public:
  /*
   * Given an m x n int matrix, if an element is 0, set its entire row and
   * column to 0's
   *
   * I/P = [1,1,1]
   *       [1,0,1]
   *       [1,1,1]
   *
   * O/P = [1,0,1]
   *       [0,0,0]
   *       [1,0,1]
   */
  void setZeroes(vector<vector<int>> &matrix) 
  {
    int rows = matrix.size();
    int cols = matrix[0].size();

    bool isFirstRowZero = 0;
    bool isFirstColZero = 0;

    for (int j = 0; j < cols; ++j) {
      if (matrix[0][j] == 0) {
        isFirstColZero = true;
        break;
      }
    }

    for (int i = 0; i < rows; ++i) {
      if (matrix[i][0] == 0) {
        isFirstRowZero = true;
        break;
      }
    }

    for (int i = 1; i < rows; ++i) {
      for (int j = 1; j < cols; ++j) {
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0; // mark the zero in the first row
          matrix[i][0] = 0; // mark the zero in the first col
        }
      }
    }
    
    for (int i = 1; i < rows; ++i) {
      for (int j = 1; j < cols; ++j) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    if (isFirstColZero) {
      for (int j = 0; j < cols; ++j) {
        matrix[0][j] = 0;
      }
    }

    if (isFirstRowZero) {
      for (int i = 0; i < rows; ++i) {
        matrix[i][0] = 0;
      }
    }


    printMatrix(matrix);
  }

private:
  void printMatrix(const vector<vector<int>> &matrix) 
  {
    if (matrix.empty() || matrix[0].empty())
      return;

    for (auto row : matrix) {
      for (auto val : row) {
        cout << val << " ";
      }
      cout << '\n';
    }
  }
};

int main(void)
{
  fast;

  Solution sol;

  vector<vector<int>> matrix1 = {
                              {1, 1, 1},
                              {1, 0, 1},
                              {1, 1, 1}};
  sol.setZeroes(matrix1);

  cout << '\n';

  vector<vector<int>> matrix2 = {
                              {0, 1, 2, 0},
                              {3, 4, 5, 2},
                              {1, 3, 1, 5}};
  sol.setZeroes(matrix2);

  return 0;
}
