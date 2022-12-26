#include <string>
#include <string_view>
#include <list>

#include "test_runner.h"

using namespace std;

class Translator{
public:
  void Add(string_view source, string_view target){
    string_view source_copy = cloneView(source);
    string_view target_copy = cloneView(target);
    forwardDic[source_copy] = target_copy;
    backwardDic[target_copy] = source_copy;
  }
  string_view TranslateForward(string_view source) const{
    if(!forwardDic.count(source)){
      return string_view();
    }
    return forwardDic.at(source);
  }
  string_view TranslateBackward(string_view target) const{
    if(!backwardDic.count(target)){
      return string_view();
    }
    return backwardDic.at(target);
  }

  string_view cloneView(string_view sv){ // ищет в обоих словарях sv и возвращает ключ
    auto it = forwardDic.find(sv);
    if(it != forwardDic.end()){
      return it->first;
    }
    else{
      auto it = backwardDic.find(sv);
      if(it != backwardDic.end()){
          return it->first;
      }
    }
    return strings.emplace_back(sv);
  }

private:
  map<string_view,string_view> forwardDic;
  map<string_view,string_view> backwardDic;
  list<string> strings;
};

void TestSimple(){
  Translator translator;
  translator.Add(string("okno"), string("window"));
  translator.Add(string("stol"), string("table"));

  ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
  ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
  ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}

int main(){
  TestRunner tr;
  RUN_TEST(tr, TestSimple);
  return 0;
}
