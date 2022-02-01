#include "main.h"
bool Update() { return (DxLib::ScreenFlip() != -1 && DxLib::ClearDrawScreen() != -1 && DxLib::ProcessMessage() != -1); }

void Main() {
	std::array<Boids, boids_number> boids;

	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> w_distr(10, window_w - 10);
	std::uniform_int_distribution<int> h_distr(10, window_h - 10);
	std::uniform_real_distribution<double> vel_distr(0.0, 1.0);
	
	for (size_t i = 0; i < boids_number; i++) {
		boids[i].setPosition(Vec2(w_distr(eng), h_distr(eng)));
		boids[i].setVelocity(Vec2(vel_distr(eng), vel_distr(eng)));
	}
	while (Update()) {
		for (auto& boid : boids)
			boid.boidsUpdate(boids);
		drawBoids(boids);
	}
}