#include "conexion_cliente.h"
#include <iostream>
#include <string>
#include "parceador.h"
#define TAMANIO_MENSAJE 100

Conexion_Cliente::Conexion_Cliente(Socket peer, Servidor_Recursos* recursos) :
      peer(std::move(peer)),
      recursos(recursos),
      seguir_hablando(true),
      esta_corriendo(true){}

Conexion_Cliente::~Conexion_Cliente(){}
bool Conexion_Cliente::esta_muerto(){
    return (!this->esta_corriendo);
}
std::stringstream Conexion_Cliente::procesar_petitorio(){
    char buffer[TAMANIO_MENSAJE];
    std::stringstream petitorio;
    bool termine = false;
    bool hubo_un_error = false;
    while (!termine && !hubo_un_error){
        int cant_recibidos = this->peer.recibir(buffer, TAMANIO_MENSAJE);
        if (cant_recibidos == -1){
            hubo_un_error = true;
        } else if (cant_recibidos == 0){
            termine = true;
        } else {
            buffer[cant_recibidos] = '\n';
            petitorio.write(buffer, cant_recibidos);
        }
    }
    return petitorio;
}

void Conexion_Cliente::stop(){
    this->seguir_hablando = false;
    this->peer.Shutdown(SHUT_RDWR);
    this->peer.cerrar();
}

void Conexion_Cliente::run(){
      while (this->seguir_hablando){
          std::stringstream petitorio = this->procesar_petitorio();
          Parceador parceador;
          Metodo* metodo = parceador.parcear_petitorio(petitorio,
                                                        this->recursos);
          std::string mensaje = metodo->obtener_respuesta();
          std::cout << mensaje << "\n";
          delete metodo;
          this->peer.enviar(mensaje.c_str(), mensaje.size());
          this->seguir_hablando = false;
      }
      this->esta_corriendo = false;
}
