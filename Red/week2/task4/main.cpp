#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

class ReadingManager {
public:
    ReadingManager() : user_page_counts_(MAX_USER_COUNT_ + 1, 0), sorted_users_(), user_positions_(MAX_USER_COUNT_ + 1, -1) {}

    void Read(int user_id, int page_count) {
        if (user_page_counts_[user_id] == 0) {
          AddUser(user_id); // amortized O(1)
        }
        user_page_counts_[user_id] = page_count; // O(1)
        int& position = user_positions_[user_id]; // O(1)
        while (position > 0 && page_count > user_page_counts_[sorted_users_[position - 1]]) {
            SwapUsers(position, position - 1); // O(1)
        }
    }
    // O()

    double Cheer(int user_id) const {
        if (user_page_counts_[user_id] == 0) {
            return 0;
        }
        const int user_count = GetUserCount();
        if (user_count == 1) {
            return 1;
        }
        const int page_count = user_page_counts_[user_id];
        int position = user_positions_[user_id];
        while (position < user_count && user_page_counts_[sorted_users_[position]] == page_count) {
            ++position;
        }
        if (position == user_count) {
            return 0;
        }
        return (user_count - position) * 1.0 / (user_count - 1);
    }

private:
    static const int MAX_USER_COUNT_ = 100'000;

    vector<int> user_page_counts_;
    vector<int> sorted_users_;   // отсортированы по убыванию количества страниц
    vector<int> user_positions_; // позиции в векторе sorted_users_

    int GetUserCount() const
    {
        return sorted_users_.size();
    }
    void AddUser(int user_id)
    {
        sorted_users_.push_back(user_id);
        user_positions_[user_id] = sorted_users_.size() - 1;
    }
    void SwapUsers(int lhs_position, int rhs_position) // O(1)
    {
        const int lhs_id = sorted_users_[lhs_position];
        const int rhs_id = sorted_users_[rhs_position];
        swap(sorted_users_[lhs_position], sorted_users_[rhs_position]);
        swap(user_positions_[lhs_id], user_positions_[rhs_id]);
    }
};

/*
class ReadingManager{
public:
    ReadingManager() : usersIds(MAX_USERS_COUNT+1, -1), pagesCount(MAX_PAGES_COUNT+1, 0){}
    void Read(int user_id, int page_count){
        for (int i = usersIds[user_id] + 1; i <= page_count; i++)
        {
            ++pagesCount[i];
        }
        usersIds[user_id] = page_count;
    }
    double Cheer(int user_id){
        if (usersIds[user_id] == -1){ // если user_id нет
            return 0.0f;
        }
        if(pagesCount[0] == 1){ // если только один пользователь прочитал 1-ую страницу
            return 1.0f;
        }
        // если есть ещё пользователи кроме user_id
        return 1.0f*(pagesCount[0]-pagesCount[usersIds[user_id]])/(pagesCount[0] - 1);
    }

private:
    int MAX_USERS_COUNT = 100000;
    int MAX_PAGES_COUNT = 1000;

    vector<int> usersIds; // количетсво страниц, которые суммарно прочитал i-ый пользователь
    // usersIds[0] - количество страниц, который прочитал 1-ый пользователь
    vector<int> pagesCount; // количество пользователей, которые прочитали i-ую страницу
    // pagesCount[0] - количество пользователей, которые прочитали 1-ую страницу

};
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;
    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }

  return 0;
}
