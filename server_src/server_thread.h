#ifndef THREAD_H
#define THREAH_H

#include <thread>
#include <utility>

class Thread{
    public:
          /*
            * creara al thread dejandolo valido
          */
          Thread();
          virtual void run() = 0;
          virtual ~Thread() {}
          /*
            * lanzara al hilo
          */
          void start();
          /*
            * hara un join del hilo
          */
          void join();
          /*
            * no se permite el constructor por copia
          */
          Thread(const Thread&) = delete;
          /*
            * no se permite el operador = por copia
          */
          Thread& operator=(const Thread&) = delete;
          /*
            * constructor por movimiento del thread
          */
          Thread(Thread&& thread);
          /*
            * operador = por movimiento del thread
          */  
          Thread& operator=(Thread&& other);

    private:
        std::thread thread;
};

#endif
