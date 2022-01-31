/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 17 avril 2021, 15:57
 */

#include <QApplication>
#include "RegistreBorneGUI.h"

int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  // create and show your widgets here
  RegistreBorneGUI fenetre;
  fenetre.show ();

  return app.exec ();
}
