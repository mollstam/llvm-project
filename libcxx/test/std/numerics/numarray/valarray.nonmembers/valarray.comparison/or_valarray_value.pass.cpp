//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <valarray>

// template<class T> class valarray;

// template<class T>
//   valarray<bool>
//   operator||(const valarray<T>& x, const T& y);

#include <valarray>
#include <cassert>
#include <cstddef>

int main()
{
    {
        typedef int T;
        T a1[] = {1,  2,  3,  4,  0};
        bool a3[] = {true,  true,  true,  true,  true};
        const unsigned N = sizeof(a1)/sizeof(a1[0]);
        std::valarray<T> v1(a1, N);
        std::valarray<bool> v3 = v1 || 5;
        assert(v1.size() == v3.size());
        for (std::size_t i = 0; i < v1.size(); ++i)
            assert(v3[i] == a3[i]);
    }
    {
        typedef int T;
        T a1[] = {1,  2,  3,  4,  0};
        bool a3[] = {true,  true,  true,  true,  false};
        const unsigned N = sizeof(a1)/sizeof(a1[0]);
        std::valarray<T> v1(a1, N);
        std::valarray<bool> v3 = v1 || 0;
        assert(v1.size() == v3.size());
        for (std::size_t i = 0; i < v1.size(); ++i)
            assert(v3[i] == a3[i]);
    }
}
