#include "server_conexion_cliente.h"
#include <iostream>
#include <string>
#include "server_parceador.h"
#define TAMANIO_MENSAJE 100

Conexion_Cliente::Conexion_Cliente(Socket peer, Servidor_Recursos& recursos) :
      peer(std::move(peer)),
      recursos(recursos),
      seguir_hablando(true),
      esta_corriendo(true){}

Conexion_Cliente::~Conexion_Cliente(){
    this->peer.Shutdown(SHUT_RDWR);
    this->peer.cerrar();
}
bool Conexion_Cliente::esta_muerto() const{
    return (this->esta_corriendo == false);
}
std::stringstream Conexion_Cliente::procesar_petitorio(){
    char buffer[TAMANIO_MENSAJE];
    std::stringstream petitorio;
    int cant_recibidos;
    do {
        cant_recibidos = this->peer.recibir(buffer, TAMANIO_MENSAJE);
        buffer[cant_recibidos] = '\n';
        petitorio.write(buffer, cant_recibidos);
    } while (cant_recibidos >0);
    this->peer.Shutdown(SHUT_RD);
    return petitorio;
}

void Conexion_Cliente::stop(){
    this->seguir_hablando = false;
    this->peer.Shutdown(SHUT_WR);
    this->peer.cerrar();
}

void Conexion_Cliente::run(){
      while (this->seguir_hablando){
          try{
              std::stringstream petitorio = this->procesar_petitorio();
              Parceador parceador;
              std::string primera_linea = parceador(petitorio);
              primera_linea += "\n";
              std::cout << primera_linea;
              Metodo* metodo = parceador.parcear_petitorio(petitorio,
                                                       this->recursos);
              std::string mensaje = metodo->obtener_respuesta();
              delete metodo;
              this->peer.enviar(mensaje.c_str(), mensaje.size());
              this->seguir_hablando = false;
              this->peer.Shutdown(SHUT_WR);
              this->peer.cerrar();
          }catch(std::exception &exception){
              this->seguir_hablando = false;
              std::cerr << exception.what();
          }catch(...){
              this->seguir_hablando = false;
              std::cerr << " error desconocido en el hilo conexion clientes";
          }
      }
      this->esta_corriendo = false;
}
