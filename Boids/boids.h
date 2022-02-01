#ifndef BOIDS_BOIDS_H
#define BOIDS_BOIDS_H
#include<array>
#include<cmath>
#include"vector.h"
#include"configuration.h"
constexpr int boids_number = 10;
class Boids
{
	private:
		Vec2 acc = Vec2(0.0, 0.0);
		Vec2 vel = Vec2(0.0, 0.0);
		Vec2 pos = Vec2(0.0, 0.0);
		double radian = 0.0;
public:
	Vec2 separation(const std::array<Boids,boids_number>& boids);
	Vec2 alignment(const std::array<Boids,boids_number>& boids);
	Vec2 cohesion(const std::array<Boids,boids_number>& boids);
	Vec2 getPosition()const;
	void setPosition(const Vec2 new_pos);
	void setVelocity(const Vec2 new_vel);
	double getRadian()const;
	void boidsUpdate(const std::array<Boids, boids_number>& boids);
};

#endif // !BOIDS_BOIDS_H 