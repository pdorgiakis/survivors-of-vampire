#include "Game.h"
#include "../core/InputHandler.h"
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
  InitWindow(Base::instance().configFile["w_width"].get<int>(),
             Base::instance().configFile["w_height"].get<int>(),
             Base::instance().configFile["title"].get<string>().c_str());
  SetTargetFPS(Base::instance().configFile["fps"].get<int>());
}

void Game::Loop() {
  MainPlayer player{};
  InputHandler input_handler{&player};

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    // LOGIC START
    input_handler.handle();
    player.tick(GetFrameTime());
    // LOGIC END
    EndDrawing();
  }
}
void Game::DestroyWindow() {}
