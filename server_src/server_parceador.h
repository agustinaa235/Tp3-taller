#ifndef PARCEADOR_H
#define PARCEADOR_H

#include <sstream>
#include "server_metodo.h"
#include "server_recursos.h"
#include <string>
class Parceador{
    public:
          Parceador();
          ~Parceador();
          Metodo* parcear_petitorio(std::stringstream& petitorio,
                                    Servidor_Recursos* recursos);
          std::string primera_linea(std::stringstream& petitorio);
    private:
};

#endif
