#ifndef DSACPP_TEMPLATE_H
#define DSACPP_TEMPLATE_H
#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

#define fast                   \
  ios::sync_with_stdio(false); \
  cin.tie(NULL);

namespace debug
{
  template <typename T>
  void printVector(const vector<T> &v)
  {
    for (const auto &x : v)
    {
      cout << x << " ";
    }
    cout << '\n';
  }

  template <typename T>
  void printVector2D(const vector<vector<T>> &v)
  {
    for (const auto &row : v)
    {
      for (const auto &x : row)
      {
        cout << x << " ";
      }
      cout << "\n";
    }
  }

  void printTrueOrNot(const bool value)
  {
    if (value)
    {
      cout << "True\n";
    }
    else
    {
      cout << "False\n";
    }
  }
}

#endif // DSACPP_TEMPLATE_H
