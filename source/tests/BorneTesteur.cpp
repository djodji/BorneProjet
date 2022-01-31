/**
 * \file BorneTesteur.cpp
 * \brief Implantation des tests unitaires de la classe Borne
 *        Borne étant une classe abstraite, on crée une classe concrète
 *        dérivée de cette classe afin de pouvoir effectuer les tests
 * \author Abdelhafid El kanfoud
 * \date 4 avril 2011
 */

#include <gtest/gtest.h>
#include "Borne.h"
#include "ContratException.h"
using namespace std;
using namespace bornesQuebec;

/**
 * \class BorneDeTest
 * \brief classe de test permettant de tester la classe abstraite Borne
 */
class BorneDeTest : public Borne
{
public:

  BorneDeTest (const int p_identifiant, const string& p_direction, const string& p_nomTopographique, const double p_longitude, const double p_latitude) :
  Borne (p_identifiant, p_direction, p_nomTopographique, p_longitude, p_latitude) { }

  /* //instancie un objet Borne

  /*virtual
  ~Borne () { };*/

  virtual
  ~BorneDeTest () { };

  virtual string
  reqBorneFormate () const
  {
    return Borne::reqBorneFormate ();
  };

  Borne*
  clone () const
  {
    return new BorneDeTest (*this);
  }
};

/**
 * \brief Test du Constructeur
 *        Cas valides: Création d'un objet Borne et verification de l’assignation de tous les attributs
 * 	  Cas invalides:
 * 			identifiant <=0
 * 			direction autre que {"Nord", "Sud", "Est", "Ouest", "null"};
 * 			nomTopographique vide
 */
TEST (Borne, ConstructeurAvecParametre)
{
  BorneDeTest borneDeTest (5698, "Nord", "205 chemin du roy", 123655.32, 123365.332);
  ASSERT_EQ (5698, borneDeTest.reqIdentifiant ())
          ;
  ASSERT_EQ ("Nord", borneDeTest.reqDirection ())
          ;
  ASSERT_EQ ("205 chemin du roy", borneDeTest.reqNomTopographique ())
          ;
  ASSERT_EQ (123655.32, borneDeTest.reqLongitude ())
          ;
  ASSERT_EQ (123365.332, borneDeTest.reqLatitude ())
          ;
}
//cas invalide

TEST (Borne, ConstructeurInvalideIdentifiant)
{
  ASSERT_THROW (BorneDeTest BorneDeTest (-5698, "Nord", "205 chemin du roy", 123655.32, 123365.332), PreconditionException);
}

TEST (Borne, ConstructeurInvalideDirection)
{
  ASSERT_THROW (BorneDeTest BorneDeTest (-5698, "XYZ", "205 chemin du roy", 123655.32, 123365.332), PreconditionException);
}

TEST (Borne, ConstructeurInvalideNomTopographique)
{
  ASSERT_THROW (BorneDeTest BorneDeTest (-5698, "Sud", "", 123655.32, 123365.332), PreconditionException);
}

/**
 * \class UnBorne
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnBorne : public ::testing::Test
{
public:

  UnBorne () :
  t_borne (698, "Sud", "205 Av uLaval", 15986.32, 3659.255) { }
  ;

  BorneDeTest t_borne;
};

/**
 * \brief Test de la méthode  void asgNomTopographique (string& p_nomTopographique)
 *        Cas valide: assignation d'un nom topographique.
 *        Cas invalide: nom vide
 */

TEST_F (UnBorne, asgNomTopographiqueValid)
{

  t_borne.asgNomTopographique ("25 1er Av");
  ASSERT_EQ ("25 1er Av", t_borne.reqNomTopographique ());
}
//cas invalide

TEST_F (UnBorne, asgNomTopographiqueInvalid)
{

  ASSERT_THROW (t_borne.asgNomTopographique (""), PreconditionException);
}

/**
 * \test Test de la méthode reqIdentifiant()
 * 		Cas valide: vérifier le retour de l'identifiant
 * 		Cas invalide: aucun
 */
TEST_F (UnBorne, reqIdentifiant)
{
  ASSERT_EQ (698, t_borne.reqIdentifiant ());
}

/**
 * \test Test de la méthode reqDirection()
 * 		Cas valide: vérifier le retour de la direction
 * 		Cas invalide: aucun
 */
TEST_F (UnBorne, reqDirection)
{
  ASSERT_EQ ("Sud", t_borne.reqDirection ());
}

/**
 * \test Test de la méthode reqNomTopographique()
 * 		Cas valide: vérifier le retour du nom topographique
 * 		Cas invalide: aucun
 */
TEST_F (UnBorne, reqNomTopographique)
{
  ASSERT_EQ ("205 Av uLaval", t_borne.reqNomTopographique ());
}

/**
 * \test Test de la méthode reqLongitude()
 * 		Cas valide: vérifier le retour du longitude
 * 		Cas invalide: aucun
 */
TEST_F (UnBorne, reqLongitude)
{
  ASSERT_EQ (15986.32, t_borne.reqLongitude ());
}

/**
 * \test Test de la méthode reqLatitude()
 * 		Cas valide: vérifier le retour du latitude
 * 		Cas invalide: aucun
 */
TEST_F (UnBorne, reqLatitude)
{
  ASSERT_EQ (3659.255, t_borne.reqLatitude ());
}

/**
 * \test Test de la méthode bool operator== (const Borne& p_borne) const;
 * 		Cas valide: vérifier le retour de comparaison entre deux objets Bones
 * 		Cas invalide: aucun
 */

TEST_F (UnBorne, ComparaionDeuxBorneCasEgeaux)
{
  BorneDeTest t_borne2 (698, "Sud", "205 Av uLaval", 15986.32, 3659.255);
  ASSERT_TRUE (t_borne.operator== (t_borne2));
}

/**
 * \test Test de la méthode virtual string reqBorneFormate () const = 0;
 * 		Cas valide: vérifier le retour des information sur l'objets Borne formaté
 * 		Cas invalide: aucun
 */

TEST_F (UnBorne, reqBorneFormate)
{
  ostringstream chaine;
  chaine << "Identifiant de la borne\t : " << t_borne.reqIdentifiant ()
          << "\nDirection\t    : " << t_borne.reqDirection ()
          << "\nNom topographique   : " << t_borne.reqNomTopographique ()
          << "\nLongitude\t    : " << t_borne.reqLongitude ()
          << "\nLatitude\t    : " << t_borne.reqLatitude () << endl;
  ASSERT_EQ (chaine.str (), t_borne.reqBorneFormate ());
}

