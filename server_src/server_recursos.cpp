#include "server_recursos.h"

#include "server_lock.h"

Servidor_Recursos::Servidor_Recursos(const std::string& root_template) :
    mapa_de_recursos(),
    root_template(root_template),
    mutex(){}

Servidor_Recursos::~Servidor_Recursos(){}

void Servidor_Recursos::agregar_recurso(const std::string& recurso,
                                        const std::string& body){
      Lock lock(this->mutex);
      this->mapa_de_recursos.insert(make_pair(recurso, body));
}

std::string Servidor_Recursos::get_root_template(){
    return this->root_template;
}
std::string Servidor_Recursos::get_recurso(const std::string& recurso){
    Lock lock(this->mutex);
    std::string body("");
    std::map<std::string, std::string>::iterator it;
    it = this->mapa_de_recursos.find(recurso);
    if (it == this->mapa_de_recursos.end()){
        return body;
    }
    body = it->second;
    return body;
}
