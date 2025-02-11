#include "server_metodo_get.h"
#include "../common_src/common_excepciones.h"
#include <iostream>

Get_Sin_Recurso::Get_Sin_Recurso(const std::string& nombre_archivo){
    this->archivo.open(nombre_archivo);
    if (!this->archivo.is_open()){
      throw Exception("error apertura de archivo");
    }
}
Get_Sin_Recurso::~Get_Sin_Recurso(){
    if (this->archivo.is_open()){
        this->archivo.close();
    }
}
std::string Get_Sin_Recurso::obtener_respuesta(){
    std::string respuesta = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
    std::string data;
    while (getline(this->archivo, data)){
        respuesta += data;
    }
    return respuesta;
}

Get_Con_Recurso::Get_Con_Recurso(const std::string& cuerpo){
      this->cuerpo = cuerpo;
}
Get_Con_Recurso::~Get_Con_Recurso(){}
std::string Get_Con_Recurso::obtener_respuesta(){
    std::string respuesta("");
    if (this->cuerpo == ""){
        respuesta = "HTTP/1.1 404 NOT FOUND\n\n";
    } else {
        respuesta = "HTTP/1.1 200 OK\nContent-Type: text/html\n" + this->cuerpo;
    }
    return respuesta;
}
