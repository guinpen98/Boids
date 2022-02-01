#include "draw.h"

void drawBoids(const std::array<Boids, boids_number>& boids) {
	for (auto& boid : boids) {
		double x = boid.getPosition().x,y = boid.getPosition().y,rad = boid.getRadian();
		DrawTriangle(int(x + std::cos(rad)*5), int(y + std::sin(rad)*5), int(x + std::cos(rad + M_PI * 2 / 3)*5), int(y + std::sin(rad + M_PI * 2 / 3)*5), int(x + std::cos(rad + M_PI * 4 / 3)*5), int(y + std::sin(rad + M_PI * 4 / 3)*5), GetColor(255, 255, 0), TRUE);

	}
}