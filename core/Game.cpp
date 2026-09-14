#include "Game.h"
#include "../entities/MainPlayer.h"
#include "raylib.h"
#include <fstream>
#include <raylib.h>

void Game::Start() {
  CreateWindow();
  InitAudioDevice();
  Loop();
  CloseAudioDevice();
  CloseWindow();
}

void Game::CreateWindow() {
  InitWindow(configFile["w_width"].get<int>(),
             configFile["w_height"].get<int>(),
             configFile["title"].get<string>().c_str());
  SetTargetFPS(configFile["fps"].get<int>());
}

void Game::Loop() {
  MainPlayer player{};
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    // LOGIC START
    // LOGIC END
    EndDrawing();
  }
}
void Game::DestroyWindow() {}
