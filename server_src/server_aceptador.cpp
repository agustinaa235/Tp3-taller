#include "server_aceptador.h"
#include "../common_src/common_excepciones.h"
#include <iostream>

Aceptador::Aceptador(Socket& listener, Servidor_Recursos& recursos):
      listener(listener),
      clientes(),
      recursos(recursos){}

Aceptador::~Aceptador(){}

void Aceptador::sacar_terminados(){
    int cantidad_clientes = this->clientes.size();
    for (int i = 0; i < cantidad_clientes; i++){
        if (this->clientes[i]->esta_muerto()){
            this->clientes[i]->join();
            delete this->clientes[i];
            this->clientes.erase(this->clientes.begin() + i);
            i--;
        }
    }
}

void Aceptador::sacar_todos(){
    int cantidad_clientes = this->clientes.size();
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
            Socket peer = this->listener.aceptar();
            this->clientes.push_back(new Conexion_Cliente(std::move(peer),
                                      this->recursos));
            this->clientes.back()->start();
            sacar_terminados();
      }catch(const SocketError &exception){
          no_termine = true;
      } catch (const std::exception &exception){
            std::cerr << exception.what();
      } catch (...){
            std::cerr << "error desconocido en el hilo aceptador";
      }
    }
    this->sacar_todos();
}
