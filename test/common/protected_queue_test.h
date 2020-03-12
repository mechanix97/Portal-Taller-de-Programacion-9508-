#ifndef __PROTECTED_QUEUE_TEST_H__
#define __PROTECTED_QUEUE_TEST_H__

#include "../../common/include/protected_queue.h"
#include <thread>
#include <chrono>
#include <cxxtest/TestSuite.h>

class ProtectedQueueTest: public CxxTest::TestSuite {
public:
    void testNuevaColaDebeEstarVacia() {
        ProtectedQueue<int> pq;
        TS_ASSERT(pq.isEmpty());
    }

    void testSeAgregaUnElementoYLaColaNoEstaVacia() {
        ProtectedQueue<int> pq;
        pq.push(1);
        TS_ASSERT(!pq.isEmpty());
    }

    void testSeAgregaUnElementoLuegoSeEsperaYQuitaYLaColaDebeQuedarVacia() {
        ProtectedQueue<int> pq;
        pq.push(1);
        pq.wait_and_pop();
        TS_ASSERT(pq.isEmpty());
    }

    void testUnHiloEsperaHastaQueHayaUnElementoQueDesencolar() {
        /* test con hilos.
         * No estoy seguro de que sea bueno hacer esto.
         * Basicamente quiero medir si el thread se duerme por al menos
         * 100milisec hasta que otro_hilo agregue un elemento a la cola */
        ProtectedQueue<int> pq;
        int waiting_time = 100;
        auto t1 = std::chrono::high_resolution_clock::now();
        std::thread otro_hilo([&]{
            std::this_thread::sleep_for(std::chrono::milliseconds(waiting_time));
            pq.push(7);});

        pq.wait_and_pop();
        auto t2 = std::chrono::high_resolution_clock::now();

        otro_hilo.join();
        std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
        TS_ASSERT(fp_ms.count() >= waiting_time);
    }
};

#endif
