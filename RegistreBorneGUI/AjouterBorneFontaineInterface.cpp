/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AjouterBorneFontaineInterface.cpp
 * Author: etudiant
 *
 * Created on 18 avril 2021, 22:45
 */

#include "AjouterBorneFontaineInterface.h"
#include "validationFormat.h"
#include <qmessagebox.h>
using namespace util;

AjouterBorneFontaineInterface::AjouterBorneFontaineInterface (QWidget *parent) :
QDialog (parent)
{
  widget.setupUi (this);
}

AjouterBorneFontaineInterface::~AjouterBorneFontaineInterface () { }

int
AjouterBorneFontaineInterface::reqIdentifiant () const
{
  return widget.txtIdentifiant->value ();
}

QString
AjouterBorneFontaineInterface::reqDirection () const
{
  return widget.comboDirection -> currentText ();
}

QString
AjouterBorneFontaineInterface::reqNomTopographique () const
{
  return widget.txtNomTopo->text ();
}

double
AjouterBorneFontaineInterface::reqLongitude () const
{
  return widget.txtLongitude->value ();
}

double
AjouterBorneFontaineInterface::reqLatitude () const
{
  return widget.txtLatitude->value ();
}

QString
AjouterBorneFontaineInterface::reqVille () const
{
  return widget.txtVille->text ();
}

QString
AjouterBorneFontaineInterface::reqArrondissement () const
{
  return widget.txtArrondissement->text ();
}

void
AjouterBorneFontaineInterface::validerChamps ()
{
  QString message ("");

  if (widget.txtNomTopo->text ().isEmpty ())
    {
      message.append ("- Le nom topographique est obligatoire!\n");
    }
  if (!validerVille (reqVille ().toStdString (), reqArrondissement ().toStdString ()))
    {
      message.append ("- L’arrondissement ne doit pas être vide!\n");

    }
  if (message.size () > 0)
    {
      QMessageBox::information (this, "ERREUR", message);
    }
  else
    {
      accept ();
    }

}
