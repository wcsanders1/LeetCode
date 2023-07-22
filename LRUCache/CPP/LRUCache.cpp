// https://leetcode.com/problems/lru-cache/
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Node
{
public:
  Node *prev;
  Node *next;
  int value;
  int key;
};

class LRUCache
{
public:
  LRUCache(int capacity)
  {
    this->capacity = capacity;
    count = 0;
    start = nullptr;
    end = nullptr;
  }

  int get(int key)
  {
    if (m.count(key) == 0)
    {
      return -1;
    }

    resetStart(key);
    return m[key]->value;
  }

  void put(int key, int value)
  {
    if (m.count(key) == 0)
    {
      auto t = start;
      start = new Node();
      start->value = value;
      start->key = key;
      start->next = t;
      if (t != nullptr)
      {
        t->prev = start;
      }
      m[key] = start;
      count++;
    }
    else
    {
      m[key]->value = value;
      resetStart(key);
    }

    if (count == 1)
    {
      end = start;
    }

    if (count > capacity)
    {
      auto t = end;
      int k = end->key;
      end = end->prev;
      end->next = nullptr;
      m.erase(t->key);
      delete t;
      count--;
    }
  }

  Node *start;
  Node *end;
  int capacity;
  int count;
  unordered_map<int, Node *> m;

private:
  void resetStart(int key)
  {
    if (key == this->start->key)
    {
      return;
    }
    auto t = m[key];

    t->prev->next = t->next;
    if (t->next != nullptr)
    {
      t->next->prev = t->prev;
    }
    auto s = start;
    start = t;
    s->prev = t;
    t->next = s;
    if (end->key == t->key)
    {
      end = t->prev;
    }
    t->prev = nullptr;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
  auto cache = new LRUCache(2);
  cache->put(1, 1);
  cache->put(2, 2);
  int result1 = cache->get(1);
  cache->put(3, 3);
  int result2 = cache->get(2);
  cache->put(4, 4);
  int result3 = cache->get(1);
  int result4 = cache->get(3);
  int result5 = cache->get(4);

  auto cache2 = new LRUCache(1);
  cache2->put(2, 1);
  int result2_1 = cache2->get(2);

  auto cache3 = new LRUCache(3);
  cache3->put(1, 1);
  cache3->put(2, 2);
  cache3->put(3, 3);
  cache3->put(4, 4);
  int result3_1 = cache3->get(4);
  int result3_2 = cache3->get(3);
  int result3_3 = cache3->get(2);
  int result3_4 = cache3->get(1);
  cache3->put(5, 5);
  int result3_5 = cache3->get(1);
  int result3_6 = cache3->get(2);
  int result3_7 = cache3->get(3);
  int result3_8 = cache3->get(4);
  int result3_9 = cache3->get(5);
}