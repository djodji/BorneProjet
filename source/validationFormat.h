
/**
 * \file validationFormat.H
 * \author bdelhafid El kanfoud et djodji Komlan
 * \date 22 février 2021, 20:11
 */


#include <string>

namespace util
{

  bool valideLigneCVS (const std::string& p_ligne, std::ostringstream& p_parametres);
  bool validerGeom (const std::string& p_geom);
  bool valideStationnementGEOJSON (const std::string& p_enregistrement, std::ostringstream& p_attributs);
  double convertirChaineEnDouble (const std::string& p_chaine);
  bool validerPointCardinal (const std::string& p_cardinalite);
  bool validerVille (const std::string& p_ville, const std::string& p_arrondissement);
}