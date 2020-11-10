#ifndef CLIENT_H
#define CLIENT_H

#include "../common_src/common_socket.h"
#include <string>
#include <sstream>

class Cliente{
    public:
        /*
          * creara al cliente dejandolo valido para uso
        */
        Cliente(const std::string& host, const std::string& service);
        /*
          * liberara al cliente con sus recurso
        */
        ~Cliente();
        /*
          * enviara un mensaje a un servidor y luego recibira uno de este
        */
        void run();
        
    private:
          const char* service;
          const char* host;
          Socket socket;
          /*
            * pocesara la respueta que le llegue del servidor
          */
          void procesar_respuesta_servidor();
};

#endif
