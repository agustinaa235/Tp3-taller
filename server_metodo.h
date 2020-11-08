#ifndef METODO_H
#define METODO_H

#include <string>
#include <fstream>

class Metodo{
    public:
          virtual std::string obtener_respuesta() = 0;
          virtual ~Metodo(){}
};

class Get_Con_Recurso: public Metodo {
    public:
          Get_Con_Recurso(std::string& body);
          ~Get_Con_Recurso();
           std::string obtener_respuesta() override;
    private:
          std::string body;
};

class Get_Sin_Recurso: public Metodo {
    public:
          Get_Sin_Recurso(std::string& nombre_archivo);
          ~Get_Sin_Recurso();
          std::string obtener_respuesta() override;
    private:
           std::ifstream archivo;
};

class Post_Con_Recurso: public Metodo {
    public:
        Post_Con_Recurso(std::string& body);
        ~Post_Con_Recurso();
        std::string obtener_respuesta() override;
    private:
        std::string body;
};

class Post_Sin_Recurso: public Metodo {
    public:
        Post_Sin_Recurso();
        ~Post_Sin_Recurso();
        std::string obtener_respuesta() override;
};
class Invalida: public Metodo {
    public:
        Invalida(std::string& instruccion_invalida);
        ~Invalida();
        std::string obtener_respuesta() override;
    private:
          std::string instruccion_invalida;
};

#endif
