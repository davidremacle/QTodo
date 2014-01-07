#include "proposappdialog.h"

proposAppDialog::proposAppDialog(QWidget *parent) :
    QDialog(parent)
{

    labelInfo = new QLabel();
    labelInfo->setText("Todo 1.0<br />&copy; David Remacle 2012");
    okButton = new QPushButton();
    iconLabel = new QLabel;

    layoutPrincipal = new QHBoxLayout;
    layoutPrincipal->addWidget(labelInfo);

    setLayout(layoutPrincipal);
}
