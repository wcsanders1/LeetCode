// https://leetcode.com/problems/integer-to-english-words/description/?envType=daily-question&envId=2024-08-07
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  string numberToWords(int num)
  {
    if (num == 0)
    {
      return "Zero";
    }

    vector<string> smalls{
        "",
        "One",
        "Two",
        "Three",
        "Four",
        "Five",
        "Six",
        "Seven",
        "Eight",
        "Nine",
        "Ten",
        "Eleven",
        "Twelve",
        "Thirteen",
        "Fourteen",
        "Fifteen",
        "Sixteen",
        "Seventeen",
        "Eighteen",
        "Nineteen"};

    vector<string> tens{
        "",
        "Ten",
        "Twenty",
        "Thirty",
        "Forty",
        "Fifty",
        "Sixty",
        "Seventy",
        "Eighty",
        "Ninety"};

    vector<string> bigs{
        "",
        "Hundred",
        "Thousand",
        "Million",
        "Billion"};

    string s = to_string(num);
    string answer = "";
    while (!s.empty())
    {
      if (s[0] == '0')
      {
        s = s.substr(1);
        continue;
      }
      int n = 0;
      switch (s.size())
      {
      case 10:
        answer += smalls[stoi(s.substr(0, 1))] + " " + bigs[4];
        s = s.substr(1);
        break;
      case 9:
        answer += smalls[stoi(s.substr(0, 1))] + " " + bigs[1];
        s = s.substr(1);
        n = stoi(s.substr(0, 2));
        if (n == 0)
        {
          answer += " " + bigs[3];
          s = s.substr(2);
        }
        break;
      case 8:
        n = stoi(s.substr(0, 2));
        if (n < 20)
        {
          answer += smalls[n] + " " + bigs[3];
        }
        else
        {
          answer += tens[stoi(s.substr(0, 1))] + " " + smalls[stoi(s.substr(1, 1))] + " " + bigs[3];
        }
        s = s.substr(2);
        break;
      case 7:
        answer += smalls[stoi(s.substr(0, 1))] + " " + bigs[3];
        s = s.substr(1);
        break;
      case 6:
        answer += smalls[stoi(s.substr(0, 1))] + " " + bigs[1];
        s = s.substr(1);
        n = stoi(s.substr(0, 2));
        if (n == 0)
        {
          answer += " " + bigs[2];
          s = s.substr(2);
        }
        break;
      case 5:
        n = stoi(s.substr(0, 2));
        if (n < 20)
        {
          answer += smalls[n] + " " + bigs[2];
        }
        else
        {
          answer += tens[stoi(s.substr(0, 1))] + " " + smalls[stoi(s.substr(1, 1))] + " " + bigs[2];
        }
        s = s.substr(2);
        break;
      case 4:
        answer += smalls[stoi(s.substr(0, 1))] + " " + bigs[2];
        s = s.substr(1);
        break;
      case 3:
        answer += smalls[stoi(s.substr(0, 1))] + " " + bigs[1];
        s = s.substr(1);
        break;
      case 2:
        n = stoi(s.substr(0, 2));
        if (n < 20)
        {
          answer += smalls[n];
        }
        else
        {
          answer += tens[stoi(s.substr(0, 1))] + " " + smalls[stoi(s.substr(1, 1))];
        }
        s = s.substr(2);
        break;
      case 1:
        answer += smalls[stoi(s)];
        s = "";
        break;

      default:
        break;
      }

      if (!s.empty() && !isspace(answer[answer.size() - 1]))
      {
        answer += " ";
      }

      if (s.empty() && isspace(answer[answer.size() - 1]))
      {
        answer = answer.substr(0, answer.size() - 1);
      }
    }

    string realAnswer = "";
    string last = "";
    for (char c : answer)
    {
      string ss{c};
      if (ss != " ")
      {
        realAnswer += ss;
      }
      else if (last != " ")
      {
        realAnswer += ss;
      }

      last = ss;
    }

    if (isspace(realAnswer[realAnswer.size() - 1]))
    {
      realAnswer = realAnswer.substr(0, realAnswer.size() - 1);
    }

    return realAnswer;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.numberToWords(123);
  string result2 = solution.numberToWords(12345);
  string result3 = solution.numberToWords(1234567);
  string result4 = solution.numberToWords(20);
  string result5 = solution.numberToWords(1000);
  string result6 = solution.numberToWords(50868);
  string result7 = solution.numberToWords(100000);
  string result8 = solution.numberToWords(100000000);
}