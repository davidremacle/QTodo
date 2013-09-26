#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *zoneCentrale = new QWidget;

    layoutPrincipal = new QVBoxLayout;
    ajouterBouton = new QPushButton(this);
    ajouterBouton->setText(tr("Ajouter"));
    ajouterBouton->setDefault(true);
    supprimerBouton = new QPushButton(this);
    supprimerBouton->setText(tr("Supprimer"));
    importantCheckBox = new QCheckBox("&Important", this);

    tableHeader << tr("Important") << tr("Tâche");

    todoTable = new QTableWidget;
    todoTable->setColumnCount(2);
    todoTable->setHorizontalHeaderLabels(tableHeader);
    todoTable->setShowGrid(true);
    todoTable->setItem(0,1,new QTableWidgetItem("hello"));
    todoTable->setStyleSheet("QTableView {selection-background-color: red;}");

    tacheEdit = new QLineEdit;

    boutonLayout = new QHBoxLayout;

    boutonLayout->addWidget(ajouterBouton);
    boutonLayout->addStretch();
    boutonLayout->addWidget(supprimerBouton);

    QGroupBox *mygroup = new QGroupBox(this);
    QHBoxLayout *groupoxlayout = new QHBoxLayout;
    mygroup->setTitle(tr("Tâche a ajouter :"));

    QFormLayout *formlayout = new QFormLayout;

    formlayout->addRow(tr("Tache : "), tacheEdit);
    formlayout->addWidget(importantCheckBox);

    groupoxlayout->addLayout(formlayout);
    mygroup->setLayout(groupoxlayout);

    layoutPrincipal->addWidget(todoTable);
    layoutPrincipal->addWidget(mygroup);
    layoutPrincipal->addLayout(boutonLayout);

    makeMenu();

    zoneCentrale->setLayout(layoutPrincipal);

    setCentralWidget(zoneCentrale);

    connect(ajouterBouton, SIGNAL(clicked()), this, SLOT(ajouterTache()));
    connect(supprimerBouton, SIGNAL(clicked()), this, SLOT(supprimerTache()));
}

/*
 * Fonction MakeMenu()
 * type : private fonction
 *
 */

void MainWindow::makeMenu()
{
    QMenu *menuFichier = menuBar()->addMenu(tr("&Fichier"));
    QAction *actionOuvrirFichier = new QAction(tr("&Ouvrir"), this);
    actionOuvrirFichier->setShortcut(QKeySequence("Ctrl+O"));
    connect(actionOuvrirFichier, SIGNAL(triggered()), this, SLOT(OuvrirFichier()));
    menuFichier->addAction(actionOuvrirFichier);

    actionSauver = new QAction(tr("Sauver"), this);
    actionSauver->setShortcut(QKeySequence("Ctrl+S"));
    connect(actionSauver, SIGNAL(triggered()), this, SLOT(SauverFichier()));
    menuFichier->addAction(actionSauver);
    menuFichier->addSeparator();


    QAction *actionQuitter = new QAction(tr("&Quitter"), this);
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    menuFichier->addAction(actionQuitter);

    QMenu *menuOutils = menuBar()->addMenu(tr("&Outis"));
    QAction *aboutQt = new QAction(tr("A propos de Qt"), this);
    menuOutils->addAction(aboutQt);


    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(aboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

/* Ajouter Tâche
 * Fonction : ajouter les tache dans le vue
 * Type : private Slot
 */

void MainWindow::ajouterTache()
{

    if (tacheEdit->text().isEmpty())
    {
        QMessageBox affbox;
        affbox.setText(tr("Il faut au moins mettre une désignation de la tâche."));
        affbox.setIcon(QMessageBox::Information);
        affbox.exec();
    }

}

/*
 * Fonction : Supprimer les tâches de la vue
 * Type : Private Slot
 *
 */

void MainWindow::supprimerTache()
{
    QMessageBox *suppbox = new QMessageBox;
    suppbox->setText(tr("Supprimer la tache ?"));

    suppbox->setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    suppbox->setIcon(QMessageBox::Critical);
    suppbox->setDefaultButton(QMessageBox::No);
    int ret = suppbox->exec();

    switch(ret){
    case QMessageBox::Yes:
        //Supprimertache
        break;
    case QMessageBox::No:
        //exit Dialog

        break;
    default:
        //never this be reacher
        break;
    }
}


/*
 * Fonction : OuvrirFichier()
 * Type : private Slot
 *
 */
void MainWindow::OuvrirFichier()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Text (*txt)");
    QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + fichier);
}

/* Fonction : SauverFichier()
 * Type : private slot
 *
 */

void MainWindow::SauverFichier()
{
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Text (*.txt)");
    QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + fichier);
}

MainWindow::~MainWindow()
{

}
