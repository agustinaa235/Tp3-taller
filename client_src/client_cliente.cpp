#include "client_cliente.h"

#include <iostream>
#include <sstream>


Cliente::Cliente(const std::string& host, const std::string& service) :
    service(service.c_str()),
    host(host.c_str()),
    socket(){}

Cliente::~Cliente(){}

void Cliente::procesar_respuesta_servidor(){
    char buffer[110] = "";
    bool termine = false;
    bool hubo_un_error = false;
    std::stringstream respuesta;
    while (!termine && !hubo_un_error){
        int bytes_recibidos = this->socket.recibir(buffer, 110);
        if (bytes_recibidos == -1){
            hubo_un_error = true;
        } else if (bytes_recibidos == 0){
            termine = true;
        } else {
            respuesta.write(buffer, bytes_recibidos);
        }
    }
    std::string respuesta_aux = respuesta.str();
    std::cout << respuesta_aux;
}

void Cliente::run(){
    this->socket.conectar(this->host, this->service);
    std::string pepitorio;
    while (getline(std::cin, pepitorio, '\n')){
        if (pepitorio.size() != 0){
              pepitorio.push_back('\n');
              this->socket.enviar(pepitorio.c_str(), pepitorio.size());
        }
    }
    this->socket.Shutdown(SHUT_WR);
    this->procesar_respuesta_servidor();
}
