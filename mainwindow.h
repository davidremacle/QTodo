#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "proposappdialog.h"

#include <QMainWindow>
#include <QPushButton>
#include <QFileDialog>
#include <QLineEdit>
#include <QLabel>
#include <QWidget>
#include <QGroupBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QSpacerItem>
#include <QApplication>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>
#include <QIcon>

#include <QTabBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void ajouterTache();
    void supprimerTache();
    void OuvrirFichier();
    void SauverFichier();
    void aproposApp();

private:
    QVBoxLayout *layoutPrincipal;
    QHBoxLayout *boutonLayout;
    QPushButton *ajouterBouton;
    QPushButton *supprimerBouton;
    QPushButton *quitterBouton;
    QCheckBox *importantCheckBox;


    QTableWidget *todoTable;
    QTableWidgetItem *todoItem;

    QLineEdit *tacheEdit;

    QStringList tableHeader;

    QAction *actionSauver;



    void makeMenu();
};

#endif // MAINWINDOW_H
