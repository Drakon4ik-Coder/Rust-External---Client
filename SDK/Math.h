#pragma once
#include <math.h>
#define powFFFFFFFFFFFFFFFFFFFFFF(n) (n)*(n)
class Vector3
{
public:
	float x, y, z;

	float Magnitude()
	{
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}


	/* Used to normalize this vector */
	Vector3 Normalized()
	{
		/* Get the magnitude of this vector */
		float num = this->Magnitude();

		/* Check if number is more than max. */
		if (num > 9.99999974737875E-06)
		{
			return { this->x / num, this->y / num, this->z / num };
		}

		/* Return an empty vector */
		return Vector3();
	}

	inline Vector3() {
		x = y = z = 0.0f;
	}

	inline Vector3(float X, float Y, float Z) {
		x = X; y = Y; z = Z;
	}

	inline float operator[](int i) const {
		return ((float*)this)[i];
	}

	inline Vector3& operator-=(float v) {
		x -= v; y -= v; z -= v; return *this;
	}

	inline Vector3 operator*(float v) const {
		return Vector3(x * v, y * v, z * v);
	}

	inline Vector3 operator/(float v) const
	{
		return Vector3(x / v, y / v, z / v);
	}

	inline Vector3& operator+=(const Vector3& v) {
		x += v.x; y += v.y; z += v.z; return *this;
	}

	inline Vector3 operator-(const Vector3& v) const {
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	inline Vector3 operator+(const Vector3& v) const {
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	inline Vector3& operator-=(const Vector3& v) {
		x -= v.x; y -= v.y; z -= v.z; return *this;
	}

	inline float Length() {
		return sqrtf(x * x + y * y + z * z);
	}
};
struct Quaternion {
	float x, y, z, w;
	Vector3 operator *(Vector3 point)
	{
		float num = this->x * 2.f;
		float num2 = this->y * 2.f;
		float num3 = this->z * 2.f;
		float num4 = this->x * num;
		float num5 = this->y * num2;
		float num6 = this->z * num3;
		float num7 = this->x * num2;
		float num8 = this->x * num3;
		float num9 = this->y * num3;
		float num10 = this->w * num;
		float num11 = this->w * num2;
		float num12 = this->w * num3;
		Vector3 result;
		result.x = (1.f - (num5 + num6)) * point.x + (num7 - num12) * point.y + (num8 + num11) * point.z;
		result.y = (num7 + num12) * point.x + (1.f - (num4 + num6)) * point.y + (num9 - num10) * point.z;
		result.z = (num8 - num11) * point.x + (num9 + num10) * point.y + (1.f - (num4 + num5)) * point.z;
		return result;
	}
};
class Vector2 {
public:
	float x, y;

	inline Vector2() {
		x = y = 0.0f;
	}

	inline Vector2 operator/(float v) const {
		return Vector2(x / v, y / v);
	}
	inline Vector2(float X, float Y) {
		x = X; y = Y;
	}

	inline Vector2 operator-(const Vector2& v) const {
		return Vector2(x - v.x, y - v.y);
	}

	inline Vector2 operator+(const Vector2& v) const {
		return Vector2(x + v.x, y + v.y);
	}

	inline Vector2& operator+=(const Vector2& v) {
		x += v.x; y += v.y; return *this;
	}

	inline bool Zero() const {
		return (x > -0.1f && x < 0.1f && y > -0.1f && y < 0.1f);
	}
};

class Vector4 {
public:
	float x, y, z, w;
};

struct Matrix4x4 {
	union {
		struct {
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;

		}; float m[4][4];
	};
};

namespace Math
{
#define M_PI 3.14159265358979323846f
#define M_RADPI	57.295779513082f
#define M_PI_F ((float)(M_PI))
#define RAD2DEG(x) ((float)(x) * (float)(180.f / M_PI_F))
#define DEG2RAD(x) ((float)(x) * (float)(M_PI_F / 180.f))
#define atan2(a, b) ((float)atan2((double)(a), (double)(b)))
	static volatile const double Infinity = INFINITY;
	typedef struct { double d0, d1; } double2;


	static inline double2 Add212RightSmaller(double2 a, double b)
	{
		double
			c0 = a.d0 + b,
			c1 = a.d0 - c0 + b + a.d1,
			d0 = c0 + c1,
			d1 = c0 - d0 + c1;
		return double2{ d0, d1 };
	}

	static inline double Add221RightSmaller(double2 a, double2 b)
	{
		double
			c0 = a.d0 + b.d0,
			c1 = a.d0 - c0 + b.d0 + b.d1 + a.d1,
			d0 = c0 + c1;
		return d0;
	}

	float abs(float a) {
		if (a < 0.f) return -a;
		else return a;
	}

	float asin(float x) {
		float negate = float(x < 0);
		x = abs(x);
		float ret = -0.0187293;
		ret *= x;
		ret += 0.0742610;
		ret *= x;
		ret -= 0.2121144;
		ret *= x;
		ret += 1.5707288;
		ret = 3.14159265358979 * 0.5 - sqrt(1.0 - x) * ret;
		return ret - 2 * negate * ret;
	}

	__forceinline float Dot(const Vector3& Vec1, const Vector3& Vec2) {
		return Vec1[0] * Vec2[0] + Vec1[1] * Vec2[1] + Vec1[2] * Vec2[2];
	}

	__forceinline float Calc3D_Dist(const Vector3& Src, const Vector3& Dst) {
		return sqrtf(pow((Src.x - Dst.x), 2) + pow((Src.y - Dst.y), 2) + pow((Src.z - Dst.z), 2));
	}

	__forceinline float Calc2D_Dist(const Vector2& Src, const Vector2& Dst) {
		return sqrt(powf(Src.x - Dst.x, 2) + powf(Src.y - Dst.y, 2));
	}

	__forceinline Vector2 CalcAngle(const Vector3& Src, const Vector3& Dst) {
		Vector3 dir = Src - Dst;
		return Vector2{ RAD2DEG(asin(dir.y / dir.Length())), RAD2DEG(-atan2(dir.x, -dir.z)) };
	}

}

namespace AimVec
{


	class Vector2
	{
	public:
		float x, y;

		__forceinline Vector2()
		{
			x = y = 0.0f;
		}

		__forceinline Vector2(float X, float Y)
		{
			x = X; y = Y;
		}

		float distance(Vector2 b)
		{
			return sqrt(powFFFFFFFFFFFFFFFFFFFFFF(b.x - x, 2) + powFFFFFFFFFFFFFFFFFFFFFF(b.y - y, 2));
		}


		__forceinline Vector2 operator+(float v) const
		{
			return Vector2(x + v, y + v);
		}

		__forceinline Vector2 operator-(float v) const
		{
			return Vector2(x - v, y - v);
		}

		__forceinline Vector2& operator+=(float v)
		{
			x += v; y += v; return *this;
		}

		__forceinline Vector2& operator*=(float v)
		{
			x *= v; y *= v; return *this;
		}

		__forceinline Vector2& operator/=(float v)
		{
			x /= v; y /= v; return *this;
		}

		__forceinline Vector2 operator-(const Vector2& v) const
		{
			return Vector2(x - v.x, y - v.y);
		}

		__forceinline Vector2 operator+(const Vector2& v) const
		{
			return Vector2(x + v.x, y + v.y);
		}

		__forceinline Vector2& operator+=(const Vector2& v)
		{
			x += v.x; y += v.y; return *this;
		}

		__forceinline Vector2& operator-=(const Vector2& v) {
			x -= v.x; y -= v.y; return *this;
		}

		__forceinline Vector2 operator/(float v) const {
			return Vector2(x / v, y / v);
		}

		__forceinline Vector2 operator*(float v) const {
			return Vector2(x * v, y * v);
		}

		__forceinline Vector2 operator/(const Vector2& v) const {
			return Vector2(x / v.x, y / v.y);
		}

		__forceinline bool Zero() const {
			return (x > -0.1f && x < 0.1f && y > -0.1f && y < 0.1f);
		}



	};



	class Vector3
	{
	public:

		inline static float sqrtf(float number)
		{
			long i;
			float x2, y;
			const float threehalfs = 1.5F;

			x2 = number * 0.5F;
			y = number;
			i = *(long*)&y;
			i = 0x5f3759df - (i >> 1);
			y = *(float*)&i;
			y = y * (threehalfs - (x2 * y * y));
			y = y * (threehalfs - (x2 * y * y));

			return 1 / y;
		}

		float distance(Vector3 vec)
		{
			return sqrt(
				powFFFFFFFFFFFFFFFFFFFFFF(vec.x - x, 2) +
				powFFFFFFFFFFFFFFFFFFFFFF(vec.y - y, 2)
			);
		}

		Vector3()
		{
			x = y = z = 0.f;
		}

		Vector3(float fx, float fy, float fz)
		{
			x = fx;
			y = fy;
			z = fz;
		}

		inline float operator[](int i) const {
			return ((float*)this)[i];
		}

		inline float Length() const
		{
			return sqrt((x * x) + (y * y) + (z * z));
		}

		float x, y, z;

		Vector3 operator+(const Vector3& input) const
		{
			return Vector3{ x + input.x, y + input.y, z + input.z };
		}

		Vector3 operator-(const Vector3& input) const
		{
			return Vector3{ x - input.x, y - input.y, z - input.z };
		}

		Vector3 operator/(float input) const
		{
			return Vector3{ x / input, y / input, z / input };
		}

		Vector3 operator*(float input) const
		{
			return Vector3{ x * input, y * input, z * input };
		}

		Vector3& operator+=(const Vector3& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;

			return *this;
		}

		Vector3& operator-=(const Vector3& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;

			return *this;
		}

		Vector3& operator/=(float input)
		{
			x /= input;
			y /= input;
			z /= input;
			return *this;
		}

		Vector3& operator*=(float input)
		{
			x *= input;
			y *= input;
			z *= input;
			return *this;
		}

		Vector3 midPoint(Vector3 v2)
		{
			return Vector3((x + v2.x) / 2, (y + v2.y) / 2, (z + v2.z) / 2);
		}

		bool operator==(const Vector3& input) const
		{
			return x == input.x && y == input.y && z == input.z;
		}



		float clamp0to1(float value)
		{
			float result;
			if (value < 0)
			{
				result = 0;
			}
			else if (value > 1.f)
			{
				result = 1.f;
			}
			else
			{
				result = value;
			}
			return result;
		}

		float Lerp()
		{
			return x + (y - x) * clamp0to1(z);
		}

		float length_sqr() const
		{
			return (x * x) + (y * y) + (z * z);
		}

		float length() const
		{
			return (float)sqrt(length_sqr());
		}

		float length_2d() const
		{
			return (float)sqrt((x * x) + (y * y));
		}

		auto length() -> float { return sqrtf((x * x) + (y * y) + (z * z)); }

		Vector3 normalized()
		{
			float len = length();
			return Vector3(x / len, y / len, z / len);
		}

		Vector3 cross(Vector3 rhs)
		{
			return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
		}


		float dot(Vector3 input) const
		{
			return (x * input.x) + (y * input.y) + (z * input.z);
		}



		auto empty() -> bool { return x == 0.000000 && y == 0.000000 && z == 0.000000; }

		bool is_valid() const
		{
			return !(x == 0.f && y == 0.f && z == 0.f) || (x == -1.f && y == -1.f && z == -1.f);
		}



	};



	float to_degree(float radian)
	{
		return radian * 180.f / 3.141592f;
	}

	float Length(Vector3 v) {
		return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	}
	static bool Normalize(float& Yaw, float& Pitch) {
		//Vector2 CurrentViewAngles = LocalPlayer.BasePlayer->GetVA();
		if (Pitch < -89)
			//Pitch = -89;
			return false;

		else if (Pitch > 89)
			//Pitch = 89;
			return false;

		if (Yaw < -360)
			/*Yaw += 360;*/
			return false;

		else if (Yaw > 360)
			//Yaw -= 360;
			return false;
	}
	static Vector3 CalcAngle(Vector3 LocalPos, Vector3 EnemyPos)
	{
		Vector3 dir;

		dir.x = LocalPos.x - EnemyPos.x;
		dir.y = LocalPos.y - EnemyPos.y;
		dir.z = LocalPos.z - EnemyPos.z;

		float Pitch = to_degree(asin(dir.y / Length(dir)));
		float Yaw = to_degree(-atan2(dir.x, -dir.z));


		Vector3 Return;
		Return.x = Pitch;
		Return.y = Yaw;


		return Return;
	}

	class Vector4
	{
	public:
		Vector4()
		{
			x = y = z = w = 0.f;
		}

		Vector4(float fx, float fy, float fz, float fw)
		{
			x = fx;
			y = fy;
			z = fz;
			w = fw;
		}

		float x, y, z, w;


	};


	__forceinline float Dot(const Vector3& Vec1, const Vector3& Vec2) {
		return Vec1[0] * Vec2[0] + Vec1[1] * Vec2[1] + Vec1[2] * Vec2[2];
	}

	struct Matrix4x4 {
		union {
			struct {
				float        _11, _12, _13, _14;
				float        _21, _22, _23, _24;
				float        _31, _32, _33, _34;
				float        _41, _42, _43, _44;
			}; float m[4][4];
		};
	}; inline Matrix4x4 pViewMatrix;


#define pow(n) (n)*(n)

	float Calc3D_Dist(const Vector3& Src, const Vector3& Dst) {
		return Vector3::sqrtf(pow(Src.x - Dst.x) + pow(Src.y - Dst.y) + pow(Src.z - Dst.z));
	}

#pragma once
#include <Windows.h>
#include <map>
#include <d3dx9.h>
#include <d3d9types.h>
#include <vector>
#include <cmath>
#include <math.h>

#define M_PI 3.14159265358979323846264338327950288419716939937510

	struct FMinimalViewInfo2 {
		Vector2 Location; // 0x00(0x0c)
		Vector2 Rotation; // 0x0c(0x0c)
		float FOV; // 0x18(0x04)
	};

	float deg_2_rad(float degrees)
	{
		float radians;
		radians = degrees * (M_PI / 180);
		return radians;
	}
	void angle_vectors(const Vector3& angles, Vector3* forward)
	{
		float    sp, sy, cp, cy;
		sy = sin(deg_2_rad(angles.y));
		cy = cos(deg_2_rad(angles.y));
		sp = sin(deg_2_rad(angles.x));
		cp = cos(deg_2_rad(angles.x));
		forward->x = cp * cy;
		forward->y = cp * sy;
		forward->z = -sp;
	}
	float DegreeToRadian(float degree)
	{
		return degree * (M_PI / 180);

	}


	Vector2 WorldRadar(Vector3 srcPos, Vector3 distPos, float yaw, float radarX, float radarY, float size)
	{
		auto cosYaw = cos(DegreeToRadian(yaw));
		auto sinYaw = sin(DegreeToRadian(yaw));

		auto deltaX = srcPos.x - distPos.x;
		auto deltaY = srcPos.y - distPos.y;

		auto locationX = (float)(deltaY * cosYaw - deltaX * sinYaw) / 15.f;
		auto locationY = (float)(deltaX * cosYaw + deltaY * sinYaw) / 15.f;

		if (locationX > (size - 2.f))
			locationX = (size - 2.f);
		else if (locationX < -(size - 2.f))
			locationX = -(size - 2.f);

		if (locationY > (size - 6.f))
			locationY = (size - 6.f);
		else if (locationY < -(size - 6.f))
			locationY = -(size - 6.f);

		return Vector2((int)(-locationX + radarX), (int)(locationY + radarY));
	}
}