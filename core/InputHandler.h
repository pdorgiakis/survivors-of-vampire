#include "../entities/MainPlayer.h"
#include "./commands/Commands.h"
#include "raylib.h"

class InputHandler {
public:
  InputHandler(MainPlayer *target) : target(target) {}
  void handle();

private:
  MainPlayer *target;

  MoveUpCommand *move_up = new MoveUpCommand();
  MoveDownCommand *move_down = new MoveDownCommand();
  MoveLeftCommand *move_left = new MoveLeftCommand();
  MoveRightCommand *move_right = new MoveRightCommand();
};
