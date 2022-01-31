/**
 * \file BorneFontaine.cpp
 * \brief Implementation de la classe BorneFontaine
 * \author bdelhafid El kanfoud et djodji Komlan
 * \date 4 avril 2021, 20:11
 */

#include "ContratException.h"
#include "BorneFontaine.h"
#include "validationFormat.h"
#include <iostream>
#include <sstream>
using namespace util;

namespace bornesQuebec
{

  /**
   * \brief Constructeur avec parametres
   *        Création d'un objet Borne à partir de valeurs passées en paramètres.
   * \param[in] p_identifiant un entier qui représente L’identifiant de la borne.
   * \param[in] p_direction un string qui représente Le côté du centre de chaussée ou l’intersection dans le cas d’un terre-plein.
   * \param[in] p_nomTopographique un string qui représente Le nom topographique (générique, liaison, spécifique, direction) du centre de chaussée.
   * \param[in] p_longitude un nombre réel qui représente La longitude.
   * \param[in] p_latitude un nombre réel qui représente Le coté par rapport au centre de chaussée ou l’intersection dans le cas d’un terre-plein.
   * \param[in] p_ville un string représente la ville dans lesquel se trouve la BorneFontaine.
   * \param[in] p_arrondissement un string représente l'arrondissement dans lesquel se trouve la BorneFontaine.
   * \pre p_arrondissement ne doit pas être vide si p_ville est « Québec »
   * \post m_ville prend la valeur de p_ville
   * \post m_arrondissement prend la valeur de p_arrondissement
   */

  BorneFontaine::BorneFontaine (const int p_identifiant, const string& p_direction,
                                const string& p_nomTopographique, const double p_longitude,
                                const double p_latitude, const string& p_ville, const string& p_arrondissement) :
  Borne (p_identifiant, p_direction, p_nomTopographique, p_longitude, p_latitude),
  m_ville (p_ville), m_arrondissement (p_arrondissement)
  {
    PRECONDITION (util::validerVille (p_ville, p_arrondissement));


    POSTCONDITION (m_ville == p_ville);
    POSTCONDITION (m_arrondissement == p_arrondissement);
  }

  /**
   * \brief Accesseur pour la ville.
   * \return m_ville la ville.
   */

  const string&
  BorneFontaine::reqVille () const
  {
    return m_ville;
  }

  /**
   * \brief Accesseur pour l'arrondissement.
   * \return m_arrondissement l'arrondissement.
   */

  const string&
  BorneFontaine::reqArrondissement () const
  {
    return m_arrondissement;
  }

  /**
   * \brief faire une copie allouée sur le monceau de l'objet BorneFontaine courant.
   * \return une copie allouée sur le monceau de l'objet BorneFontaine courant.
   */

  Borne*
  BorneFontaine::clone () const
  {
    return new BorneFontaine (*this);
  }

  /**
   * \brief Affiche les informations de l'objet Borne fontaine sous forme d'une chaîne de caractère formatée
   * \return une chaîne de caractère contient les informations de l'objet
   */

  string
  BorneFontaine::reqBorneFormate () const
  {
    ostringstream chaine;
    chaine << "Borne-fontaine\n"
            << "----------------------------------------------\n"
            << Borne::reqBorneFormate ()
            << "Ville\t\t    : " << m_ville
            << "\nArrondissement\t    : " << m_arrondissement << endl;
    return chaine.str ();
  }

  /**
   * \brief Vérifie les invariants de la classe
   */

  void
  BorneFontaine::verifieInvariant () const
  {
    INVARIANT (util::validerVille (m_ville, m_arrondissement));
  }
}