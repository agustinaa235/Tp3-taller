#ifndef CLIENT_H
#define CLIENT_H

#include "../common_src/common_socket.h"
#include <string>
#include <sstream>

class Cliente{
    public:
        Cliente(const std::string& host, const std::string& service);
        ~Cliente();
        void run();
    private:
          const char* service;
          const char* host;
          Socket socket;
          void procesar_respuesta_servidor();
};

#endif
