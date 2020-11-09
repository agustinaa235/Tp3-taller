#ifndef ACEPTADOR_H
#define ACEPTADOR_H

#include "server_conexion_cliente.h"
#include "../common_src/common_socket.h"
#include "server_recursos.h"
#include <vector>
#include <utility>
class Aceptador : public Thread{
    public:
        Aceptador();
        Aceptador(Socket* listener, Servidor_Recursos* recursos);
        ~Aceptador();
        void run() override;
    private:
        Socket* listener;
        std::vector<Conexion_Cliente*> clientes;
        Servidor_Recursos* recursos;
        void sacar_terminados();
        void sacar_todos();
};

#endif
