// https://leetcode.com/problems/design-hashmap/?envType=daily-question&envId=2023-10-04
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class MyHashMap
{
public:
  MyHashMap()
  {
    m = new vector<int>(10e6, -1);
  }

  ~MyHashMap()
  {
    m->clear();
    delete m;
  }

  void put(int key, int value)
  {
    (*m)[key] = value;
  }

  int get(int key)
  {
    return (*m)[key];
  }

  void remove(int key)
  {
    (*m)[key] = -1;
  }

private:
  vector<int> *m;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */