
/**
 * \file validationFormat.cpp
 * \author bdelhafid El kanfoud
 * \date 22 février 2021, 20:11
 */

// CppUnit site http://sourceforge.net/projects/cppunit/files

#include <cstdlib>
#include <iostream>
#include <sstream>
#include "validationFormat.h"

using namespace std;

namespace util
{

  bool
  valideLigneCVS (const std::string& p_ligne, std::ostringstream& p_parametres)
  {
    string informations = "";

    bool intormation_valide = true;
    int nombre_information = 0;
    for (int i = 0; i < p_ligne.size () && intormation_valide; i++)
      {
        if (p_ligne[i] == '|')
          {
            if (nombre_information != 4)
              {
                intormation_valide = informations.size () > 0;
              }
            p_parametres << informations + ",";
            nombre_information += 1;
            informations = "";
          }
        else
          {
            informations += p_ligne[i];
            if (i == p_ligne.size () - 1)
              {
                p_parametres << informations;
                nombre_information += 1;
              }

          }
      }
    intormation_valide &= nombre_information == 9;
    if (!intormation_valide)
      {
        p_parametres.str ("");
      }
    return intormation_valide;
  }

  bool
  validerGeom (const std::string& p_geom)
  {
    bool coordonnees_valides = true;
    if (p_geom.size () >= 11)
      {
        if (p_geom.substr (0, 7) == "POINT (" && p_geom[p_geom.size () - 1] == ')')
          {
            string coordonnees = p_geom.substr (7, p_geom.size () - 8);
            istringstream is_chaine (coordonnees);
            double longitude;
            is_chaine >> longitude;
            if (!is_chaine)
              {
                coordonnees_valides = false;
              }
            double latitude;
            is_chaine >> latitude;
            if (!is_chaine)
              {
                coordonnees_valides = false;
              }
          }
        else
          {
            coordonnees_valides = false;
          }
      }
    else
      {
        coordonnees_valides = false;
      }
    return coordonnees_valides;
  }

  bool
  valideStationnementGEOJSON (const std::string& p_enregistrement, std::ostringstream& p_attributs)
  {
    bool valide = true;
    return valide;
  }

  /**
   * \brief valide le format d’un point cardinal. Les valeurs possibles d’un point cardinal sont :Nord, Sud, Est, Ouest, null, « chaine vide »
   * \return un true si le format est valide sinon false
   */

  bool
  validerPointCardinal (const std::string& p_cardinalite)
  {
    bool validCardinalite = false;
    string tableau_cardinalite[5] = {"Nord", "Sud", "Est", "Ouest", "null"};
    if (p_cardinalite.size () == 0)
      {
        validCardinalite = true;
      }
    else
      {
        for (int i = 0; i < 5 && !validCardinalite; i++)
          {
            if (tableau_cardinalite[i] == p_cardinalite)
              {
                validCardinalite = true;
              }
          }
      }
    return validCardinalite;
  }

  bool
  validerVille (const string& p_ville, const string& p_arrondissement)
  {
    bool arrondissementValid = true;
    if (p_ville == "Québec")
      {
        arrondissementValid = !p_arrondissement.empty ();
      }
    return arrondissementValid;
  }
}

