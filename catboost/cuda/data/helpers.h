#pragma once

#include <algorithm>
#include <util/generic/set.h>

template <class TSortedStorage>
inline bool IsSubset(const TSortedStorage& subset, const TSortedStorage& set) {
    return std::includes(set.begin(), set.end(), subset.begin(), subset.end());
}

template <class TSortedStorage>
inline bool NotSubset(const TSortedStorage& subset, const TSortedStorage& set) {
    return !IsSubset(subset, set);
}

template <class TSortedStorage>
inline yvector<typename TSortedStorage::value_type> RemoveExisting(const TSortedStorage& from, const TSortedStorage& what) {
    using T = typename TSortedStorage::value_type;
    yvector<T> result;
    std::set_difference(from.begin(), from.end(), what.begin(), what.end(), std::inserter(result, result.end()));
    return result;
}