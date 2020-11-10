#ifndef METODO_POST_H
#define METODO_POST_H

#include "server_metodo.h"
#include <string>
#include <fstream>

class Post_Con_Recurso: public Metodo {
    public:
        /*
          * creara la clase post con recurso dejandola valida para uso
        */
        explicit Post_Con_Recurso(const std::string& body);
        /*
          * Liberara la clase post con recurso
        */
        ~Post_Con_Recurso();
        /*
          * devolvera la respuesta correspondiente
        */
        std::string obtener_respuesta() override;
        
    private:
        std::string body;
};

class Post_Sin_Recurso: public Metodo {
    public:
        /*
          * creara la clase post sin recurso dejandola valida para uso
        */
        Post_Sin_Recurso();
        /*
          * liberara la clase post sin recurso
        */
        ~Post_Sin_Recurso();
        /*
          * devolvera la respuesta correspondiente
        */
        std::string obtener_respuesta() override;
};

#endif
