#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QWebView>

#include <list>
#include <iterator>
#include "web_test.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_Quit_triggered();

    void on_actionAdd_triggered();

    void on_action_search_triggered();

private:
    Ui::MainWindow *ui;
};

//extern std::list<Web_test*> list;

#endif // MAINWINDOW_H
