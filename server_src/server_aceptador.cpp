#include "server_aceptador.h"

#include <iostream>

Aceptador::Aceptador(Socket* listener, Servidor_Recursos* recursos):
      listener(std::move(listener)),
      clientes(),
      recursos(recursos){}
/*
void Aceptador::settear(Socket* listener, Servidor_Recursos* recursos){
    this->listener = listener;
    this->recursos = recursos ;
}*/

Aceptador::~Aceptador(){}

void Aceptador::sacar_terminados(){
    int cantidad_clientes = this->clientes.size();
  //  std::cout << "cantidad_clientes_totales: " << cantidad_clientes;
    for (int i = 0; i < cantidad_clientes; i++){
        if (this->clientes[i]->esta_muerto()){
            //std::cout << "esta_muerto:\n" << i;
            this->clientes[i]->join();
            delete this->clientes[i];
            this->clientes.erase(this->clientes.begin() + i);
            i--;
        }
    }
//  std::cout << "cantidad_clit despues del for 1: " << cantidad_clientes;
}

void Aceptador::sacar_todos(){
    int cantidad_clientes = this->clientes.size();
  //  std::cout << "cantidad_clientes_para_limpiar: " << cantidad_clientes;
    for (int i = 0; i < cantidad_clientes; i++){
          this->clientes[i]->stop();
          this->clientes[i]->join();
          delete this->clientes[i];
    }
}

void Aceptador::run(){
    bool no_termine = false;
    while (!no_termine){
        try{
        Socket peer = this->listener->aceptar();
        this->clientes.push_back(new Conexion_Cliente(std::move(peer),
                                  this->recursos));
        this->clientes.back()->start();
        sacar_terminados();
      }catch(const SocketError &exception){
          this->sacar_todos();
          no_termine = true;
      }
    }
}
