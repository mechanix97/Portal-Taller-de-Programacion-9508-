#ifndef __LOCK_H__
#define __LOCK_H__

#include <mutex>

class Lock {
    private:
        std::mutex &m;

    public:
        explicit Lock(std::mutex &m) : m(m) {
            m.lock();
        }

        ~Lock() {
            m.unlock();
        }

    private:
        Lock(const Lock&) = delete;
        Lock& operator=(const Lock&) = delete;
        Lock(Lock&&) = delete;
        Lock& operator=(Lock&&) = delete;
};

#endif
