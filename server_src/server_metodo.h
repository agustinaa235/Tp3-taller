#ifndef METODO_H
#define METODO_H

#include <string>
#include <fstream>

class Metodo{
    public:
          virtual std::string obtener_respuesta() = 0;
          virtual ~Metodo(){}
};

#endif
