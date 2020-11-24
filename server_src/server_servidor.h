#ifndef SERVER_H
#define SERVER_H

#include <string>
#include "../common_src/common_socket.h"
#include "server_recursos.h"
#include "server_aceptador.h"

class Servidor{
    public:
          /*
            * creara al servidor dejandolo valido para uso
          */
          Servidor(const std::string& service,
                   const std::string& nombre_archivo);
          /*
            * liberara al servidor junto a sus recursos
          */
          ~Servidor();
          /*
            * haga un bind and listen y luego lanzara el hilo aceptador
          */
          void run();
          /*
            * cerrara su socket listener y hara un join del hilo aceptador
          */
          void close();
          /*
            * constructor por movimiento
          */
          Servidor(Servidor&& servidor);
          /*
            * operador= por movimiento
          */
          Servidor& operator=(Servidor&& servidor);

    private:
          Servidor_Recursos recursos;
          const char* service;
          Socket listener;
          Aceptador aceptador;
};

#endif
