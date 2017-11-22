#include "attribute_tab.hpp"

#include <QJsonDocument>
#include <QFile>

AttributeTab::AttributeTab(QWidget * parent): QWidget(parent)
{
    QFile file("../src/editor/attributes.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QJsonDocument document;
    document.fromJson(file.readAll().toStdString());

    file.close();
}

AttributeTab::~AttributeTab()
{
}
