#include "InputHandler.h"
#include "commands/Commands.h"

void InputHandler::handle() {
  std::cout << move_down << std::endl;
  bool moved = false;
  if (IsKeyDown(KEY_W)) {
    move_up->execute(target);
    moved = true;
  }
  if (IsKeyDown(KEY_S)) {
    move_down->execute(target);
    moved = true;
  }
  if (IsKeyDown(KEY_A)) {
    move_left->execute(target);
    moved = true;
  }
  if (IsKeyDown(KEY_D)) {
    move_right->execute(target);

    moved = true;
  }
  if (moved) {
    target->setState(WALK);
  } else {
    target->setState(IDLE);
  }
}
