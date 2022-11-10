#include <cmath>
#include <initializer_list>
#include <iostream>
#include <vector>


template <typename S>
std::ostream& operator<<(std::ostream& o, const std::vector<S>& v) {
    o << "[";
    const char* s = "";
    for (auto& element : v) {
        o << s << element;
        s = ", ";
    }
    o << "]";
    return o;
}


using L = unsigned long;


// a "brute force" algorithm (the Quadratic Sieve factoring algorithm is, among others, better)
std::vector<L> factorise(L n) {
    std::vector<L> f;

    while (n % 2 == 0) {
        f.push_back(2);
        n /= 2;
    }

    for (L c = 3, cmax = n / 3; 1 < n && c <= cmax; c += 2) {
        while (n % c == 0) {
            f.push_back(c);
            n /= c;
        }
    }

    return f;
}


int main() {
    for (L n : {315, 588, 2206637, 3111989, 13091989}) {
        std::cout << n << ": " << factorise(n) << std::endl;
    }

    return 0;
}