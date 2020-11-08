#ifndef SERVER_RECURSOS_H
#define SERVER_RECURSOS_H

#include <map>
#include <string>
#include <mutex>


class Servidor_Recursos{
    public:
        explicit Servidor_Recursos(const std::string& root_template);
        ~Servidor_Recursos();
        void agregar_recurso(const std::string& recurso, const std::string& body);
        std::string get_root_template();
        std::string get_recurso(const std::string& recurso);
    private:
        std::map<std::string, std::string> mapa_de_recursos;
        std::string root_template;
        std::mutex mutex;
};

#endif
