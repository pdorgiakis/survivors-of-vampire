#include "MainPlayer.h"
#include "../core/Assets.h"
#include "GameActor.h"
#include <raylib.h>

MainPlayer::MainPlayer() : GameActor(Assets::load(PLAYER), true) {}
