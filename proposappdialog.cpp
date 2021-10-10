#include "proposappdialog.h"

proposAppDialog::proposAppDialog(QWidget *parent) :
    QDialog(parent)
{

    labelInfo = new QLabel();
    labelInfo->setText("Todo 1.0<br />&copy; David Remacle 2012");
    okButton = new QPushButton();
    okButton->setText("&Ok");
    connect(okButton, SIGNAL(clicked()), this, SLOT(close()));
    iconLabel = new QLabel;

    layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(labelInfo);
    layoutPrincipal->addWidget(okButton);

    setLayout(layoutPrincipal);
}
