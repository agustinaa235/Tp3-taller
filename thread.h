#ifndef THREAD_H
#define THREAH_H

#include <thread>

class Thread{
public:
      Thread();
      virtual void run() = 0;
      virtual ~Thread() {}
      void start();
      void join();
      Thread(const Thread&) = delete;
      Thread& operator=(const Thread&) = delete;
      Thread(Thread&& thread);
      Thread& operator=(Thread&& other);

private:
      std::thread thread;
};

#endif
