#include "server_parceador.h"
#define POST "POST"
#define GET "GET"
#define SIN_RECURSO "/ HTTP"
#define BODY "<!DOCTYPE html>"
#include <iostream>

Parceador::Parceador(){}

Parceador::~Parceador(){}

/*
  * devuleve true si el petitorio posee get sino devuelve false
*/
static bool soy_get(const std::string& petitorio){
    int pos = petitorio.find(GET);
    return (pos >-1? true:false);
}
/*
  * devuelve true si el petitorio posee un post sino devuelve false
*/
static bool soy_post(const std::string& petitorio){
    int pos = petitorio.find(POST);
    return (pos > -1? true:false);
}
/*
  * devulve true si determina que el petitorio no posee un recurso
  * sino devulve false
*/
static bool no_tiene_recurso(const std::string& petitorio){
    int pos = petitorio.find(SIN_RECURSO);
    return (pos > -1 ? true:false);
}
/*
  * buscara en el petitorio el recurso y lo devolvera
  * se asume que el petitorio viene con un correcto formato
*/
static std::string buscar_recurso(const std::string& petitorio){
    int pos = petitorio.find("/");
    int pos2 = petitorio.find("HTTP");
    std::string recurso = petitorio.substr(pos, pos2);
    return recurso;
}
/*
  * buscara en el petitorio el cuerpo y lo devulvera. si no lo encuentra
  * devulve el string vacio.
*/
static std::string buscar_cuerpo(const std::string& petitorio){
    int pos = petitorio.find(BODY);
    std::string cuerpo("");
    if (pos == -1){
        return cuerpo;
    }
    cuerpo = petitorio.substr(pos, petitorio.size() -1);
    return cuerpo;
}
/*
  * creara el metodo get y de acuerdo a si posee un recurso devuelve
  * uno o el otro
*/
static Metodo* crear_metodo_get(const std::string& petitorio,
                                Servidor_Recursos& recursos){
    if (no_tiene_recurso(petitorio)){
        std::string archivo = recursos.obtener_nombre_archivo();
        return new Get_Sin_Recurso(archivo);
    }
    std::string recurso = buscar_recurso(petitorio);
    std::string cuerpo = recursos.obtener_recurso(recurso);
    return new Get_Con_Recurso(cuerpo);
}
/*
  * creara el metodo post y de acuedo a si posee un recurso devuelve uno o
  * el otro
*/
static Metodo* crear_metodo_post(const std::string& petitorio,
                            Servidor_Recursos& recursos){
    if (no_tiene_recurso(petitorio)){
        return new Post_Sin_Recurso();
    }
    std::string recurso = buscar_recurso(petitorio);
    std::string cuerpo = buscar_cuerpo(petitorio);
    recursos.agregar_recurso(recurso, cuerpo);
    return new Post_Con_Recurso(cuerpo);
}
/*
  * creara el metodo invalida
*/
static Metodo* crear_metodo_invalido(const std::string& petitorio){
    int pos = petitorio.find("/");
    std::string instruccion_invalida = petitorio.substr(0, pos);
    return new Invalida(instruccion_invalida);
}

Metodo* Parceador::parcear_petitorio(std::stringstream& petitorio,
                                      Servidor_Recursos& recursos) const {
    const std::string petitorio_aux = petitorio.str();
    if (soy_get(petitorio_aux)){
        return crear_metodo_get(petitorio_aux, recursos);
    } else if (soy_post(petitorio_aux)){
        return crear_metodo_post(petitorio_aux, recursos);
    } else {
        return crear_metodo_invalido(petitorio_aux);
    }
}

std::string Parceador::operator()(std::stringstream& petitorio) const {
    std::string petitorio_aux = petitorio.str();
    int pos = petitorio_aux.find("\n");
    std::string primera_linea("");
    if (pos == -1){
        return primera_linea;
    }
    primera_linea = petitorio_aux.substr(0, pos);
    return primera_linea;
}
