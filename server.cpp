#include "server.h"
#include <iostream>
//#include "server_metodo.h"
//#include "parceador.h"

Servidor::Servidor(const std::string& service, const std::string& root_file) :
    recursos(root_file),
    service(service.c_str()),
    listener(){}

Servidor::~Servidor(){
    delete this->aceptador;
}
/*
void Servidor::sacar_terminados(){
    int cantidad_clientes = this->clientes.size();
    for (int i = 0; i < cantidad_clientes; i++){
        if (this->clientes[i]->esta_muerto()){
            this->clientes[i]->join();
            delete this->clientes[i];
        }
    }
}

void Servidor::sacar_todos(){
    int cantidad_clientes = this->clientes.size();
    for (int i = 0; i < cantidad_clientes; i++){
          this->clientes[i]->stop();
          this->clientes[i]->join();
          delete this->clientes[i];
    }
}*/
/*
std::stringstream Servidor::procesar_petitorio(Socket* peer){
    char buffer[100];
    std::stringstream petitorio;
    bool termine = false;
    bool hubo_un_error = false;
    while (!termine && !hubo_un_error){
        int cant_recibidos = peer->recibir(buffer, 100);
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
}*/
void Servidor::close(){

    this->listener.Shutdown(SHUT_RDWR);
    this->listener.cerrar();
    this->aceptador->join();
  //  delete this->aceptador;
}
void Servidor::run(){
    this->listener.bine_and_listen(nullptr, this->service);

    this->aceptador = new Aceptador(&this->listener, &recursos);
    this->aceptador->start();
    /*Aceptador aceptar = new Aceptador(&this->listener, &recursos);
    this->aceptador = std::move(aceptar);
    this->aceptador.start();

    while (true){
        Socket peer = this->listener.aceptar();
        this->clientes.push_back(new Conexion_Cliente(std::move(peer),
                                  &recursos));
        this->clientes.back()->start();
        sacar_terminados();
    }
    this->sacar_todos();

    this->aceptador = new Aceptador(this->listener);
    this->aceptador.run();
    */
    /*
    Socket peer = this->listener.aceptar();
    std::stringstream petitorio = this->procesar_petitorio(&peer);
    Parceador parceador;
    Metodo* metodo =  parceador.parcear_petitorio(petitorio,
                                                        &this->recursos);
    std::string mensaje = metodo->obtener_respuesta();
  //  std::cout << mensaje << "\n";
    delete metodo;
    peer.enviar(mensaje.c_str(), mensaje.size());
    peer.Shutdown(SHUT_RDWR);*/
}
