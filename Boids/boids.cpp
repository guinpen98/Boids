#include "boids.h"
Vec2 Boids::separation(const std::array<Boids, boids_number>& boids){
	Vec2 sep_vec = Vec2(0.0, 0.0);
	int cnt = 0;
	for (const auto& boid : boids) {
		if (pos.distance(boid.getPosition()) > window_w * window_h / 16) continue;
		Vec2 dif = pos - boid.pos;
		if (dif.magnitude() == 0.0) continue;
		cnt++;
		sep_vec = sep_vec + (dif / dif.magnitude());
	}
	if (cnt == 0) return Vec2(0.0,0.0);
	return sep_vec / cnt;
}
Vec2 Boids::alignment(const std::array<Boids, boids_number>& boids) {
	Vec2 align_vec = Vec2(0.0, 0.0);
	int cnt = 0;
	for (const auto& boid : boids) {
		if (pos.distance(boid.getPosition()) > window_w * window_h / 16) continue;
		cnt++;
		align_vec = align_vec + boid.vel;
	}
	if (cnt != 0) align_vec = align_vec / cnt;
	return align_vec - vel;
}
Vec2 Boids::cohesion(const std::array<Boids, boids_number>& boids) {
	Vec2 cohe_pos = Vec2(0.0, 0.0);
	int cnt = 0;
	for (const auto& boid : boids) {
		if (pos.distance(boid.getPosition()) > window_w * window_h / 16) continue;
		cnt++;
		cohe_pos = cohe_pos + boid.pos;
	}
	if (cnt != 0) cohe_pos = cohe_pos / cnt;
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
	acc = (separation(boids) * 40) + (alignment(boids) * 0.72) + (cohesion(boids) * 0.008);
	if (pos.x < window_w / 8 && acc.x < 0) acc = Vec2(-acc.x, acc.y);
	if (pos.x > window_w / 8 * 7 && acc.x > 0) acc = Vec2(-acc.x, acc.y);
	if (pos.y < window_h / 8 && acc.y < 0) acc = Vec2(acc.x, -acc.y);
	if (pos.y > window_h / 8 * 7 && acc.y > 0) acc = Vec2(acc.x, -acc.y);
	vel = vel + acc;
	if (pos.x < window_w /16 && vel.x < 0) vel = Vec2(vel.x / 1.1, vel.y);
	if (pos.x > window_w * 15 / 16 && vel.x > 0) vel = Vec2(vel.x / 1.1, vel.y);
	if (pos.y < window_h / 16 && vel.y < 0) vel = Vec2(vel.x, vel.y / 1.1);
	if (pos.y > window_h * 15 / 16 && vel.y > 0) vel = Vec2(vel.x, vel.y / 1.1);
	//Vec2 vec = vel + (acc / 2.0);
	Vec2 vec = vel;
	pos = pos + vec;
	radian = std::atan2(vec.y,vec.x);
}