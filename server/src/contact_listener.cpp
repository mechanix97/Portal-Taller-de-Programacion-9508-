#include "../include/contact_listener.h"
#include "../include/bodies/body.h"
#include <iostream>


void ContactListener::BeginContact(b2Contact *contact) {
    void *ptr = contact->GetFixtureA()->GetBody()->GetUserData();
    void *other_ptr = contact->GetFixtureB()->GetBody()->GetUserData();


    Body *body = static_cast<Body *>(ptr);
    Body *other_body = static_cast<Body *>(other_ptr);

    if (body != 0 and other_body != 0) {
        other_body->handleBeginContactWith(body, contact);
    }
}

void ContactListener::EndContact(b2Contact *contact) {
    void *ptr = contact->GetFixtureA()->GetBody()->GetUserData();
    void *other_ptr = contact->GetFixtureB()->GetBody()->GetUserData();

    Body *body = static_cast<Body *>(ptr);
    Body *other_body = static_cast<Body *>(other_ptr);

    if (body != 0 and other_body != 0) {
        other_body->handleEndContactWith(body, contact);
    }
}
