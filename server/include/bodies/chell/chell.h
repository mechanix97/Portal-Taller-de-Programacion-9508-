#ifndef __CHELL_H__
#define __CHELL_H__

#include "chell_def.h"
#include "../body.h"
#include "chell_state.h"
#include "idle_state.h"
#include "running_state.h"
#include "jumping_state.h"
#include "dead_state.h"
#include "fire_state.h"
#include "fire_to_idle_state.h"
#include "jiging_state.h"
#include "falling_state.h"
#include "landing_state.h"
#include "turning_state.h"
#include "stopping_state.h"
#include "../../../../common/include/key.h"
#include "../../../../common/include/keypad.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/Joints/b2Joint.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../portal/portal_gun.h"

#define JUMPSPEED 5
#define LEFTSPEED 1.2
#define RIGHTSPEED 1.2
#define MAX_HORIZONTAL_SPEED 4
#define RAY_ZOOM 10000

class World;
class Acid;
class Button;
class Block;
class Gate;
class Portal;
class Launcher;
class Receiver;
class Cake;
class Rock;
class Bullet;

class Chell: public Body {
private:
    bool is_facing_right;
    IdleState idle_state;
    RunningState running_state;
    JumpingState jumping_state;
    DeadState dead_state;
    FireState fire_state;
    FireToIdleState fire_to_idle_state;
    JigingState jiging_state;
    FallingState falling_state;
    LandingState landing_state;
    TurningState turning_state;
    StoppingState stopping_state;
    ChellState *state;
    PortalGun portal_gun;
    bool is_in_grabbing_mode;
    b2Joint *joint;
    ChellDef def;
    Keypad keypad;
    const float WIDTH = 1.00;
    const float HEIGHT = 2.00;
    const float DENSITY = 1;
    const float ANGLE = 0;
    const float FRICTION = 0.5;
    const float RESTITUTION = 0.00;

public:
    /* Instancia a chell de id 'body_id' sobre world en la
     * posicion (x, y) mirando a la derecha en estado idle. */
    Chell(World *world, float x, float y);

    /* Libera los recursos utilizados */
    ~Chell();

    /* Dispara el primer portal a (x, y) */
    void firePortalOne(float x, float y);

    /* Dispara el segundo portal a (x, y) */
    void firePortalTwo(float x, float y);

    /* Indica si alcanzo la maxima rapidez para correr. */
    bool hasReachedMaxHorizontalSpeed() const;

    /* Indica si chell mantiene una roca */
    bool isGrabbingARock() const;

    /* Suelta una roca */
    void releaseRock();

    /* Toma una roca */
    void grabRock(Rock *rock);

    /* Indica si chell esta en grabbing mode, es decir, esta en modo de tomar
     * una roca*/
    bool isInGrabbingMode() const;

    /* Entra en grabbing mode */
    void enterGrabbingMode();

    /* Sale de grabbing mode */
    void exitGrabbingMode();

    /* Devuelve un puntero a la portal gun */
    PortalGun *getPortalGun();

    /* Indica si chell esta mirando hacia la derecha */
    bool isFacingRight() const;

    /* Indica si chell esta mirando hacia la izquierda */
    bool isFacingLeft() const;

    /* Hace mirar a la derecha */
    void faceRight();

    /* Hace mirar a la izquierda */
    void faceLeft();

    /* Hace mirar en la direccion opuesta */
    void faceOppositeDirection();

    /* Devuelve un update de Command de chell */
    virtual Update createUpdate(COMMAND command) const override;

/* Presiona el boton de jig (bailar) */
    void jig();

    /* Presiona el boton para tomar/soltar rocas de chell */
    void pressGrab();

    /* Suelta el boton para tomar/soltar rocas de chell */
    void releaseGrab();

    /* Presiona la tecla izquierda de chell*/
    void pressLeft();

    /* Suelta la tecla izquierda de chell. */
    void releaseLeft();

    /* Presiona la tecla derecha */
    void pressRight();

    /* Suelta la tecla derecha */
    void releaseRight();

    void pressUp();

    void releaseUp();

    /* Cambia el estado a running */
    void changeStateToRunning();

    /* Cambia el estado a idle */
    void changeStateToIdle();

    /* Cambia el estado a jumping */
    void changeStateToJumping();

    /* Cambia el estado de chell a muerta */
    void changeStateToDead();

    /* Cambia el estado de chell a disparando */
    void changeStateToFire();

    /* Cambia de estado a fire to idle */
    void changeStateToFireToIdle();

    /* Cambia el estado a jiging (baila) */
    void changeStateToJiging();

    /* Cambia el estado a cayend */
    void changeStateToFalling();

    /* Cambia al estado aterrizar */
    void changeStateToLanding();

    /* Cambia al estado voltear */
    void changeStateToTurning();

    /* Cambia el estado a deteniendose */
    void changeStateToStopping();

    /* Aterriza a chell */
    void land();

    /* Aplica un impulso a la izquierda */
    void applyLinearImpulseToLeft();

    /* Aplica un impulso a la derecha */
    void applyLinearImpulseToRight();

    /* Aplica un impulso hacia arriba */
    void applyLinearImpulseToUp();

    /* Para el movimiento hacia la izqueirda */
    void stopLeftMovement();

    /* Para el movimiento hacia la derecha */
    void stopRightMovement();

    /* Devuelve un puntero al keypad de chell */
    Keypad *getKeypad();

    /* Aplica una accion sobre chell dependiendo de su estado */
    virtual void applyStateAction();

    /* Maneja el contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *other_body, b2Contact *contact);

    /* Muere por el contacto con el acido */
    virtual void handleBeginContactWith(
        Acid *acid, b2Contact *contact) override;

    /* Aterriza sobre el bloque si esta saltando */
    virtual void handleBeginContactWith(
        Block *block, b2Contact *contact) override;

    /* Muere tras chocar con una bala. */
    virtual void handleBeginContactWith(
        Bullet *bullet, b2Contact *contact) override;

    /* Presiona y aterriza sobre el boton si esta saltando */
    virtual void handleBeginContactWith(
        Button *button, b2Contact *contact) override;

    /* Agrega chell al conjunto del pastel */
    virtual void handleBeginContactWith(
        Cake *cake, b2Contact *contact) override;

    /* Aterriza sobre otra chell */
    virtual void handleBeginContactWith(
        Chell *chell, b2Contact *contact) override;

    /* Aterriza sobre otra chell */
    virtual void handleBeginContactWith(
        Gate *gate, b2Contact *contact) override;

    /* Aterriza sobre un lanzador */
    virtual void handleBeginContactWith(
        Launcher *launcher, b2Contact *contact) override;

    /* Teletransporta a chell */
    virtual void handleBeginContactWith(
        Portal *portal, b2Contact *contact) override;

    /* Aterriza sobre un receptor */
    virtual void handleBeginContactWith(
        Receiver *receiver, b2Contact *contact) override;

    /* Toma una roca si esta en grabbing mode. */
    virtual void handleBeginContactWith(
        Rock *rock, b2Contact *contact) override;

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *other_body, b2Contact *contact);

    /* Suelta el boton */
    virtual void handleEndContactWith(
        Button *button, b2Contact *contact) override;
};

#endif
