#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> decode(vector<int> &encoded)
  {
    vector<int> result(encoded.size() + 1, 0);
    int x = 1;
    for (int i = 2; i <= encoded.size() + 1; i++)
    {
      x ^= i;
    }

    for (int i = 1; i < encoded.size(); i += 2)
    {
      x ^= encoded[i];
    }

    result[0] = x;

    for (int i = 1; i < result.size(); i++)
    {
      result[i] = result[i - 1] ^ encoded[i - 1];
    }

    return result;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.decode(*new vector<int>{3, 1});
  auto result2 = solution.decode(*new vector<int>{6, 5, 4, 6});
}