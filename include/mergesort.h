//
// Created by aknight on 9/19/18.
//

#ifndef MERGESORT_MERGESORT_H
#define MERGESORT_MERGESORT_H
#include <cstdlib>
#include <algorithm>
#include <iostream>

namespace edu { namespace vcccd { namespace vc { namespace csv15 {
    using std::distance;
    namespace {
        template<typename T>
        void _merge(T lo[], T hi[], size_t loSize, size_t hiSize) {
            size_t size = loSize + hiSize;
            T hold[size];
            T *loPtr = lo, *hiPtr = hi, *h = hold;
            while(distance(lo, loPtr) < loSize && distance(hi, hiPtr) < hiSize)
                *h++ = (*loPtr > *hiPtr) ? *hiPtr++ : *loPtr++;

            while (distance(lo, loPtr) < loSize) *h++ = *loPtr++;
            while (distance(hi, hiPtr) < hiSize) *h++ = *hiPtr++;

            for(loPtr = lo, h = hold; distance(lo, loPtr) < size; *loPtr++ = *h++);
        }
    }

    template<typename T>
    void mergesort(T array[], size_t size) {
        if (size == 1) return;
        size_t half = size / 2;
        mergesort(array, half);
        mergesort(array + half, size - half);
        _merge(array, array + half, half, size - half);
    }
}}}}

#endif //MERGESORT_MERGESORT_H
