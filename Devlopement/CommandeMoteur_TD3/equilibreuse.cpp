#include "equilibreuse.h"
#include "ui_equilibreuse.h"

Equilibreuse::Equilibreuse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Equilibreuse)// Allocate memory for Moteur

{
    ui->setupUi(this);
    leCapot = new Capot(laCarte, DIO0, this);
    connect(leCapot,&Capot::EtatCapotChange,this,&Equilibreuse::onCapot_EtatCapotChange);
    ui->statusbar->addPermanentWidget(&labelEtatCapot);
    leMoteur = new Moteur(laCarte, 0,4);

}



void Equilibreuse::onCapot_EtatCapotChange(const bool _etat)
{
    QPalette palette;
        labelEtatCapot.setAutoFillBackground(true);
        if(_etat)
        {
            palette.setColor(QPalette::WindowText,Qt::black);
            labelEtatCapot.setPalette(palette);
            labelEtatCapot.setText("| Capot Fermé |");
        }
        else
        {
            palette.setColor(QPalette::WindowText,Qt::red);
            labelEtatCapot.setPalette(palette);
            labelEtatCapot.setText("| Capot Ouvert |");
        }
}

Equilibreuse::~Equilibreuse()
{
    delete ui;
}

void Equilibreuse::on_pushButton_Lancer_clicked()
{
    ui->pushButton_Lancer-> setText("Fixer Consigne");
    leMoteur->FixerConsigneVitesse(ui->dial_ConsigneVitesse->value());

    }


void Equilibreuse::on_pushButton_Arreter_clicked()
{
    ui->pushButton_Lancer->setText("Lancer Moteur");
    leMoteur->FixerConsigneVitesse(0);
}




