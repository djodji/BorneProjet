/**
 * \file BorneException.cpp
 * \brief Implementation de la classe BorneException et ses dérivées
 * \author bdelhafid El kanfoud et djodji Komlan
 * \date 17 avril 2021, 20:11
 */

#include <string>
#include "Borne.h"
#include <vector>

using namespace std;

#ifndef BORNEEXCEPTION_H
#define BORNEEXCEPTION_H
namespace bornesQuebec
{

  /**
   * \class BorneException
   * \brief Cette classe permet de gérer les exceptions liées aux bornes.
   **/

  class BorneException : public std::runtime_error
  {
  public:

    BorneException (const string& p_raison) : runtime_error (p_raison) { }
  };

  /**
   * \class BorneDejaPresenteException
   * \brief Cette classe permet de gérer l’exception de l’ajout d’un doublon de Borne dans la liste des bornes.
   *        Cette classe hérite de BorneException
   **/

  class BorneDejaPresenteException : public BorneException
  {
  public:

    BorneDejaPresenteException (const string& p_raison) : BorneException (p_raison) { }

  };

  /**
   * \class Cette classe permet de gérer l’exception de la tentative d’effacement d’une Borne absente dans la liste des bornes.
   * Cette classe hérite de BorneException
   **/

  class BorneAbsenteException : public BorneException
  {
  public:

    BorneAbsenteException (const string& p_raison) : BorneException (p_raison) { }

  };
}

#endif /* BORNEEXCEPTION_H */

