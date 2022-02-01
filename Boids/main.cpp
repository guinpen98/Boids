#include "main.h"
bool Update() { return (DxLib::ScreenFlip() != -1 && DxLib::ClearDrawScreen() != -1 && DxLib::ProcessMessage() != -1); }

void Main() {
	while (Update()) {
		
	}
}