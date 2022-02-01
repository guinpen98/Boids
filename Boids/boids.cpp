#include "boids.h"
Vec2 Boids::separation(const std::array<Boids, boids_number>& boids){
	Vec2 sep_vec = Vec2(0.0, 0.0);
	for (const auto& boid : boids) {
		if (pos.distance(boid.getPosition()) > window_w * window_h / 64) continue;
		Vec2 dif = pos - boid.pos;
		if (dif.magnitude() == 0.0) continue;
		sep_vec = sep_vec + (dif / dif.magnitude());
	}
	return sep_vec / boids_number;
}
Vec2 Boids::alignment(const std::array<Boids, boids_number>& boids) {
	Vec2 align_vec = Vec2(0.0, 0.0);
	for (const auto& boid : boids) {
		if (pos.distance(boid.getPosition()) > window_w * window_h / 64) continue;
		align_vec = align_vec + boid.vel;
	}
	align_vec = align_vec / boids_number;
	return align_vec - vel;
}
Vec2 Boids::cohesion(const std::array<Boids, boids_number>& boids) {
	Vec2 cohe_pos = Vec2(0.0, 0.0);
	for (const auto& boid : boids) {
		if (pos.distance(boid.getPosition()) > window_w * window_h / 64) continue;
		cohe_pos = cohe_pos + boid.pos;
	}
	cohe_pos = cohe_pos / boids_number;
	return cohe_pos - pos;
}
Vec2 Boids::getPosition()const {
	return pos;
}
void Boids::setPosition(const Vec2 new_pos) {
	pos = new_pos;
}
void Boids::setVelocity(const Vec2 new_vel) {
	vel = new_vel;
}
double Boids::getRadian()const {
	return radian;
}
void Boids::boidsUpdate(const std::array<Boids, boids_number>& boids) {
	acc = (separation(boids) * 2) + (alignment(boids) * 0.1) + (cohesion(boids) * 0.001);
	if (pos.x < window_w / 8 && acc.x < 0) acc = Vec2(-acc.x, acc.y);
	if (pos.x > window_w / 8 * 7 && acc.x > 0) acc = Vec2(-acc.x, acc.y);
	if (pos.y < window_h / 8 && acc.y < 0) acc = Vec2(acc.x, -acc.y);
	if (pos.y > window_h / 8 * 7 && acc.y > 0) acc = Vec2(acc.x, -acc.y);
	vel = vel + (acc * 2);
	if (pos.x < window_w /16 && vel.x < 0) vel = Vec2(vel.x / 1.1, vel.y);
	if (pos.x > window_w * 15 / 16 && vel.x > 0) vel = Vec2(vel.x / 1.1, vel.y);
	if (pos.y < window_h / 16 && vel.y < 0) vel = Vec2(vel.x, vel.y / 1.1);
	if (pos.y > window_h * 15 / 16 && vel.y > 0) vel = Vec2(vel.x, vel.y / 1.1);
	//Vec2 vec = vel + (acc / 2.0);
	Vec2 vec = vel + acc;
	pos = pos + vec;
	radian = std::atan2(vec.y,vec.x);
}