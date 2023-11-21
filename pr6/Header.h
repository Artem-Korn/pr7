#pragma once
#include <iostream>

#include <cryptopp/integer.h>
#include <cryptopp/ecp.h>
#include <cryptopp/osrng.h>
#include <cryptopp/oids.h>
#include "cryptopp/eccrypto.h"

using namespace std;
using namespace CryptoPP;

class EllipticCurve
{
	DL_GroupParameters_EC<ECP> group;
	ECP::Point basePoint;

public:
	EllipticCurve();
	ECP::Point get_base_point();
	bool is_on_curve(ECP::Point);
	ECP::Point add_points(ECP::Point, ECP::Point);
	ECP::Point double_point(ECP::Point);
	ECP::Point scalar_mult(Integer, ECP::Point);
	string point_to_string(ECP::Point);
	ECP::Point string_to_point(string);
	void print_point(ECP::Point);
	bool is_equal(ECP::Point, ECP::Point);
};