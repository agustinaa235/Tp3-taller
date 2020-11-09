#include "server_servidor.h"
#include <iostream>
//#include "server_metodo.h"
//#include "parceador.h"

Servidor::Servidor(const std::string& service, const std::string& root_file) :
    recursos(root_file),
    service(service.c_str()),
    listener(),
    aceptador(){}

Servidor::~Servidor(){
    delete this->aceptador;
}
/*
Servidor::Servidor(Servidor&& servidor){
    this->recursos = std::move(servidor.recursos);
    this->service =  std::move(servidor.service);
    this->listener = std::move(servidor.listener);
    this->aceptador = std::move(servidor.aceptador);
}

Servidor& Servidor::operator=(Servidor&& servidor) {
    this->recursos = std::move(servidor.recursos);
    this->service = std::move(servidor.service);
    this->listener = std::move(servidor.listener);
    this->aceptador = std::move(servidor.aceptador);
    return *this;
}
*/
void Servidor::close(){
    this->listener.Shutdown(SHUT_RDWR);
    this->listener.cerrar();
    this->aceptador->join();
}
void Servidor::run(){
    this->listener.bine_and_listen(nullptr, this->service);
    this->aceptador = new Aceptador(&this->listener,&this->recursos);
    this->aceptador->start();
}
