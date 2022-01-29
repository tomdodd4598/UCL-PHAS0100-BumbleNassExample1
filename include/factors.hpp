#ifndef FACTORS_H
#define FACTORS_H

#include <cstdlib>
#include <iterator>
#include <stdint.h>
#include <utility>
#include <vector>

namespace factors {

    long highest_common_factor(long a, long b);

    template <typename T>
    long highest_common_factor(T&& vals) {
        long len = vals.size();
		if (len == 0) {
            return 1;
        }
		else if (len == 1) {
            return labs(vals[0]);
        }
		else {
            long hcf = highest_common_factor(vals[0], vals[1]);
            if (len == 2) {
                return hcf;
            }
            else {
                auto next = std::vector<long>(vals.begin() + 2, vals.end());
                next.push_back(hcf);
                return highest_common_factor(std::move(next));
            }
        }
    }

	void factorize(long& num, long& den);
}

#endif
