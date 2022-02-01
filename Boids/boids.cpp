#include "boids.h"
Vec2 Boids::separation(const std::array<Boids, boids_number>& boids){
	Vec2 sep_vec = Vec2(0.0, 0.0);
	for (const auto& boid : boids) {
		Vec2 dif = vel - boid.vel;
		sep_vec = sep_vec + (dif / dif.magnitude());
	}
	return sep_vec / boids_number;
}
Vec2 Boids::alignment(const std::array<Boids, boids_number>& boids) {
	Vec2 align_vec = Vec2(0.0, 0.0);
	for (const auto& boid : boids) {
		align_vec = align_vec + boid.vel;
	}
	align_vec = align_vec / boids_number;
	return align_vec - vel;
}
Vec2 Boids::cohesion(const std::array<Boids, boids_number>& boids) {
	Vec2 cohe_pos = Vec2(0.0, 0.0);
	for (const auto& boid : boids) {
		cohe_pos = cohe_pos + boid.pos;
	}
	cohe_pos = cohe_pos / boids_number;
	return cohe_pos - pos;
}
void Boids::boidsUpdate(const std::array<Boids, boids_number>& boids) {
	acc = separation(boids) + alignment(boids) + cohesion(boids);
	vel = vel + acc;
	pos = pos + vel + (acc / 2.0);
}