#ifndef WINCOMFORM_H
#define WINCOMFORM_H

#include <QWidget>
#include "qextserialport.h"
#include <QtDesigner/QDesignerExportWidget>
#include <QString>
namespace Ui {
    class WinComForm;
}

class WinComForm : public QWidget
{
    Q_OBJECT

public:
    explicit WinComForm(QWidget *parent = 0);
    explicit WinComForm(QString portName,PortSettings set,QWidget *parent = 0);
    ~WinComForm();
signals:
    void SetPortChange(QString name, PortSettings s);
private slots:
    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBoxStop_currentIndexChanged(int index);

    void on_comboBoxSpeed_currentIndexChanged(int index);

    void on_comboBoxData_currentIndexChanged(int index);

    void on_comboBoxParz_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::WinComForm *ui;
    PortSettings newSet;
    QString portName;

};

#endif // WINCOMFORM_H
