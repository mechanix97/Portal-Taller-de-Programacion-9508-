#ifndef __PROTECTED_QUEUE_H__
#define __PROTECTED_QUEUE_H__

#include <queue>
#include <mutex>
#include <condition_variable>

/* ProtectedQueue es una cola bloqueante que en caso de querer desencolar un
 * elemento, bloquea al hilo hasta tener algo que devolver */
template <typename T>
class ProtectedQueue {
private:
    std::queue<T> queue;
    std::mutex m;
    std::condition_variable cond_var;

public:
    /* Indica si la cola esta vacia */
    bool isEmpty();

    /* Agrega un elemento. */
    void push(T elem);

    /* Espera hasta que haya un elemento para desencolar y lo desencola. */
    T wait_and_pop();

    /* Desencola un elemento en elem y devuelve false en caso de estar vacia */
    bool try_pop(T &elem);
};

template <typename T>
bool ProtectedQueue<T>::isEmpty() {
    std::lock_guard<std::mutex> lk(this->m);
    return this->queue.empty();
}

template <typename T>
void ProtectedQueue<T>::push(T elem) {
    std::lock_guard<std::mutex> lk(this->m);
    this->queue.push(elem);
    this->cond_var.notify_one();
}

template <typename T>
T ProtectedQueue<T>::wait_and_pop() {
    std::unique_lock<std::mutex> ul(this->m);
    this->cond_var.wait(ul, [&]{return !queue.empty();});
    T elem = this->queue.front();
    this->queue.pop();
    return elem;
}

template <typename T>
bool ProtectedQueue<T>::try_pop(T &elem) {
    std::lock_guard<std::mutex> lg(this->m);
    if (this->queue.empty()) {
        return false;
    }
    elem = this->queue.front();
    this->queue.pop();
    return true;
}

#endif
