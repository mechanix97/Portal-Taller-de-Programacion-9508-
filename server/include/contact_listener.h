#ifndef __CONTACT_LISTENER_H__
#define __CONTACT_LISTENER_H__

#include "../../libs/Box2D-master/Box2D/Dynamics/Contacts/b2Contact.h"

#include "../../libs/Box2D-master/Box2D/Dynamics/b2WorldCallbacks.h"
#include "./bodies/body.h"


class ContactListener: public b2ContactListener {
public:
    virtual void BeginContact(b2Contact *contact) override;
    virtual void EndContact(b2Contact *contact) override;
};


#endif
