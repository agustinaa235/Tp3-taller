#ifndef METODO_INVALIDO_H
#define METODO_INVALIDO_H

#include "server_metodo.h"
#include <string>

class Invalida: public Metodo {
    public:
        /*
          * creara la clase invalida dejandola valida
        */
        explicit Invalida(const std::string& instruccion_invalida);
        /*
          * liberara invalida con todos sus recursos
        */
        ~Invalida();
        /*
          * devolvera la respuesta del servidor
        */
        std::string obtener_respuesta() override;
        
    private:
          std::string instruccion_invalida;
};

#endif
