#ifndef PROPOSAPPDIALOG_H
#define PROPOSAPPDIALOG_H

#include <QDialog>
#include <QtWidgets>

class proposAppDialog : public QDialog
{
    Q_OBJECT
public:
    explicit proposAppDialog(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *labelInfo;
    QPushButton *okButton;
    QLabel *iconLabel;
    QHBoxLayout *layoutPrincipal;

};

#endif // PROPOSAPPDIALOG_H
