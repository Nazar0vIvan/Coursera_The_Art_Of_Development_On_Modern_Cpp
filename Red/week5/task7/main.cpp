#include "test_runner.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <set>
#include <utility>
#include <vector>

using namespace std;

template <typename T>
class PriorityCollection {
public:
    // using Id = /* тип, используемый для идентификаторов */;

    using Id = int;
    // Добавить объект с нулевым приоритетом
    // с помощью перемещения и вернуть его идентификатор
    Id Add(T object){
        objectPriorPairs.emplace_back(move(object),0);
        priorIdPairsSorted.emplace(0,idCount);
        return idCount++;
    }

    // Добавить все элементы диапазона [range_begin, range_end)
    // с помощью перемещения, записав выданные им идентификаторы
    // в диапазон [ids_begin, ...)
    template <typename ObjInputIt, typename IdOutputIt>
    void Add(ObjInputIt range_begin, ObjInputIt range_end, IdOutputIt ids_begin){
        while (range_begin != range_end){
            *ids_begin++ = Add(move(*range_begin++));
        }
    }

    // Определить, принадлежит ли идентификатор какому-либо
    // хранящемуся в контейнере объекту
    bool IsValid(Id id) const{
        return objectPriorPairs[id].second >= 0;
    }

    // Получить объект по идентификатору
    const T& Get(Id id) const{
        return objectPriorPairs[id].first;
    }

    // Увеличить приоритет объекта на 1
    void Promote(Id id){
        auto newPrior = objectPriorPairs[id].second++;
        auto oldPrior = newPrior++;
        priorIdPairsSorted.erase({oldPrior, id});
        priorIdPairsSorted.insert({newPrior, id});
    }

    // Получить объект с максимальным приоритетом и его приоритет
    pair<const T&, int> GetMax() const{
        return objectPriorPairs[prev(priorIdPairsSorted.end())->second];
    }

    // Аналогично GetMax, но удаляет элемент из контейнера
    pair<T, int> PopMax(){
        auto id = prev(priorIdPairsSorted.end())->second;
        auto result = std::move(objectPriorPairs[id]);
        priorIdPairsSorted.erase({result.second, id});
        objectPriorPairs[id] = {T(), -1};
        return result;
    }

private:
    vector<pair<T,int>> objectPriorPairs;
    set<pair<int, Id>> priorIdPairsSorted;
    Id idCount = 0;

};


class StringNonCopyable : public string {
public:
    using string::string;  // Позволяет использовать конструкторы строки
    StringNonCopyable(const StringNonCopyable&) = delete;
    StringNonCopyable(StringNonCopyable&&) = default;
    StringNonCopyable& operator=(const StringNonCopyable&) = delete;
    StringNonCopyable& operator=(StringNonCopyable&&) = default;
};

void TestNoCopy() {
    PriorityCollection<StringNonCopyable> strings;
    const auto white_id = strings.Add("white");
    const auto yellow_id = strings.Add("yellow");
    const auto red_id = strings.Add("red");

    strings.Promote(yellow_id);
    for (int i = 0; i < 2; ++i) {
        strings.Promote(red_id);
    }
    strings.Promote(yellow_id);
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "red");
        ASSERT_EQUAL(item.second, 2);
    }
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "yellow");
        ASSERT_EQUAL(item.second, 2);
    }
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "white");
        ASSERT_EQUAL(item.second, 0);
    }
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestNoCopy);
  return 0;
}
