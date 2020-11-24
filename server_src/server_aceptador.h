#ifndef ACEPTADOR_H
#define ACEPTADOR_H

#include "server_conexion_cliente.h"
#include "../common_src/common_socket.h"
#include "server_recursos.h"
#include <vector>
#include <utility>
class Aceptador : public Thread{
    public:
          /*
            *Creara al aceptador dejandolo valido para uso
          */
          Aceptador(Socket& listener, Servidor_Recursos& recursos);
          /*
            * Liberara al aceptador con sus recursos
          */
          ~Aceptador();
          /*
            * creara las distintas conexciones a clientes y las lanzara
            * corta cuando se hace un shutdown del socket listener
          */
          void run() override;

    private:
        Socket& listener;
        std::vector<Conexion_Cliente*> clientes;
        Servidor_Recursos& recursos;
        void sacar_terminados();
        void sacar_todos();
};

#endif
