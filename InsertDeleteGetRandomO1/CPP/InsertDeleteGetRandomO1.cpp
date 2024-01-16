// https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=daily-question&envId=2024-01-16
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class RandomizedSet
{
public:
  RandomizedSet()
  {
    size = 0;
  }

  bool insert(int val)
  {
    if (m.count(val) > 0)
    {
      return false;
    }

    m[val] = size++;
    if (v.size() < size)
    {
      v.push_back(val);
    }
    else
    {
      v[size - 1] = val;
    }

    return true;
  }

  bool remove(int val)
  {
    if (m.count(val) == 0)
    {
      return false;
    }

    m[v[--size]] = m[val];
    v[m[val]] = v[size];
    m.erase(val);

    return true;
  }

  int getRandom()
  {
    int r = rand() % size;
    return v[r];
  }

private:
  unordered_map<int, int> m;
  vector<int> v;
  int size;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
  auto r = new RandomizedSet();
  bool result1 = r->insert(1);
  bool result2 = r->remove(2);
  bool result3 = r->insert(2);
  int result4 = r->getRandom();
  bool result5 = r->remove(1);
  bool result6 = r->insert(2);
  int result7 = r->getRandom();

  auto r2 = new RandomizedSet();
  bool result11 = r2->remove(0);
  bool result12 = r2->remove(0);
  bool result13 = r2->insert(0);
  int result14 = r2->getRandom();
  bool result15 = r2->remove(0);
  bool result16 = r2->insert(0);

  auto r3 = new RandomizedSet();
  bool r31 = r3->insert(0);
  bool r32 = r3->insert(1);
  bool r33 = r3->remove(0);
  bool r34 = r3->insert(2);
  bool r35 = r3->remove(1);
  int r36 = r3->getRandom();
  int r37 = r3->getRandom();
  int r38 = r3->getRandom();
  int r39 = r3->getRandom();
  int r310 = r3->getRandom();
  int r311 = r3->getRandom();
}