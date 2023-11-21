#include "Header.h"

int main()
{
    EllipticCurve eliptic_curve;
    AutoSeededRandomPool rng;
    size_t bitCount = 9;

    // test get_base_point
    ECP::Point G = eliptic_curve.get_base_point();
    cout << "G (secp256r1) = " << eliptic_curve.point_to_string(G) << "\n\n";

    // test scalar_mult
    Integer k(rng, bitCount), d(rng, bitCount);

    cout << "k = " << k << "\n\n";
    cout << "d = " << d << "\n\n";

    ECP::Point H1 = eliptic_curve.scalar_mult(d, G);
    ECP::Point H2 = eliptic_curve.scalar_mult(k, H1);

    ECP::Point H3 = eliptic_curve.scalar_mult(k, G);
    ECP::Point H4 = eliptic_curve.scalar_mult(d, H3);

    cout << "k*(d*G) = H2 = " << eliptic_curve.point_to_string(H2) << "\n\n";
    cout << "d*(k*G) = H4 = " << eliptic_curve.point_to_string(H4) << "\n\n";

    // test point_to_string
    string test_str = eliptic_curve.point_to_string(H4);
    cout << "point_to_string (H4): " << test_str << "\n\n";

    // test string_to_point and print_point
    cout << "string_to_point and print_point (H4): ";
    eliptic_curve.print_point(eliptic_curve.string_to_point(test_str));

    // test is_equal
    cout << "\nis_equal (H2,H4): " << eliptic_curve.is_equal(H2, H4) << "\n\n";

    // test is_on_curve
    cout << "is_on_curve (H4): " << eliptic_curve.is_on_curve(H4) << "\n\n";

    // test add_points and double_point
    cout << "add_points (H2,H4): " << eliptic_curve.point_to_string(eliptic_curve.add_points(H2, H4)) << "\n\n";
    cout << "double_point (H4): " << eliptic_curve.point_to_string(eliptic_curve.double_point(H4)) << "\n\n";
}