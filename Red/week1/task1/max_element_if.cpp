#include <algorithm>

using namespace std;

template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred) {
  ForwardIterator maxIt = find_if(first, last, pred);
  for (ForwardIterator cur = maxIt; cur != last; ++cur) {
    if (cur != maxIt && pred(*cur) && *maxIt < *cur) {
      maxIt = cur;
    }
  }
  return maxIt;
}
