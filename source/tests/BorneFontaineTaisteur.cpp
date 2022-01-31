/**
 * \file BorneFontaineTaisteur.cpp
 * \brief Implantation des tests unitaires de la classe BorneFontaine
 * \author Abdelhafid El kanfoud
 * \date 4 avril 2011 * \date 2 juin 2011
 */

#include <gtest/gtest.h>
#include "BorneFontaine.h"
#include "ContratException.h"
using namespace std;
using namespace bornesQuebec;

/**
 * \brief Test du Constructeur
 *        Cas valides: Création d'un objet BorneFontaine et verification de l’assignation de tous les attributs
 * 	  Cas invalides:
 * 			arrondissement  vide si la ville est « Québec »
 */


TEST (BorneFontaine, ConstructeurDefaut)
{
  BorneFontaine unBorneFontaine (12365, "Nord", "2365 rue gingra", 123655.32, 123365.332, "Québec", "Saint-Foy");
  ASSERT_EQ (12365, unBorneFontaine.reqIdentifiant ());
  ASSERT_EQ ("Nord", unBorneFontaine.reqDirection ());
  ASSERT_EQ ("2365 rue gingra", unBorneFontaine.reqNomTopographique ());
  ASSERT_EQ (123655.32, unBorneFontaine.reqLongitude ());
  ASSERT_EQ (123365.332, unBorneFontaine.reqLatitude ());
  ASSERT_EQ ("Québec", unBorneFontaine.reqVille ());
  ASSERT_EQ ("Saint-Foy", unBorneFontaine.reqArrondissement ());

}
//cas invalide

TEST (BorneFontaine, ConstructeurArrondissementInvalide)
{
  ASSERT_THROW (BorneFontaine unBorneFontaine (12365, "Nord", "2365 rue gingra", 123655.32, 123365.332, "Québec", ""), PreconditionException);
}

/**
 * \class UnBorneBorneFontaine
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnBorneBorneFontaine : public ::testing::Test
{
public:

  UnBorneBorneFontaine () :
  f_borne (4598, "Sud", "3040 rue de la fone", 123655.32, 123365.332, "Québec", "Charlesbourg") { }
  ;

  BorneFontaine f_borne;

};

/**
 * \test Test de la méthode reqVille()
 *     Cas valide: vérifier le retour de la ville  de la BorneBorneFontaine
 *     Cas invalide: aucun
 */

TEST_F (UnBorneBorneFontaine, reqVille)
{
  ASSERT_EQ ("Québec", f_borne.reqVille ());
}

/**
 * \test Test de la méthode reqArrondissement()
 *     Cas valide: vérifier le retour de l'Arrondissement  de la BorneBorneFontaine
 *     Cas invalide: aucun
 */
TEST_F (UnBorneBorneFontaine, reqArrondissement)
{
  ASSERT_EQ ("Charlesbourg", f_borne.reqArrondissement ());
}

/**
 * \brief Test de la méthode clone()
 *     Cas valide: faire une copie allouée sur le monceau de l'objet BorneBorneFontaine courant
 *     Cas invalide: aucun
 */

TEST_F (UnBorneBorneFontaine, clone)
{
  BorneFontaine f_borne2 (4598, "Sud", "3040 rue de la fone", 123655.32, 123365.332, "Québec", "Charlesbourg");
  ASSERT_TRUE ((f_borne2.clone ())->operator== (f_borne));

}

/**
 * \brief Test de la méthode string reqBorneFormate()
 *        Cas valides: vérifier le retour des information sur l'objets BorneBorneFontaine formatés
 *        Cas invalides: aucun
 */
TEST_F (UnBorneBorneFontaine, reqBorneFormate)
{
  ostringstream chaine;
  chaine << "Borne-fontaine\n"
          << "----------------------------------------------\n"
          << "Identifiant de la borne\t : " << f_borne.reqIdentifiant ()
          << "\nDirection\t    : " << f_borne.reqDirection ()
          << "\nNom topographique   : " << f_borne.reqNomTopographique ()
          << "\nLongitude\t    : " << f_borne.reqLongitude ()
          << "\nLatitude\t    : " << f_borne.reqLatitude () << endl
          << "Ville\t\t    : " << f_borne.reqVille ()
          << "\nArrondissement\t    : " << f_borne.reqArrondissement () << endl;
  ASSERT_EQ (chaine.str (), f_borne.reqBorneFormate ());
}