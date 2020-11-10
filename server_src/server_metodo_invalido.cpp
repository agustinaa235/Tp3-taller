#include "server_metodo_invalido.h"


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
