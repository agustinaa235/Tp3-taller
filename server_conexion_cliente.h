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
          Conexion_Cliente(Socket peer, Servidor_Recursos* recursos);
          ~Conexion_Cliente();
          void run() override;
          bool esta_muerto();
          void stop();
    private:
          Socket peer;
          Servidor_Recursos* recursos;
          std::atomic<bool> seguir_hablando;
          std::atomic<bool> esta_corriendo;
          std::stringstream procesar_petitorio();
};

#endif
