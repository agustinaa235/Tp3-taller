#ifndef PARCEADOR_H
#define PARCEADOR_H

#include <sstream>
#include "server_metodo_get.h"
#include "server_metodo_post.h"
#include "server_metodo_invalido.h"
#include "server_recursos.h"
#include <string>

class Parceador{
    public:
          /*
            * creara al parceador dejandolo valido para uso
          */
          Parceador();
          /*
            * liberara al parceador
          */
          ~Parceador();
          /*
            * parceara a al petitorio que le llega y creara y devolvera
            * el correspondiente metodo
          */
          Metodo* parcear_petitorio(std::stringstream& petitorio,
                                    Servidor_Recursos& recursos) const;
          /*
            * devuelve la primera linea del parceo
          */
          std::string operator()(std::stringstream& petitorio) const;
};

#endif
