#ifndef WEB_TEST_H
#define WEB_TEST_H

#include <QWidget>
#include "mainwindow.h"

class Web_test : public QWebView
{
public:
    Web_test(QString);
    QString read_str();

private:
    QString str;
};
extern std::list<Web_test*> list;
#endif // WEB_TEST_H
