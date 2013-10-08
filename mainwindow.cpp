#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *zoneCentrale = new QWidget;


    layoutPrincipal = new QVBoxLayout;
    ajouterBouton = new QPushButton(this);
    ajouterBouton->setText(tr("Ajouter"));
    ajouterBouton->setDefault(true);
    ajouterBouton->setIcon(QIcon(":/img/Actions-document-new-icon.png"));
    supprimerBouton = new QPushButton(this);
    supprimerBouton->setText(tr("Supprimer"));
    supprimerBouton->setIcon(QIcon(":/img/Actions-document-close-icon.png"));
    quitterBouton = new QPushButton(this);
    quitterBouton->setText(tr("Quitter"));
    quitterBouton->setIcon(QIcon(":/img/delete-icon.png"));


    importantCheckBox = new QCheckBox("&Important", this);

    tableHeader << tr("Important") << tr("Tâche");

    todoTable = new QTableWidget;
    todoTable->setColumnCount(2);
    todoTable->setHorizontalHeaderLabels(tableHeader);
    todoTable->setShowGrid(true);
    /*todoTable->setItem(1,1,new QTableWidgetItem("hello"));
    todoTable->setStyleSheet("QTableView {selection-background-color: red;}");*/

    tacheEdit = new QLineEdit;

    boutonLayout = new QHBoxLayout;
    boutonLayout->addWidget(quitterBouton);
    boutonLayout->addStretch();
    boutonLayout->addWidget(supprimerBouton);
    boutonLayout->addWidget(ajouterBouton);

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
    connect(quitterBouton, SIGNAL(clicked()), qApp, SLOT(quit()));
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
    actionOuvrirFichier->setIcon(QIcon(":/img/Actions-document-open-icon.png"));
    connect(actionOuvrirFichier, SIGNAL(triggered()), this, SLOT(OuvrirFichier()));
    menuFichier->addAction(actionOuvrirFichier);

    actionSauver = new QAction(tr("Sauver"), this);
    actionSauver->setShortcut(QKeySequence("Ctrl+S"));
    connect(actionSauver, SIGNAL(triggered()), this, SLOT(SauverFichier()));
    menuFichier->addAction(actionSauver);
    menuFichier->addSeparator();


    QAction *actionQuitter = new QAction(tr("&Quitter"), this);
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    actionQuitter->setIcon(QIcon(":/img/delete-icon.png"));
    menuFichier->addAction(actionQuitter);

    QMenu *menuOutils = menuBar()->addMenu(tr("&Outis"));
    QAction *ActionaboutApp = new QAction(tr("A propos de Todo"), this);
    menuOutils->addAction(ActionaboutApp);
    QAction *aboutQt = new QAction(tr("A propos de Qt"), this);
    menuOutils->addAction(aboutQt);



    connect(ActionaboutApp, SIGNAL(triggered()), this, SLOT(aproposApp()));
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
    else
    {
        QTableWidgetItem *newItem = new QTableWidgetItem(tr("hellworld"));
        todoTable->setItem(0,1,newItem);

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
        // button yes

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

/* fonction : aproposApp
 * type : private slot
 */

void MainWindow::aproposApp()
{
    proposAppDialog *aboutbox = new proposAppDialog;
    aboutbox->exec();
}

MainWindow::~MainWindow()
{

}
