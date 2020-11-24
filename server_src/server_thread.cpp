#include "server_thread.h"


Thread::Thread(){}

void Thread::start() {
    this->thread = std::thread(&Thread::run, this);
}
void Thread::join() {
    this->thread.join();
}

Thread::Thread(Thread&& thread) {
    this->thread = std::move(thread.thread);
}

Thread& Thread::operator=(Thread&& other) {
    if (this == &other){
        return *this;
    }
    this->thread = std::move(other.thread);
    return *this;
}
