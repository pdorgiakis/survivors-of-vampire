#ifndef COMMAND_H
#define COMMAND_H

#include "../entities/GameActor.h"

class Command {
public:
  virtual ~Command() = default;
  virtual void execute(GameActor *actor) = 0;
};

#endif // !COMMAND_H
