#include "Game.h"
#include "raylib.h"
#include <fstream>
#include <raylib.h>

Game::Game() { LoadConfiguration(); }

void Game::LoadConfiguration() {
  std::ifstream c("../config/config.json");
  configFile = json::parse(c);
}

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
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    // LOGIC START
    // LOGIC END
    EndDrawing();
  }
}
void Game::DestroyWindow() {}
