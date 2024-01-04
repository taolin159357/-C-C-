* 如果题目限定了对应的指针，最好使用new（malloc）和delete（free）创建相应的空间；如果题目没有限定对应的指针，那么直接使用智能指针

  ```c++
  class Solution {
      shared_ptr<vector<string>> cache[100] = {nullptr};
  public:
      shared_ptr<vector<string>> generate(int n) {
          if (cache[n] != nullptr)
              return cache[n];
          if (n == 0) {
              cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
          } else {
              auto result = shared_ptr<vector<string>>(new vector<string>);
              for (int i = 0; i != n; ++i) {
                  auto lefts = generate(i);
                  auto rights = generate(n - i - 1);
                  for (const string& left : *lefts)
                      for (const string& right : *rights)
                          result -> push_back("(" + left + ")" + right);
              }
              cache[n] = result;
          }
          return cache[n];
      }
      vector<string> generateParenthesis(int n) {
          return *generate(n);
      }
  };
  ```

* 对于那些有顺序要求的问题，用map（红黑树）会更高效一些；对于查找问题，unordered_map（散列）会更加高效一些；也有set和unordered_set，unordered_map初始化如下

  ```c++
  unordered_map<char, string> phoneMap{
              {'2', "abc"},
              {'3', "def"},
              {'4', "ghi"},
              {'5', "jkl"},
              {'6', "mno"},
              {'7', "pqrs"},
              {'8', "tuv"},
              {'9', "wxyz"}
          };
  ```

* lambda表达式写法示例

  ```c++
  class Solution {
  public:
      using LL = long long;
  
      struct Staff {
          int s, e;
          bool operator < (const Staff& rhs) const {
              return s > rhs.s;
          }
      };
  
      int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
          vector<Staff> v;
          priority_queue<Staff> q;
          for (int i = 0; i < n; ++i) {
              v.push_back({speed[i], efficiency[i]});
          }
          sort(v.begin(), v.end(), [] (const Staff& u, const Staff& v) { return u.e > v.e; });
          LL ans = 0, sum = 0;
          for (int i = 0; i < n; ++i) {
              LL minE = v[i].e;
              LL sumS = sum + v[i].s;
              ans = max(ans, sumS * minE);
              q.push(v[i]); 
              sum += v[i].s;
              if (q.size() == k) {
                  sum -= q.top().s;
                  q.pop();
              }
          }
          return ans % (int(1E9) + 7);
      }
  };
  ```

* INT_MIN和INT_MAX

