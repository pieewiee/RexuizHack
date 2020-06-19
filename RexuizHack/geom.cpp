#include "pch.h"
#include "geom.h"
#define PI 3.1415927f



vec3 Subtract(vec3 src, vec3 dst)
{
	vec3 diff;
	diff.x = src.x - dst.x;
	diff.y = src.y - dst.y;
	diff.z = src.z - dst.z;
	return diff;
}

vec3 Divide(vec3 src, float num)
{
	vec3 vec;
	vec.x = src.x / num;
	vec.y = src.y / num;
	vec.z = src.z / num;

	return vec;
}

float Magnitude(vec3 vec)
{
	return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

float DotProduct(vec3 src, vec3 dst)
{
	return src.x * dst.x + src.y * dst.y + src.z * dst.z;
}



//Thanks to c5 for this knowledge
bool WorldToScreen(vec3 src, vec3 dst, vec3& screen, float fovx, float fovy, int windowWidth, int windowHeight, vec3 left, vec3 up, vec3 forward)
{
	vec3 transform;
	float xc, yc;
	float px, py;
	float z;

	float aspect = (float)windowWidth / (float)windowHeight;
	float relfovy = fovy / aspect;

	px = tan(fovx * PI / 360.0);
	py = tan(relfovy * PI / 360.0);

	transform = Subtract(dst, src);

	xc = windowWidth / 2.0;
	yc = windowHeight / 2.0;

	z = DotProduct(transform, left);

	if (z <= 0.1)
	{
		return false;
	}

	screen.x = xc - DotProduct(transform, up) * xc / (z * px);
	screen.y = yc - DotProduct(transform, forward) * yc / (z * py);

	return true;
}



