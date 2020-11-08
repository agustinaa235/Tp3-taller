#ifndef CLIENT_H
#define CLIENT_H

#include "common_socket.h"
#include <string>
#include <sstream>
#include "thread.h"
#include <mutex>

class Cliente{
    public:
        Cliente(const std::string& host, const std::string& service);
        ~Cliente();
        void run();
    private:
          Socket socket;
          const char* host;
          const char* service;
          void procesar_respuesta_servidor();
};

#endif
