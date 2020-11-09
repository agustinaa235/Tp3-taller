#ifndef SERVER_H
#define SERVER_H

#include <string>
#include "../common_src/common_socket.h"
#include "server_recursos.h"
#include "server_aceptador.h"

class Servidor{
    public:
          Servidor(const std::string& service, const std::string& root_file);
          ~Servidor();
          void run();
          void close();
          Servidor(Servidor&& servidor);
          Servidor& operator=(Servidor&& servidor);
    private:
          Servidor_Recursos recursos;
          const char* service;
          Socket listener;
          Aceptador* aceptador;
          //std::stringstream procesar_petitorio(Socket* peer);
};

#endif
