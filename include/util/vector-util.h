#ifndef CPP_SP_VECTOR_UTIL_H
#define CPP_SP_VECTOR_UTIL_H

#include <vector>

template<typename T>
void moveVector(std::vector<T> &src, std::vector<T> &dest) {
    dest.insert(
            dest.end(),
            std::make_move_iterator(src.begin()),
            std::make_move_iterator(src.end())
    );
}

template<typename T>
void moveVector(std::vector<T> &&src, std::vector<T> &dest) {
    dest.insert(
            dest.end(),
            std::make_move_iterator(src.begin()),
            std::make_move_iterator(src.end())
    );
}

#endif //CPP_SP_VECTOR_UTIL_H
