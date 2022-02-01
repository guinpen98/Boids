#ifndef BOIDS_VEC2_H
#define BOIDS_VEC2_H
struct Vec2
{
	double x = 0, y = 0;

	Vec2() = default;

	Vec2(const double ix, const double iy)
		:x(ix), y(iy) {}

	double magnitude()const {
		return (x * x + y * y );
	}

	Vec2 operator+(const Vec2& coord)const {
		return Vec2(x + coord.x, y + coord.y);
	}
	Vec2 operator-(const Vec2& coord)const {
		return Vec2(x - coord.x, y - coord.y);
	}
	Vec2 operator/(const double n)const {
		return Vec2(x / n, y / n);
	}
};
#endif // !BOIDS_VEC2_H
