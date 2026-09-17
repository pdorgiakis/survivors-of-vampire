#ifndef COMMANDS_H
#define COMMANDS_H

#include "../../entities/GameActor.h"
#include "../Command.h"

class MoveLeftCommand : public Command {
public:
  virtual void execute(GameActor *actor) { actor->moveLeft(); }
};
class MoveRightCommand : public Command {
public:
  virtual void execute(GameActor *actor) { actor->moveRight(); }
};

class MoveUpCommand : public Command {
public:
  virtual void execute(GameActor *actor) { actor->moveUp(); }
};
class MoveDownCommand : public Command {
public:
  virtual void execute(GameActor *actor) { actor->moveDown(); }
};
#endif // !COMMANDS_H
