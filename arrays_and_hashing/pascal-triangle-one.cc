#include "../template.h"

class Solution {
public:
 /*
  * Given an integer numRows, return the first numRows of Pascal's triangle.
  * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
  *
  * Example:
  * I/P : numRows = 5
  * O/P : [[1],[1,1],[1,2,1],[1,3,3,1], [1,4,6,4,1]]
  */
  vector<vector<int>> generate(int numRows) 
  {
    vector<vector<int>> triangle;

    for (int i = 0; i < numRows; ++i) {
      vector<int> row(i + 1, 1);

      for (int j = 1; j < i; ++j) {
        row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
      }

      triangle.push_back(row);
    }

    printResult(triangle);
    return triangle;
  }

private:
  void printResult(const vector<vector<int>>& triangle) const
  {
    for (const auto &row : triangle) {
      cout << '[';
      for (int val : row) {
        cout  <<  val << ",";
      }
      cout << ']';
    }
    cout << '\n';
  }
};

int main(void) {
  fast;

  Solution sol;

  int numRows = 30;
  auto res = sol.generate(numRows);

  return 0;
}
