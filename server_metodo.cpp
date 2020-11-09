#include "server_metodo.h"
#include <iostream>

Get_Sin_Recurso::Get_Sin_Recurso(std::string& nombre_archivo){
    this->archivo.open(nombre_archivo);
    if (!this->archivo.is_open()){
      std::cout << "ERROR_ARCHIVO \n";
    }
}
Get_Sin_Recurso::~Get_Sin_Recurso(){
    if (this->archivo.is_open()){
        this->archivo.close();
    }
}
std::string Get_Sin_Recurso::obtener_respuesta(){
  //std::cout << "estoy adentor de obtener respuesta";
    std::string respuesta = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
    std::string data;
    while (getline(this->archivo, data)){
        respuesta += data;
    }
    return respuesta;
}

Invalida::Invalida(const std::string& instruccion_invalida){
    this->instruccion_invalida = instruccion_invalida;
}
Invalida::~Invalida(){}

std::string Invalida::obtener_respuesta(){
    std::string respuesta = "HTTP/1.1 405 METHOD NOT ALLOWED\n\n" +
                            this->instruccion_invalida +
                            "es un comando desconocido";
    return respuesta;
}

Post_Sin_Recurso::Post_Sin_Recurso(){}

Post_Sin_Recurso::~Post_Sin_Recurso(){}

std::string Post_Sin_Recurso::obtener_respuesta(){
    std::string respuesta = "HTTP/1.1 403 FORBIDDEN\n\n";
    return respuesta;
}

Post_Con_Recurso::Post_Con_Recurso(const std::string& body){
    this->body = body;
}
Post_Con_Recurso::~Post_Con_Recurso(){}

std::string Post_Con_Recurso::obtener_respuesta(){
    std::string respuesta = "HTTP/1.1 200 OK\n\n" + this->body;
    return respuesta;
}

Get_Con_Recurso::Get_Con_Recurso(const std::string& body){
      this->body = body;
}
Get_Con_Recurso::~Get_Con_Recurso(){}
std::string Get_Con_Recurso::obtener_respuesta(){
    std::string respuesta = "HTTP/1.1 200 OK\nContent-Type: text/html\n" +
                              this->body;
    return respuesta;
}
