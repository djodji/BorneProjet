/**
 * \file BorneStationnementTesteur.cpp
 * \brief Implantation des tests unitaires de la classe BorneStationnement
 * \author Abdelhafid El kanfoud
 * \date 4 avril 2011 * \date 2 juin 2011
 */

#include <gtest/gtest.h>
#include "BorneStationnement.h"
#include "ContratException.h"
using namespace std;
using namespace bornesQuebec;

/**
 * \brief Test du Constructeur
 *        Cas valides: Création d'un objet BorneStationnement et verification de l’assignation de tous les attributs
 * 	  Cas invalides:
 * 			Type autre que « stationnement », ou « paiement ».
 *                      LectureMetrique <= 0.
 *                      Le numéro de la borne n'est pas composé de 1 à 4 chiffres.
 *                      Le coté ne correspondre pas à un point cardinal.
 */


TEST (BorneFontaine, ConstructeurDefaut)
{
  BorneStationnement objetBorne = BorneStationnement (5698, "Nord", "205 chemin du roy", 123655.32, 123365.332,
                                                      "stationnement", 1236, 1113, 5465, "Sud");
  ASSERT_EQ (5698, objetBorne.reqIdentifiant ());
  ASSERT_EQ ("Nord", objetBorne.reqDirection ());
  ASSERT_EQ ("205 chemin du roy", objetBorne.reqNomTopographique ());
  ASSERT_EQ (123655.32, objetBorne.reqLongitude ());
  ASSERT_EQ (123365.332, objetBorne.reqLatitude ());
  ASSERT_EQ ("stationnement", objetBorne.reqType ());
  ASSERT_EQ (1236, objetBorne.reqLectureMetrique ());
  ASSERT_EQ (1113, objetBorne.reqSegmentRue ());
  ASSERT_EQ (5465, objetBorne.reqNumBorne ());
  ASSERT_EQ ("Sud", objetBorne.reqCoteRue ());

}
//cas invalide

TEST (BorneFontaine, ConstructeurTypeInvalide)
{
  ASSERT_THROW (BorneStationnement BorneStat (5698, "Nord", "205 chemin du roy", 123655.32, 123365.332,
                                              "xyz", 1236, 1113, 5465, "Sud"), PreconditionException);
}

TEST (BorneFontaine, ConstructeurLectureMetriqueInvalide)
{
  ASSERT_THROW (BorneStationnement BorneStat (5698, "Nord", "205 chemin du roy", 123655.32, 123365.332,
                                              "stationnement", 0, 1113, 5465, "Sud"), PreconditionException);
}

TEST (BorneFontaine, ConstructeurNumBorneInvalide)
{
  ASSERT_THROW (BorneStationnement BorneStat (5698, "Nord", "205 chemin du roy", 123655.32, 123365.332,
                                              "stationnement", 1236, 1113, 65465, "Sud"), PreconditionException);
}

TEST (BorneFontaine, ConstructeurCoteRueInvalide)
{
  ASSERT_THROW (BorneStationnement BorneStat (5698, "Nord", "205 chemin du roy", 123655.32, 123365.332,
                                              "stationnement", 1236, 1113, 65465, "xyz"), PreconditionException);
}

/**
 * \class UnBorneStationnement
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnBorneStationnement : public ::testing::Test
{
public:

  UnBorneStationnement () :
  f_borne (456, "Est", "3050 Boulevard Laurier", 756.32, 986.332,
           "paiement", 1236, 1113, 5465, "Sud") { };

  BorneStationnement f_borne;

};

/**
 * \test Test de la méthode reqType()
 *     Cas valide: vérifier le retour de type de la BorneStationnement
 *     Cas invalide: aucun
 */

TEST_F (UnBorneStationnement, reqType)
{
  ASSERT_EQ ("paiement", f_borne.reqType ());

}

/**
 * \test Test de la méthode reqLectureMetrique()
 *     Cas valide: vérifier le retour de la distance mesurée à partir du début du tronçon dans le sens des numéros d'immeuble
 *     Cas invalide: aucun
 */

TEST_F (UnBorneStationnement, reqLectureMetrique)
{
  ASSERT_EQ (1236, f_borne.reqLectureMetrique ());

}

/**
 * \test Test de la méthode reqSegmentRue()
 *     Cas valide: vérifier le retour de l’identifiant du segment de voie publique
 *     Cas invalide: aucun
 */

TEST_F (UnBorneStationnement, reqSegmentRue)
{
  ASSERT_EQ (1113, f_borne.reqSegmentRue ());

}

/**
 * \test Test de la méthode reqNumBorne()
 *     Cas valide: vérifier le retour du numéro de la borne.
 *     Cas invalide: aucun
 */

TEST_F (UnBorneStationnement, reqNumBorne)
{
  ASSERT_EQ (5465, f_borne.reqNumBorne ());

}

/**
 * \test Test de la méthode reqCoteRue()
 *     Cas valide: vérifier le retour du coté par rapport au centre de chaussée où est la borne.
 *     Cas invalide: aucun
 */

TEST_F (UnBorneStationnement, reqCoteRue)
{
  ASSERT_EQ ("Sud", f_borne.reqCoteRue ());

}

/**
 * \brief Test de la méthode clone()
 *     Cas valide: faire une copie allouée sur le monceau de l'objet BorneStationnement courant
 *     Cas invalide: aucun
 */

TEST_F (UnBorneStationnement, clone)
{
  BorneStationnement f_borne2 (456, "Est", "3050 Boulevard Laurier", 756.32, 986.332,
                               "paiement", 1236, 1113, 5465, "Sud");
  ASSERT_TRUE ((f_borne2.clone ())->operator== (f_borne));

}

/**
 * \brief Test de la méthode string reqBorneFormate()
 *        Cas valides: vérifier le retour des information sur l'objets BorneStationnement formatés
 *        Cas invalides: aucun
 */
TEST_F (UnBorneStationnement, reqBorneFormate)
{
  ostringstream chaine;
  chaine << "Borne de stationnement\n"
          << "----------------------------------------------\n"
          << "Identifiant de la borne\t : " << f_borne.reqIdentifiant ()
          << "\nDirection\t    : " << f_borne.reqDirection ()
          << "\nNom topographique   : " << f_borne.reqNomTopographique ()
          << "\nLongitude\t    : " << f_borne.reqLongitude ()
          << "\nLatitude\t    : " << f_borne.reqLatitude () << endl
          << "Distance mesuree    : " << f_borne.reqLectureMetrique ()
          << "\nSegment de rue\t    : " << f_borne.reqSegmentRue ()
          << "\nNumero de la borne  : " << f_borne.reqNumBorne ()
          << "\nCote de la rue\t    : " << f_borne.reqCoteRue () << endl;
  ASSERT_EQ (chaine.str (), f_borne.reqBorneFormate ());
}


