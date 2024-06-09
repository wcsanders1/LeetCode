// https://leetcode.com/problems/replace-words/description/?envType=daily-question&envId=2024-06-07
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Trie
{
public:
  unordered_map<char, Trie> *branches;
  char value;
  bool isEnd;
  Trie()
  {
    branches = new unordered_map<char, Trie>();
    isEnd = false;
  }
};

class Solution
{
public:
  string replaceWords(vector<string> &dictionary, string sentence)
  {
    Trie root;
    for (string &word : dictionary)
    {
      Trie *t = &root;
      for (char &c : word)
      {
        if (t->branches->count(c) == 0)
        {
          Trie n;
          n.value = c;
          t->branches->insert(make_pair(c, n));
        }
        t = &(*t->branches)[c];
      }
      t->isEnd = true;
    }

    queue<string> q;
    string s = "";
    for (char c : sentence)
    {
      if (c == ' ')
      {
        q.push(s);
        s = "";
      }
      else
      {
        s += c;
      }
    }

    if (s.size() > 0)
    {
      q.push(s);
    }

    string answer = "";
    while (!q.empty())
    {
      s = q.front();
      q.pop();

      if (answer.size() > 0)
      {
        answer += " ";
      }

      string temp = "";
      Trie *t = &root;
      for (char &c : s)
      {
        if (t->branches->count(c) > 0)
        {
          t = &(*t->branches)[c];
          temp += c;
          if (t->isEnd)
          {
            break;
          }
        }
        else
        {
          temp = s;
          break;
        }
      }
      answer += temp;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.replaceWords(*new vector<string>{"cat", "bat", "rat"}, "the cattle was rattled by the battery");
  string result2 = solution.replaceWords(*new vector<string>{"a", "b", "c"}, "aadsfasf absbs bbab cadsafafs");
  string result3 = solution.replaceWords(*new vector<string>{"a", "aa", "aaa", "aaaa"}, "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa");
  string result4 = solution.replaceWords(*new vector<string>{"e", "k", "c", "harqp", "h", "gsafc", "vn", "lqp", "soy", "mr", "x", "iitgm", "sb", "oo", "spj", "gwmly", "iu", "z", "f", "ha", "vds", "v", "vpx", "fir", "t", "xo", "apifm", "tlznm", "kkv", "nxyud", "j", "qp", "omn", "zoxp", "mutu", "i", "nxth", "dwuer", "sadl", "pv", "w", "mding", "mubem", "xsmwc", "vl", "farov", "twfmq", "ljhmr", "q", "bbzs", "kd", "kwc", "a", "buq", "sm", "yi", "nypa", "xwz", "si", "amqx", "iy", "eb", "qvgt", "twy", "rf", "dc", "utt", "mxjfu", "hm", "trz", "lzh", "lref", "qbx", "fmemr", "gil", "go", "qggh", "uud", "trnhf", "gels", "dfdq", "qzkx", "qxw"}, "ikkbp miszkays wqjferqoxjwvbieyk gvcfldkiavww vhokchxz dvypwyb bxahfzcfanteibiltins ueebf lqhflvwxksi dco kddxmckhvqifbuzkhstp wc ytzzlm gximjuhzfdjuamhsu gdkbmhpnvy ifvifheoxqlbosfww mengfdydekwttkhbzenk wjhmmyltmeufqvcpcxg hthcuovils ldipovluo aiprogn nusquzpmnogtjkklfhta klxvvlvyh nxzgnrveghc mpppfhzjkbucv cqcft uwmahhqradjtf iaaasabqqzmbcig zcpvpyypsmodtoiif qjuiqtfhzcpnmtk yzfragcextvx ivnvgkaqs iplazv jurtsyh gzixfeugj rnukjgtjpim hscyhgoru aledyrmzwhsz xbahcwfwm hzd ygelddphxnbh rvjxtlqfnlmwdoezh zawfkko iwhkcddxgpqtdrjrcv bbfj mhs nenrqfkbf spfpazr wrkjiwyf cw dtd cqibzmuuhukwylrnld dtaxhddidfwqs bgnnoxgyynol hg dijhrrpnwjlju muzzrrsypzgwvblf zbugltrnyzbg hktdviastoireyiqf qvufxgcixvhrjqtna ipfzhuvgo daee r nlipyfszvxlwqw yoq dewpgtcrzausqwhh qzsaobsghgm ichlpsjlsrwzhbyfhm ksenb bqprarpgnyemzwifqzz oai pnqottd nygesjtlpala qmxixtooxtbrzyorn gyvukjpc s mxhlkdaycskj uvwmerplaibeknltuvd ocnn frotscysdyclrc ckcttaceuuxzcghw pxbd oklwhcppuziixpvihihp");
}