#include "web_test.h"

Web_test::Web_test(QString strings)
{
    str=strings;
}

QString Web_test::read_str(){
    return str;
}
