#include "thread.h"


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
    this->thread = std::move(other.thread);
    return *this;
}
