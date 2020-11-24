#include "server_recursos.h"


Servidor_Recursos::Servidor_Recursos(const std::string& nombre_archivo) :
    mapa_de_recursos(),
    nombre_archivo(nombre_archivo){}

Servidor_Recursos::~Servidor_Recursos(){}

void Servidor_Recursos::agregar_recurso(const std::string& recurso,
                                        const std::string& cuerpo){
      std::lock_guard<std::mutex> lock(this->mutex);
      this->mapa_de_recursos.insert(make_pair(recurso, cuerpo));
}

std::string Servidor_Recursos::obtener_nombre_archivo()const{
    return this->nombre_archivo;
}
std::string Servidor_Recursos::obtener_recurso(const std::string& recurso){
    std::lock_guard<std::mutex> lock(this->mutex);
    std::string cuerpo("");
    std::map<std::string, std::string>::iterator it;
    it = this->mapa_de_recursos.find(recurso);
    if (it == this->mapa_de_recursos.end()){
        return cuerpo;
    }
    cuerpo = it->second;
    return cuerpo;
}
