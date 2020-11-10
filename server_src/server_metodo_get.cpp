#include "server_metodo_get.h"
#include "../common_src/common_excepciones.h"
#include <iostream>

Get_Sin_Recurso::Get_Sin_Recurso(std::string& nombre_archivo){
    this->archivo.open(nombre_archivo);
    if (!this->archivo.is_open()){
      throw ArchivoError("ERROR_ARCHIVO");
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

Get_Con_Recurso::Get_Con_Recurso(const std::string& body){
      this->body = body;
}
Get_Con_Recurso::~Get_Con_Recurso(){}
std::string Get_Con_Recurso::obtener_respuesta(){
    std::string respuesta("");
    if (this->body == ""){
        respuesta = "HTTP/1.1 404 NOT FOUND\n\n";
    } else {
        respuesta = "HTTP/1.1 200 OK\nContent-Type: text/html\n" + this->body;
    }
    return respuesta;
}
