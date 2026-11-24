// https://leetcode.com/problems/product-of-the-last-k-numbers/description/?envType=daily-question&envId=2026-11-23
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

class ProductOfNumbers
{
public:
  ProductOfNumbers()
  {
  }

  void add(int num)
  {
    nums.push_back(num);
  }

  int getProduct(int k)
  {
    int product = nums[nums.size() - 1];
    for (int i = 1; i < k; i++)
    {
      product *= nums[nums.size() - 1 - i];
    }

    return product;
  }

private:
  vector<int> nums;
};

int main()
{
  auto p1 = new ProductOfNumbers();
  p1->add(3);
  p1->add(0);
  p1->add(2);
  p1->add(5);
  p1->add(4);
  int res1 = p1->getProduct(2);
  int res2 = p1->getProduct(3);
  int res3 = p1->getProduct(4);
  p1->add(8);
  int res4 = p1->getProduct(2);
}