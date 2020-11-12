#ifndef METODO_GET_H
#define METODO_GET_H

#include "server_metodo.h"
#include <string>
#include <fstream>

class Get_Con_Recurso: public Metodo {
    public:
          /*
            * creara la clase get con recurso dejandola valida para uso
          */
          explicit Get_Con_Recurso(const std::string& body);
          /*
            * liberara la clase get con recurso con sus recursos
          */
          ~Get_Con_Recurso();
          /*
            * devolvera la respuesta correspondiente
          */
           std::string obtener_respuesta() override;

    private:
          std::string body;
};

class Get_Sin_Recurso: public Metodo {
    public:
          /*
            * creara la clase get sin recurso dejandola valida para uso
          */
          explicit Get_Sin_Recurso(const std::string& nombre_archivo);
          /*
            * liberara la clase get sin recurso
          */
          ~Get_Sin_Recurso();
          /*
            * devolvera la respuesta correspondiente
          */
          std::string obtener_respuesta() override;

    private:
           std::ifstream archivo;
};

#endif
