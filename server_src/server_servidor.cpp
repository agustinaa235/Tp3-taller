#include "server_servidor.h"
#include <iostream>


Servidor::Servidor(const std::string& service,
                    const std::string& nombre_archivo) :
    recursos(nombre_archivo),
    service(service.c_str()),
    listener(),
    aceptador(listener, recursos){}

Servidor::~Servidor(){}

void Servidor::close(){
    this->listener.Shutdown(SHUT_RDWR);
    this->listener.cerrar();
    this->aceptador.join();
}
void Servidor::run(){
    this->listener.bine_and_listen(nullptr, this->service);
    this->aceptador.start();
}
