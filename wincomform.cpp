#include "wincomform.h"
#include "ui_wincomform.h"

WinComForm::WinComForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WinComForm)
{
    ui->setupUi(this);

}
WinComForm::WinComForm(QString portName, PortSettings set, QWidget *parent):
    QWidget(parent),
    ui(new Ui::WinComForm)
{
 newSet=set;
 this->portName=portName;
    ui->setupUi(this);

}

WinComForm::~WinComForm()
{
    delete ui;
}
void WinComForm::on_comboBox_2_currentIndexChanged(int index)
{
portName=ui->comboBox_2->itemText(index);
}

void WinComForm::on_comboBoxStop_currentIndexChanged(int index)
{
    switch(index){

    case 0:
        newSet.StopBits=STOP_1;
        break;
    case 1:
        newSet.StopBits=STOP_1_5;
        break;
    case 2:
        newSet.StopBits=STOP_2;
        break;
    default:
        newSet.StopBits=STOP_1;
    }
}

void WinComForm::on_comboBoxSpeed_currentIndexChanged(int index)
{
    switch(index){

    case 0:
         newSet.BaudRate=BAUD9600;
        break;
    case 1:
         newSet.BaudRate=BAUD1200;
        break;
    case 2:
         newSet.BaudRate=BAUD2400;
        break;
    case 3:
         newSet.BaudRate=BAUD14400;
        break;
    case 4:
         newSet.BaudRate=BAUD19200;
        break;
    default:
           newSet.BaudRate=BAUD9600;
    }
}

void WinComForm::on_comboBoxData_currentIndexChanged(int index)
{
    switch(index){

    case 0:
         newSet.DataBits=DATA_8;
        break;
    case 1:
          newSet.DataBits=DATA_5;
        break;
    case 2:
          newSet.DataBits=DATA_6;
        break;
    case 3:
          newSet.DataBits=DATA_7;
        break;
    default:
            newSet.DataBits=DATA_8;
    }
}

void WinComForm::on_comboBoxParz_currentIndexChanged(int index)
{
    switch(index){
    case 0:
         newSet.Parity=PAR_NONE;
        break;
    case 1:
         newSet.Parity=PAR_ODD;
        break;
    case 2:
         newSet.Parity=PAR_EVEN;
        break;
    case 3:
         newSet.Parity=PAR_MARK;
        break;
    case 4:
         newSet.Parity=PAR_SPACE;
        break;
    default:
           newSet.Parity=PAR_NONE;
    }

}

void WinComForm::on_pushButton_clicked()
{
   emit SetPortChange(portName,newSet);
   close();
}
