//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <unordered_set>

// Call erase(const_iterator position) with end()

#if _LIBCPP_DEBUG >= 1

#define _LIBCPP_ASSERT(x, m) ((x) ? (void)0 : std::exit(0))

#include <unordered_set>
#include <cassert>

int main()
{
    {
    int a1[] = {1, 2, 3};
    std::unordered_set<int> l1(a1, a1+3);
    std::unordered_set<int>::const_iterator i = l1.end();
    l1.erase(i);
    assert(false);
    }
}

#else

int main()
{
}

#endif
