#ifndef __GAME_LOOP_H__
#define __GAME_LOOP_H__

#include <cstdint>
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"

#include <set>
#include <deque>
#include <map>

class World;
class Action;
class Chell;
class Body;
class Instruction;

class GameLoop {
private:
    World *world;
    std::set<Body *> *bodies;
    std::deque<Update> *internal_updates;
    std::deque<Instruction *> *internal_instructions;
    const float TIME_STEP = 1/(20.0 * FPS_FACTOR);
    const uint32_t VELOCITY_ITERATIONS = 50;
    const uint32_t POSITION_ITERATIONS = 50;

public:
    /* Instancia un controlador de game loop para world */
    GameLoop(
        World *world,
        std::set<Body *> *bodies,
        std::deque<Update> *internal_updates,
        std::deque<Instruction *> *internal_instructions);

    /* Ejecuta input externo */
    void executeExternalInput(ProtectedQueue<Action> *inputs);

    /* Genera una simulacion */
    void step();

    /* Rellena con uodates a ext_updates */
    void fillUpdates(ProtectedQueue<Update> *ext_updates);

    /* Indica si el juego esta terminado */
    bool isFinished() const;

private:
    /* Genera una simulacion de world */
    void worldStep();

    /* Aplica instrucciones dadas por los mismos bodies*/
    void applyInternalInstructions();

    /* Aplica instrucciones de estado sobre los bodies */
    void applyStateActions();

    /* Crea updates para cada body */
    void createUpdates();
};

#endif
