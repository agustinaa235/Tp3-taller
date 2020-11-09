#include "server_parceador.h"
#define POST "POST"
#define GET "GET"
#define SIN_RECURSO "/ HTTP"
#define BODY "<!DOCTYPE html>"
#include <iostream>

Parceador::Parceador(){}

Parceador::~Parceador(){}
bool soy_get(std::string& petitorio){
    int pos = petitorio.find(GET);
    return (pos >-1? true:false);
}
bool soy_post(std::string& petitorio){
    int pos = petitorio.find(POST);
    return (pos > -1? true:false);
}
bool no_tiene_recurso(std::string petitorio){
    int pos = petitorio.find(SIN_RECURSO);
    return (pos > -1 ? true:false);
}
std::string buscar_recurso(std::string petitorio){
    int pos = petitorio.find("/");
    int pos2 = petitorio.find("HTTP");
    std::string recurso = petitorio.substr(pos, pos2);
    return recurso;
}
std::string buscar_body(std::string petitorio){
    int pos = petitorio.find(BODY);
    std::string body("");
    if (pos == -1){
        return body;
    }
    body = petitorio.substr(pos, petitorio.size() -1);
    return body;
}
Metodo* crear_metodo_get(const std::string& petitorio,
                          Servidor_Recursos* recursos){
    if (no_tiene_recurso(petitorio)){
        std::string archivo = recursos->get_root_template();
        return new Get_Sin_Recurso(archivo);
    } else {
          // verifico si mi recurso esta en mi petitorio y en base a eso se lo
          // mando a mi get con recurso;
          std::string recurso = buscar_recurso(petitorio);
          std::string body = recursos->get_recurso(recurso);
          return new Get_Con_Recurso(body);
    }
}
Metodo* crear_metodo_post(const std::string& petitorio,
                            Servidor_Recursos* recursos){
    if (no_tiene_recurso(petitorio)){
        return new Post_Sin_Recurso();
    } else {
        // agrego a mi mapa el resour con su mensaje;
        std::string recurso = buscar_recurso(petitorio);
        std::string body = buscar_body(petitorio);
        recursos->agregar_recurso(recurso, body);
        return new Post_Con_Recurso(body);
    }
}
Metodo* crear_metodo_invalido(std::string& petitorio){
    int pos = petitorio.find("/");
    std::string instruccion_invalida = petitorio.substr(0, pos);
    return new Invalida(instruccion_invalida);
}

Metodo* Parceador::parcear_petitorio(std::stringstream& petitorio,
                                      Servidor_Recursos* recursos){
    std::string petitorio_aux = petitorio.str();
    if (soy_get(petitorio_aux)){
        return crear_metodo_get(petitorio_aux, recursos);
    } else if (soy_post(petitorio_aux)){
        return crear_metodo_post(petitorio_aux, recursos);
    } else {
        return crear_metodo_invalido(petitorio_aux);
    }
}
std::string Parceador::primera_linea(std::stringstream& petitorio){
    std::string petitorio_aux = petitorio.str();
    int pos = petitorio_aux.find("\n");
    std::string primera_linea("");
    if (pos == -1){
        return primera_linea;
    }
    primera_linea = petitorio_aux.substr(0, pos);
    return primera_linea;
}
