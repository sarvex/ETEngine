#include <catch2/catch.hpp>

#include <EtMath/Quaternion.h>


using namespace et;


TEST_CASE("constructors", "[quat]")
{
	SECTION( "default constructor" )
	{
		quat testQuat = quat();
		REQUIRE( testQuat.x == 0 );
		REQUIRE( testQuat.y == 0 );
		REQUIRE( testQuat.z == 0 );
		REQUIRE( testQuat.w == 1 );
	}
	SECTION( "eulerian constructor" )
	{
		vec3 euler = vec3(math::PI, 0, 0);
		quat testQuat = quat(euler);
		REQUIRE( math::nearEqualsV(testQuat.v4, vec4( 1, 0, 0, 0 ), 0.0001f));
	}
	SECTION( "value constructor" )
	{
		quat testQuat = quat(3, 2, 4, 2.4f);
		REQUIRE( testQuat.x == 3 );
		REQUIRE( testQuat.y == 2 );
		REQUIRE( testQuat.z == 4 );
		REQUIRE( testQuat.w == 2.4f );
	}
}
TEST_CASE("axis angles", "[quat]")
{
	float angle = math::PI_DIV4;
	quat testQuat = quat( math::normalize( vec3( -1, -1, 1 ) ), angle );
	SECTION( "from axis angle" )
	{
		REQUIRE( math::nearEqualsV( testQuat.v4, vec4( -0.2209424f, -0.2209424f, 0.2209424f, 0.9238795f ), 0.0001f ) );
	}
	SECTION( "to axis angle" )
	{
		vec4 axisAngle = testQuat.ToAxisAngle();
		REQUIRE( math::nearEqualsV( axisAngle, vec4( math::normalize( vec3( -1, -1, 1 ) ), angle ), 0.0001f ) );
	}
	SECTION( "use axis angle quat for rotation" )
	{
		vec3 initial = vec3( 0, 1, 0 );
		quat testQuat2 = quat( vec3( 1, 0, 0 ), math::PI_DIV2 );
		vec3 rotated2 = testQuat2 * initial;
		REQUIRE( math::nearEqualsV( rotated2, vec3( 0, 0, 1 ), 0.0001f ) );
	}
}
TEST_CASE( "quaternion multiplication", "[quat]" )
{
	quat R1 = quat( vec3( 0, 0, 1 ), math::PI_DIV2 );
	quat R2 = quat( vec3( 0, 1, 0 ), math::PI_DIV2 );

	SECTION( "quat mul quat" )
	{
		quat testQuat = R2 * R1; // #todo invert multiplication order in implementation

		vec3 initial = vec3( 0, 1, 0 );
		vec3 rotated = testQuat * initial;

		REQUIRE( math::nearEqualsV( rotated, vec3( 0, 0, 1 ), 0.0001f ) );
	}
	SECTION( "inverse" )
	{
		quat testQuat = R1 * math::inverse(R1) * R2;

		REQUIRE( math::nearEqualsV( R2.v4, testQuat.v4, 0.0001f ) );
	}
	SECTION( "conjugate" )
	{
		quat testQuat = R1 * math::inverse(R1) * R2;

		REQUIRE( math::nearEqualsV( R2.v4, testQuat.v4, 0.0001f ) );
	}
	SECTION( "inverse" )
	{
		REQUIRE( math::nearEqualsV( math::inverse(R1).v4, math::inverseSafe(R1).v4, 0.0001f ) );
	}
}
TEST_CASE( "matrix compatibility", "[quat]" )
{
	quat R1 = quat( vec3( 0, 0, 1 ), math::PI_DIV2 );
	mat3 r1m = R1.ToMatrix();
	mat3 tMat( {	 0, 1, 0,
					-1, 0, 0,
					 0, 0, 1 } );

	SECTION( "to mat 3" )
	{
		REQUIRE( math::nearEqualsM( r1m, tMat, 0.00001f ) );
	}
	SECTION( "equal rotation" )
	{
		vec3 initV = vec3( 0, 1, 0 );
		vec3 qRot = R1 * initV;
		vec3 mRot = r1m * initV;
		REQUIRE( math::nearEqualsV( qRot, mRot, 0.0001f ) );
	}
	SECTION("from mat 3")
	{
		quat m2q(tMat);
		vec3 initV = vec3(0, 1, 0);
		vec3 qRot = m2q * initV;
		vec3 mRot = tMat * initV;
		REQUIRE(math::nearEqualsV(qRot, mRot, 0.0001f));
	}
}