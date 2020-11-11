#ifndef CONEXION_CLIENTE_H
#define CONEXION_CLIENTE_H

#include "server_thread.h"
#include "server_recursos.h"
#include "../common_src/common_socket.h"
#include <atomic>
#include <sstream>
#include <utility>

class Conexion_Cliente: public Thread{
    public:
          /*
            * creara a la conexion de cada cliente con el peer
          */
          Conexion_Cliente(Socket peer, Servidor_Recursos& recursos);
          /*
            * liberara la conexion cliente con sus respectivos recursos
          */
          ~Conexion_Cliente();
          /*
            * se encarga de recibir la informacion del cliente, procesarla
            * y devolvera ya procesada
          */
          void run() override;
          /*
            * se fija si el hilo ya termino
          */
          bool esta_muerto() const;
          /*
            * hace que el hilo frene y no se ejecute mas
          */
          void stop();

    private:
          Socket peer;
          Servidor_Recursos& recursos;
          std::atomic<bool> seguir_hablando;
          std::atomic<bool> esta_corriendo;
          std::stringstream procesar_petitorio();
};

#endif
