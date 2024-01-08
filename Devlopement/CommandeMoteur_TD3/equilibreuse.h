#ifndef EQUILIBREUSE_H
#define EQUILIBREUSE_H

#include <QMainWindow>
#include "mcculdaq.h"
#include "moteur.h"
#include "capot.h"
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class Equilibreuse; }
QT_END_NAMESPACE

class Equilibreuse : public QMainWindow
{
    Q_OBJECT

public:

    Equilibreuse(QWidget *parent = nullptr);
    ~Equilibreuse();

public slots:
    void onCapot_EtatCapotChange(const bool _etat);
private slots:
    void on_pushButton_Lancer_clicked();

    void on_pushButton_Arreter_clicked();

private:
    Ui::Equilibreuse *ui;
    MccUldaq laCarte;
    Moteur *leMoteur;
    Capot *leCapot;
    int DIO0 = 0;
    QLabel labelEtatCapot;
#endif // EQUILIBREUSE_H
};
