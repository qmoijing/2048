/*#include "start.h"
#include "ui_start.h"
start::start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(StartClick()));
    Gamewindow=NULL;
    resDialog=new result;
}
start::~start()
{
    delete ui;
}
void start::StartClick()
{
    Gamewindow=new game(this,resDialog);
    connect(resDialog,SIGNAL(reset()),this,SLOT(resetGame()));
    Gamewindow->show();
}
void start::resetGame()
{
    resDialog->hide();
    if(Gamewindow!=NULL)
    {
        delete Gamewindow;
    }
    Gamewindow=new game(this,resDialog);
    Gamewindow->show();
}*/
