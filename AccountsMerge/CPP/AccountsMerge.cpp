// https://leetcode.com/problems/accounts-merge/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

struct Account
{
  string name;
  vector<string> emails;
};

class Solution
{
public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
  {
    unordered_map<int, Account> accountsById;
    unordered_map<string, vector<int>> emailsByAccountId;
    for (int i = 0; i < accounts.size(); i++)
    {
      accountsById[i] = {accounts[i][0], {}};
      for (int e = 1; e < accounts[i].size(); e++)
      {
        string email = accounts[i][e];
        emailsByAccountId[email].push_back(i);
        accountsById[i].emails.push_back(email);
      }
    }

    vector<bool> visited(accounts.size(), false);
    vector<vector<string>> mergedAccounts;
    for (auto &[id, account] : accountsById)
    {
      unordered_set<string> emails;
      getEmails(accountsById, emailsByAccountId, visited, emails, id);
      if (emails.size() == 0)
      {
        continue;
      }
      vector<string> mergedEmails(emails.begin(), emails.end());
      sort(mergedEmails.begin(), mergedEmails.end());
      vector<string> mergedAccount;
      mergedAccount.push_back(account.name);
      for (string &me : mergedEmails)
      {
        mergedAccount.push_back(me);
      }
      mergedAccounts.push_back(mergedAccount);
    }

    return mergedAccounts;
  }

private:
  void getEmails(
      unordered_map<int, Account> &accountsById,
      unordered_map<string, vector<int>> &emailsByAccountId,
      vector<bool> &visited,
      unordered_set<string> &emails,
      int id)
  {
    if (visited[id])
    {
      return;
    }

    visited[id] = true;
    for (string &email : accountsById[id].emails)
    {
      emails.insert(email);
      for (int &nextId : emailsByAccountId[email])
      {
        getEmails(accountsById, emailsByAccountId, visited, emails, nextId);
      }
    }
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.accountsMerge(*new vector<vector<string>>{{"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"John", "johnsmith@mail.com", "john00@mail.com"}, {"Mary", "mary@mail.com"}, {"John", "johnnybravo@mail.com"}});
}