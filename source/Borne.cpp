/**
 * \file Borne.cpp
 * \brief Implementation de la classe Borne
 * \author bdelhafid El kanfoud et djodji Komlan
 * \date 4 avril 2021, 20:11
 */

#include "ContratException.h"
#include "Borne.h"
#include "validationFormat.h"
#include <iostream>
#include <sstream>
#include <iomanip>
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
   * \pre p_identifiant un entier strictement positif.
   * \pre p_direction correspondre à un point cardinal parmis {"Nord", "Sud", "Est", "Ouest", "null"};
   * \pre p_nomTopographique non vide
   * \post m_identifiant prend la valeur de p_identifiant
   * \post m_direction prend la valeur de p_direction
   * \post m_nomTopographique prend la valeur de p_nomTopographique
   * \post m_longitude prend la valeur de p_longitude
   * \post m_latitude prend la valeur de p_latitude
   */
  Borne::Borne (const int p_identifiant, const string& p_direction, const string& p_nomTopographique, const double p_longitude, const double p_latitude) :
  m_identifiant (p_identifiant), m_direction (p_direction), m_nomTopographique (p_nomTopographique), m_longitude (p_longitude), m_latitude (p_latitude)
  {
    PRECONDITION (p_identifiant > 0);
    PRECONDITION (util::validerPointCardinal (p_direction));
    PRECONDITION (!p_nomTopographique.empty ());

    POSTCONDITION (m_identifiant == p_identifiant);
    POSTCONDITION (m_direction == p_direction);
    POSTCONDITION (m_nomTopographique == p_nomTopographique);
    POSTCONDITION (m_longitude == p_longitude);
    POSTCONDITION (m_latitude == p_latitude);
    INVARIANTS ();
  }

  /**
   * \brief Accesseur pour L’identifiant de la borne.
   * \return m_identifiant L’identifiant.
   */

  int
  Borne::reqIdentifiant () const
  {
    return m_identifiant;
  }

  /**
   * \brief Accesseur pour Le côté du centre de chaussée ou l’intersection dans le cas d’un terre-plein.
   * \return m_direction Le côté du centre de chaussée ou l’intersection dans le cas d’un terre-plein.
   */


  const string&
  Borne::reqDirection () const
  {
    return m_direction;
  }

  /**
   * \brief Accesseur pour LLe nom topographique (générique, liaison, spécifique, direction) du centre de chaussée.
   * \return m_nomTopographique  Le nom topographique
   */

  const string&
  Borne::reqNomTopographique () const
  {
    return m_nomTopographique;
  }

  /**
   * \brief Accesseur pour La longitude
   * \return m_longitude La longitude
   */

  double
  Borne::reqLongitude () const
  {
    return m_longitude;
  }

  /**
   * \brief Accesseur pour La latitude.
   * \return m_latitude la latitude.
   */


  double
  Borne::reqLatitude () const
  {
    return m_latitude;
  }

  /**
   * \brief Mutateur pour Le nom topographique du centre de chaussée
   * \param[in] p_nomTopographique un string qui représente Le nom topographique (générique, liaison, spécifique, direction) du centre de chaussée.
   * \pre p_nomTopographique non vide
   * \post m_nomTopographique prend la valeur de p_nomTopographique
   */

  void
  Borne::asgNomTopographique (const string& p_nomTopographique)
  {
    PRECONDITION (!p_nomTopographique.empty ());
    m_nomTopographique = p_nomTopographique;
    POSTCONDITION (m_nomTopographique == p_nomTopographique);
    INVARIANTS ();
  }

  /**
   * \brief L’opérateur de comparaison d’égalité. La comparaison se fait sur la base de tous les attributs.
   * \param[in] p_borne un objet de typle Borne.
   * \return true si les deux ibjets sont égeaux. false sinon.
   */

  bool
  Borne::operator== (const Borne& p_borne) const
  {
    return m_identifiant == p_borne.reqIdentifiant () &&
            m_direction == p_borne.reqDirection () &&
            m_nomTopographique == p_borne.reqNomTopographique () &&
            m_longitude == p_borne.reqLongitude () &&
            m_latitude == p_borne.reqLatitude ();
  }

  /**
   * \brief Affiche les informations de l'objet Borne sous forme d'une chaîne de caractère formatée
   * \return une chaîne de caractère contient les informations de l'objet
   */

  string
  Borne::reqBorneFormate () const
  {
    ostringstream chaine;
    chaine << "Identifiant de la borne\t : " << m_identifiant
            << "\nDirection\t    : " << m_direction
            << "\nNom topographique   : " << m_nomTopographique
            << "\nLongitude\t    : " << m_longitude
            << "\nLatitude\t    : " << m_latitude << endl;
    return chaine.str ();
  }

  /**
   * \brief Vérifie les invariants de la classe
   */

  void
  Borne::verifieInvariant () const
  {
    INVARIANT (m_identifiant > 0);
    INVARIANT (util::validerPointCardinal (m_direction));
    INVARIANT (!m_nomTopographique.empty ());
  }

}

