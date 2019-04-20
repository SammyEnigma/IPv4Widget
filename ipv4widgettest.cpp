#include "ipv4widgettest.h"
#include "ui_ipv4widgettest.h"

IPv4WidgetTest::IPv4WidgetTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IPv4WidgetTest)
{
    ui->setupUi(this);
}

IPv4WidgetTest::~IPv4WidgetTest()
{
    delete ui;
}
