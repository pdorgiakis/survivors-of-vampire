#include "MainPlayer.h"
#include "../core/Assets.h"
#include "GameActor.h"
#include <raylib.h>

MainPlayer::MainPlayer() : GameActor(Assets::load(PLAYER), true) {}

void MainPlayer::moveUp() {};
void MainPlayer::moveDown() {};
void MainPlayer::moveLeft() {
  if (rotation > 0)
    rotation = -rotation;
};
void MainPlayer::moveRight() {
  if (rotation < 0)
    rotation = -rotation;
};
