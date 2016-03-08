#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(3);
    addchildren(ui->treeWidget);
    QTreeWidgetItem *treeChild = new QTreeWidgetItem();
    treeChild->setText(0,"c");treeChild->setText(1,"hi");treeChild->setText(2,"ld");
    ui->treeWidget->invisibleRootItem()->child(1)->addChild(treeChild);
    qDebug()<<ui->treeWidget->invisibleRootItem()->child(0)->text(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void addchildren(QTreeWidget *tree){
    for(int i=0; i<5; i++){
        QTreeWidgetItem *treeItem = new QTreeWidgetItem(tree);
        treeItem->setText(0,"a"+QString::number(i));
        treeItem->setText(1,"b"+QString::number(i));
        treeItem->setText(2,"c"+QString::number(i));
//        tree->addTopLevelItem(treeItem);
        qDebug()<<tree->indexOfTopLevelItem(treeItem)<<tree->invisibleRootItem();
    }
}
