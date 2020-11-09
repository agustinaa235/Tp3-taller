#ifndef SERVER_RECURSOS_H
#define SERVER_RECURSOS_H

#include <map>
#include <string>
#include <mutex>
#include <utility>

class Servidor_Recursos{
    public:
        explicit Servidor_Recursos(const std::string& root_template);
        ~Servidor_Recursos();
        void agregar_recurso(const std::string& recurso,
                              const std::string& body);
        std::string get_root_template();
        std::string get_recurso(const std::string& recurso);
        //Servidor_Recursos& operator=(const Servidor_Recursos&
                                      //servidor_recursos) = delete;
      //  Servidor_Recursos(Servidor_Recursos&& servidor_recursos);
      //  Servidor_Recursos& operator=(Servidor_Recursos&& servidor_recursos);
    private:
        std::map<std::string, std::string> mapa_de_recursos;
        std::string root_template;
        std::mutex mutex;
};

#endif
