#include "Header.h"

EllipticCurve::EllipticCurve() 
{
	group.Initialize(ASN1::secp256r1());
	basePoint = group.GetSubgroupGenerator();
}

ECP::Point EllipticCurve::get_base_point()
{
	return basePoint;
}

bool EllipticCurve::is_on_curve(ECP::Point point)
{
	return group.GetCurve().VerifyPoint(point);
}

ECP::Point EllipticCurve::add_points(ECP::Point a, ECP::Point b)
{
	return group.GetCurve().Add(a, b);
}

ECP::Point EllipticCurve::double_point(ECP::Point point)
{
	return group.GetCurve().Double(point);
}

ECP::Point EllipticCurve::scalar_mult(Integer k, ECP::Point point)
{
	return group.GetCurve().Multiply(k, point);
}

string EllipticCurve::point_to_string(ECP::Point point)
{
	stringstream stream;
	stream << "x: " << point.x << " y: " << point.y;
	return stream.str();
}

ECP::Point EllipticCurve::string_to_point(string str)
{
	str.erase(0, 3);
	size_t pos = str.find(" y: ");

	Integer x(str.substr(0, pos).c_str());
	Integer y(str.substr(pos, str.length()).c_str());

	return ECP::Point(x, y);
}

void EllipticCurve::print_point(ECP::Point point)
{
	cout << "x: " << point.x << " y: " << point.y << endl;
}

bool EllipticCurve::is_equal(ECP::Point a, ECP::Point b)
{
	return a == b;
}
