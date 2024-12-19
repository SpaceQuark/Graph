#include <string>
#include <iostream>
#include <cstdint> 
#include <string>
#include <array>
#include <optional>
#include <functional> // For hash

#include <stdio.h>
#include <variant>
#include <type_traits> // For std::decay_t
#include <concepts>

#include <algorithm> 
#include <limits>
#include <numeric>
#include <vector>
#include <utility>
#include <tuple>
#include <iterator>
#include <iomanip>
#include <optional>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>
#include <cassert>

using std::string;
using std::ostream;
using std::cout;
using std::cerr;
using std::endl;
using std::array;
using std::optional;
using std::nullopt;
using std::hash;
using std::numeric_limits;

using std::vector;
using std::pair;
using std::unordered_set;
using std::unordered_map;
using std::stack;
using std::queue;
using std::priority_queue;

using std::remove;
using std::remove_if;
using std::invalid_argument;
using std::function;
using std::greater;

using std::min;
using std::max;

template <class T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

// #define MX uint64_t{-1}
#define INV static_cast<uint64_t>(-1)

#define WINF std::numeric_limits<int64_t>::max()

