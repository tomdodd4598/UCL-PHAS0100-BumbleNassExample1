#include "factors.hpp"

#include <vector>

namespace factors {

    long highest_common_factor(long a, long b) {
        return b == 0 ? labs(a) : highest_common_factor(b, a % b);
    }

    void factorize(long& num, long& den) {
		long hcf = highest_common_factor(num, den);
		num /= hcf;
		den /= hcf;
	}
}
