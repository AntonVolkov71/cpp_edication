#include <cmath>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
   auto it = binary_search(range_begin, range_end, prefix);

   if(it == range_end){
       auto it_lower = lower_bound(range_begin, range_end, prefix);

       return make_pair(it_lower, range_end);
   }

}


int main() {
    const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

    const auto m_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto p_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " << (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " << (z_result.second - begin(sorted_strings)) << endl;

    return 0;
}

//set<int>::const_iterator FindNearestElement(const set<int> &cont, int border) {
//    if (cont.empty()) {
//        return cont.end();
//    }
//
//    auto it = cont.lower_bound(border);
//
//    if (it != cont.begin()) {
//        auto it_prev = prev(it, 1);
//
//        if (abs(border - *it_prev) > abs(border - *it)) {
//            return it;
//        }
//
//        return it_prev;
//    }
//
//    return it;
//};



//int main() {
//    set<int> numbers = {1, 4, 6};
//    cout << *FindNearestElement(numbers, 0) << " " << *FindNearestElement(numbers, 3) << " "
//         << *FindNearestElement(numbers, 5) << " " << *FindNearestElement(numbers, 6) << " "
//         << *FindNearestElement(numbers, 100) << endl;
//
//    set<int> empty_set;
//
//    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
//    return 0;
//}