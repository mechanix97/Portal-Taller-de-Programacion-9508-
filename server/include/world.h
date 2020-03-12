#ifndef __WORLD_H__
#define __WORLD_H__

#include "world_config.h"
#include "pin.h"
#include "boolean_suppliers/boolean_block_factory.h"
#include "contact_listener.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"
#include "../include/instructions/instruction_factory.h"
#include "../include/game_loop.h"
#include <cstdint>
#include <vector>
#include <list>
#include <map>
#include <mutex>
#include <set>
#include <deque>


class Instruction;
class Chell;
class Receiver;
class Launcher;
class Rock;
class Gate;
class Button;
class Acid;
class Portal;
class Cake;
class Rock;
class Laser;
class Rock;
class Material;
class Shape;
class MetalMaterial;
class StoneMaterial;
class SquareShape;
class DiagonalShape;
class GameLoop;

#define GRAVITY b2Vec2(0.0, -9.8)

/* Representa al mundo de juego.
 * Utiliza dos sistemas de control de memoria.
 * 1. Automatico: Se llama al destruirse world. Destruye a todos los elementos
 *                que queden en world.
 * 2. Manual: Permite destruir de manera controlada a objetos en world.
 *
 * Aquellos objetos aglomerados en los que tras eliminar uno se eliminen los
 * otros deben ser eliminados manualmente, en caso contrario el orden de
 * eliminacion no es asegurado pudiendo generar memory leaks.
 * Se recomienda destruir manualmente los bodies y solo dejar a eliminacion
 * automatica a aquellos que no sean aglomerados.
 * ejemplo: body no aglomerado(simples) = bullet, block, launcher.
 *          aglomerado: Chell, puede contener portales.*/

class World {
private:
    b2World *b2world;
    uint32_t body_count;
    bool b2world_is_internal;
    std::set<Body *> bodies;
    std::map<uint32_t, Chell *> chells;
    std::map<uint32_t, Pin *> pins;
    std::map<uint32_t, uint32_t> changedPins;
    BooleanBlockFactory boolean_block_factory;
    ContactListener contact_listener;
    std::set<Body *> bodies_for_deletion;
    std::deque<Instruction *> instructions;
    std::deque<Update>  internal_updates;
    InstructionFactory instruction_factory;
    Cake *cake;
    GameLoop game_loop;
    WorldConfig config;

public:
    /* Instancia un world */
    World();

    /* Instancia un world core sobre b2world. */
    World(b2World *b2world);

    /* No se permite construccion por movimiento */
    World(World &&world) = delete;

    /* No se permite la construccion por copia */
    World(const World &world) = delete;

    /* No se permite asignacion por movimiento */
    World &operator=(World &&other) = delete;

    /* No se permite la asignacion por copia */
    World &operator=(const World &other) = delete;

    /* Libera los recursos utilizados. */
    ~World();

    /* Devuelve la cantidad de chells vivas */
    unsigned int countLiveChells() const;

    /* Devuelve las configuracion de world*/
    WorldConfig getWorldConfig() const;

    /* Asigna parametros de configuracion */
    void setWorldConfig(const WorldConfig &config);

    /* Indica si chell de chell_id esta viva */
    bool isChellAlive(uint32_t chell_id) const;

    /* Devuelve un puntero al controlador de game loop */
    GameLoop *getGameLoop();

    /* Indica si el mundo cargado es valido */
    bool isValid();

    /* Devuelve un conjunto de bodies */
    std::set<Body *> *getBodies();

    /* Indica si se gano la partida */
    bool isFinished() const;

    /* Devuelve un mapa con clave chell_id y valor puntero a chell. */
    std::map<uint32_t, Chell *> *getChells();

    /* Elimina a chell del conjunto de chells */
    void removeFromChells(Chell *chell);

    /* Indica si todos los jugadores comieron del pastel */
    bool everybodyAteTheCake() const;

    /* Indica si todos los jugadores menos uno comieron del pastel */
    bool everybodyButOneAteTheCake() const;

    /* Incrementa el contador de bodies */
    void incBodyCount();

    /* Agrega un nuevo body al set bodies */
    void addToBodies(Body *body);

    /* Agrega una update a la coleccion de updates*/
    void addUpdate(const Update &update);

    /* Elimina a body de world */
    void destroyBody(Body *body);

    /* Agrega una instruccion a la cola de instrucciones */
    void addInstruction(Instruction *instruction);

    /* Agrega un nuevo body a world */
    void insertNewBody(Body *body);

    /* Devuelve la cantidad de cuerpos que han existido.*/
    uint32_t getBodyCount() const;

    /* Devuelve la cantidad de cuerpos que existen en este momento.
     * No cuenta los cuerpos que murieron. */
    uint32_t getBodySize() const;

    /* Devuelve b2world */
    b2World *getB2World();

    /* Crea y devuelve un puntero a una Chell creada en la posicion (x, y) */
    Chell *createChell(float x, float y);

    /* Crea un bloque cuadrado de metal en (x, y) */
    Block *createSquareMetalBlock(float x, float y);

    /* Crea un bloque cuadrado de piedra en (x, y) */
    Block *createSquareStoneBlock(float x, float y);

    /* Crea un bloque diagonal metalico en (x, y) del tipo 'orientation' */
    Block *createDiagonalMetalBlock(float x, float y, ORIENTATION orientation);

    /* Crea un boton. */
    Button *createButton(float x, float y);

    /* Crea una compuerta sin estar asociada a ningun boton ni receptores
     *en (x, y) */
    Gate *createGate(float x, float y);

    /* Crea una compuerta sin estar asociada a ningun boton ni receptores
     *en (x, y) */
    Gate *createRegularGate(float x, float y);

    /* Crea una compuerta del tipo AND en (x, y) */
    Gate *createAndGate(float x, float y);

    /* Crea una compuerta del tipo OR en (x, y) */
    Gate *createOrGate(float x, float y);

    /* Crea una mancha de acido en (x, y) */
    Acid *createAcid(float x, float y);

    /* Crea un lanzador en (x, y) apuntando en la direccion ada.*/
    Launcher *createLauncher(float x, float y, DIRECTION direction);

    /* Crea una bala en (x, y) desplazandose en direction 'direction' */
    Bullet *createBullet(float x, float y, DIRECTION direction);

    /* Crea un receptor en (x, y) */
    Receiver *createReceiver(float x, float y);

    /* Crea un portal de numbe 'portal_number' en pos con normal 'normal'. */
    Portal *createPortal(uint8_t portal_number, b2Vec2 pos, b2Vec2 normal);

    /* Crea una pastel en la posicion(x, y).
     * Pre: Solo se puede crear un unico pastel, en caso contrario
     * devuelve nullptr.  */
    Cake *createCake(float x, float y);

    /* Crea una roca en la posicion (x, y) */
    Rock *createRock(float x, float y);

    /* Crea un laser (barrera de energia) en (x, y) con un cierto angulo.
     * Pre: Los unicos angulos permitidos son ANGLE_000 y ANGLE_090 */
    Laser *createLaser(float x, float y, ANGLE angle);

    /* Devuelve una lista con los elementos del mundo para los nuevos
     * jugadores. */
    std::list<Update> getNewPlayerUpdates() const;

    std::list<Update> getPinUpdateList();

    void createNewPin(uint32_t id, int32_t x, int32_t y);

    /* Devuelve su boolean block factory */
    BooleanBlockFactory *getBooleanBlockFactory();

    std::list<uint32_t> getChellsIdList() const;

    /* Asigna una imagen de background */
    void setBackGround(const std::string &path);

private:
    /* Libera los recursos utiliados por chell */
    void destroyChells();

    /* Libera los bodies creados */
    void destroyAllBodies();

    /* Libera a b2world si fue creado internamente */
    void deleteB2WorldIfInternal();

};

#endif
