#include "../include/game_loop.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"
#include "../include/world.h"
#include "../include/bodies/body.h"
#include "../include/instructions/instruction_factory.h"
#include "../include/instructions/instruction.h"
#include <iostream>

GameLoop::GameLoop(
    World *world,
    std::set<Body *> *bodies,
    std::deque<Update> *internal_updates,
    std::deque<Instruction *> *internal_instructions):
    world(world),
    bodies(bodies),
    internal_updates(internal_updates),
    internal_instructions(internal_instructions) {
}

void GameLoop::executeExternalInput(ProtectedQueue<Action> *inputs) {
    InstructionFactory inst_fact;
    Instruction *inst;
    Action action;

    while (inputs->try_pop(action)) {
        inst = inst_fact.createInstruction(
            action,
            *this->world->getChells(),
            this->world);
        inst->execute();
        delete inst;
    }
}

void GameLoop::step() {
    this->worldStep();
    this->applyInternalInstructions();
    this->applyStateActions();
    this->applyInternalInstructions();
    this->createUpdates();
}

void GameLoop::fillUpdates(ProtectedQueue<Update> *ext_updates) {
    while (!this->internal_updates->empty()) {
        Update update = this->internal_updates->front();
        this->internal_updates->pop_front();
        ext_updates->push(update);
    }

    std::list<Update> pins = this->world->getPinUpdateList();
    for (Update &update: pins) {
        ext_updates->push(update);
    }
}

bool GameLoop::isFinished() const {
    return this->world->isFinished();
}

void GameLoop::worldStep() {
    this->world->getB2World()->Step(
        this->TIME_STEP,
        this->VELOCITY_ITERATIONS,
        this->POSITION_ITERATIONS);
}

void GameLoop::applyInternalInstructions() {
    while (!this->internal_instructions->empty()) {
        Instruction *instruction = this->internal_instructions->front();
        this->internal_instructions->pop_front();
        instruction->execute();
        delete instruction;
    }
}

void GameLoop::applyStateActions() {
    for (Body *body: *this->bodies) {
        body->applyStateAction();
    }
}

void GameLoop::createUpdates() {
    for (Body *body: *this->bodies) {
        if (body->isUpdatable()) {
            Update update = body->createUpdate(COMMAND::UPDATE_COMMAND);
            this->internal_updates->emplace_back(update);
        }
    }
}
