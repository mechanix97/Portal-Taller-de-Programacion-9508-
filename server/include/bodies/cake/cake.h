#ifndef __CAKE_H__
#define __CAKE_H__

#include "../body.h"
#include <set>

class World;
class Chell;

class Cake: public Body {
private:
    const float WIDTH  = 1.00;
    const float HEIGHT = 1.00;
    std::set<Chell *> chell_set;

public:
    /* Instancia un pastel en (x, y) */
    Cake(World *world, float x, float y);

    /* Indica la cantidad de chells distintas que tocaron al pastel */
    unsigned int chellCount() const;

    /* Agrega a chell al conjunto de chells que tocaron el pastel */
    void insertChellInSet(Chell *chell);

    /* Crea un update con comando command */
    virtual Update createUpdate(COMMAND command) const;

    /* Maneja el inicio de colision con body e informacion de contacto
     * en contact. */
    virtual void handleBeginContactWith(Body *body, b2Contact *contact);

    /* Maneja el fin de colision con body e informacion de contacto
     * en contact.*/
    virtual void handleEndContactWith(Body *body, b2Contact *contact);

    /* Agrega chell al conjunto de chells que tocaron el pastel */
    virtual void handleBeginContactWith(Chell *chell, b2Contact *contact);
};

#endif
