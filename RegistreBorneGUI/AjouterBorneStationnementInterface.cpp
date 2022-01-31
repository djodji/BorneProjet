/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AjouterBorneStationnementInterface.cpp
 * Author: etudiant
 *
 * Created on 18 avril 2021, 21:45
 */

#include "AjouterBorneStationnementInterface.h"
#include <qmessagebox.h>

AjouterBorneStationnementInterface::AjouterBorneStationnementInterface (QWidget *parent) :
QDialog (parent)
{
  widget.setupUi (this);
}

AjouterBorneStationnementInterface::~AjouterBorneStationnementInterface () { }

int
AjouterBorneStationnementInterface::reqIdentifiant () const
{
  return widget.txtIdentifiant->value ();
}

QString
AjouterBorneStationnementInterface::reqDirection () const
{
  return widget.comboDirection -> currentText ();
}

QString
AjouterBorneStationnementInterface::reqNomTopographique () const
{
  return widget.txtNomTopo->text ();
}

double
AjouterBorneStationnementInterface::reqLongitude () const
{
  return widget.txtLongitude->value ();
}

double
AjouterBorneStationnementInterface::reqLatitude () const
{
  return widget.txtLatitude->value ();
}

QString
AjouterBorneStationnementInterface::reqType () const
{
  return widget.comboType->currentText ();
}

double
AjouterBorneStationnementInterface::reqLectureMetrique () const
{
  return widget.txtDistance->value ();
}

int
AjouterBorneStationnementInterface::reqSegmentRue () const
{
  return widget.txtSegment->value ();
}

int
AjouterBorneStationnementInterface::reqNumBorne () const
{
  return widget.txtNumBorne->value ();
}

QString
AjouterBorneStationnementInterface::reqCoteRue () const
{
  return widget.comboCote->currentText ();
}

void
AjouterBorneStationnementInterface::validerChamps ()
{
  QString message ("");
  if (widget.txtNomTopo->text ().isEmpty ())
    {
      message.append ("- Le nom topographique est obligatoire!\n");
    }
  if (widget.txtDistance->value () <= 0)
    {
      message.append ("- La distance doit étre  strictement positive!\n");
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
