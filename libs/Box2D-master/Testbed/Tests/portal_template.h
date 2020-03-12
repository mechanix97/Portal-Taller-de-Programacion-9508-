#ifndef __PORTAL_LEAK_H__
#define __PORTAL_LEAK_H__

// Template de test 
class Portal: public Test {
public:
    Portal() {
    }

    void Step(Settings *settings) {
        Test::Step(settings);
    }

    static Test *Create() {
        return new Portal();
    }

    void Keyboard(int key) {
        switch (key) {
        case GLFW_KEY_A:
            break;
        case GLFW_KEY_D:
            break;
        case GLFW_KEY_W:
            break;
        }
    }

    void KeyboardUp(int key) {
        switch (key) {
        case GLFW_KEY_A:
            break;
        case GLFW_KEY_D:
            break;
        case GLFW_KEY_W:
            break;
        }
    }
};

#endif
