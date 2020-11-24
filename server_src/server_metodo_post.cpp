#include "server_metodo_post.h"

Post_Sin_Recurso::Post_Sin_Recurso(){}

Post_Sin_Recurso::~Post_Sin_Recurso(){}

std::string Post_Sin_Recurso::obtener_respuesta(){
    std::string respuesta = "HTTP/1.1 403 FORBIDDEN\n\n";
    return respuesta;
}

Post_Con_Recurso::Post_Con_Recurso(const std::string& cuerpo){
    this->cuerpo = cuerpo;
}
Post_Con_Recurso::~Post_Con_Recurso(){}

std::string Post_Con_Recurso::obtener_respuesta(){
    std::string respuesta = "HTTP/1.1 200 OK\n\n" + this->cuerpo;
    return respuesta;
}
