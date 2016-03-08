#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Quit_triggered()
{
    close();
}

void MainWindow::on_actionAdd_triggered()
{
    Web_test *view = new Web_test(QDateTime::currentDateTime().toString());
    view->setUrl(QUrl("http://google.com"));
    list.push_back(view);
    ui->tab->addTab(view,"Google");
}

void MainWindow::on_action_search_triggered()
{
    int c=0;
    Web_test* a;
    std::list<Web_test*>::iterator it = list.begin();
    while(it != list.end()){
        a = *it;
        a->setUrl("http://google.com/search?q="+QString::number(c));
        qDebug()<<a->read_str();
        c++;
        it++;
    }
}
