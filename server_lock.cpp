#include "server_lock.h"

Lock::Lock(std::mutex& mutex) : mutex(mutex) {
		mutex.lock();
}

Lock::~Lock() {
		mutex.unlock();
}
