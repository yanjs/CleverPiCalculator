#include <iostream>
#include <iomanip>
#include <cmath>
typedef long double ld;
constexpr bool SHOW_ARCCOS_V2 = false;

using std::cout;
using std::endl;
using std::setbase;
using std::acos;
using std::pow;

int main(int argc, const char* argv[]) {
    // change *digit* and *base* to see different results!
    // digit: number of sig-fig of pi
    // base: can be 8, 10 or 16
    constexpr auto digit = 8;
    constexpr auto base = 16;

    constexpr auto power = 2 * (digit - 1);
    constexpr ld m1 = 1;
    constexpr ld m2 = pow(base, power);

    size_t count = 0;
    // velocity to left < 0
    ld v1 = 0, v2 = -1;
    ld temp_v1;

    // m1 will hit m2 iff v1 > v2;
    // m1 will hit the wall iff v1 < 0;
    while (v1 > v2) {
        if constexpr (SHOW_ARCCOS_V2) {
            cout << acos(v2) << endl;
        }
        // m1 hits m2
        count++;
        // temp_v1 = ((m2 - m1) * v2 + 2 * m1 * v1) / (m1 + m2);
        temp_v1 = ((m1 - m2) / (m1 + m2)) * v1 + (2 * m2 / (m1 + m2)) * v2;

        // m1 goes right after she hits m2
        if (temp_v1 >= 0) break;

        // v2 = ((m1 - m2) * v1 + 2 * m2 * v2) / (m2 + m1);
        v2 = ((m2 - m1) / (m1 + m2)) * v2 + (2 * m1 / (m1 + m2)) * v1;
        // m1 hits the wall and changes the direction of velocity
        v1 = -temp_v1;
        count++;
    }
    cout << "The collision happens" << setbase(base) << count << " times" << endl;

    return 0;
}
