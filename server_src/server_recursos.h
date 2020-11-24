#ifndef SERVER_RECURSOS_H
#define SERVER_RECURSOS_H

#include <map>
#include <string>
#include <mutex>
#include <utility>

class Servidor_Recursos{
    public:
        /*
          * creara al servidor de recursos dejandolo valido para uso
        */
        explicit Servidor_Recursos(const std::string& nombre_archivo);
        /*
          * liberara el servidor de recursos junto a sus recursos
        */
        ~Servidor_Recursos();
        /*
          * agregara el recurso que le llega al mapa junto a su body
        */
        void agregar_recurso(const std::string& recurso,
                              const std::string& cuerpo);
        /*
          * devuelve el nombre del archivo
        */
        std::string obtener_nombre_archivo() const;
        /*
          * devuelve el el body del recurso asociado
        */
        std::string obtener_recurso(const std::string& recurso);

    private:
        std::map<std::string, std::string> mapa_de_recursos;
        std::string nombre_archivo;
        std::mutex mutex;
};

#endif
