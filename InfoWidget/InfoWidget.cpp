#include "InfoWidget.hpp"
#include "ui_InfoWidget.h"
#include <sstream>
#include "common/Common.hpp"

InfoWidget::InfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoWidget)
{
    ui->setupUi(this);

    dp = new DescriptionPanel();
    ui->verticalLayout->addWidget(dp);

    mp = new MetaDataPanel();
    ui->verticalLayout->addWidget(mp);

    tp = new TagPanel();
    ui->verticalLayout->addWidget(tp);

    connect_widgets();
}

//void InfoWidget::update_info_widget(std::string id, std::string type, std::string name, boost::optional<std::basic_string<char>> description, nix::Section meta_section)
//{
//    dp->update_description_panel(id,type,name,description);
//    mp->update_metadata_panel(meta_section);
//}

//void InfoWidget::update_info_widget(std::string id, std::string name, boost::optional<std::basic_string<char>> description, nix::Section meta_section)
//{

//    dp->update_description_panel(id,name,description);
//    mp->update_metadata_panel(meta_section);
//}

void InfoWidget::update_info_widget(QVariant v)
{
    std::cout << "works " << v.canConvert<nix::Block>() << std::endl;

    dp->update_description_panel(v);

//    if(typeid(v) == typeid(nix::Block))
//    {
//        std::cout << "block" << std::endl;
//    }
}

void InfoWidget::connect_widgets()
{
    QObject::connect(mp->get_tree_widget(), SIGNAL(expanded(QModelIndex)), mp, SLOT(resize_to_content(QModelIndex)));
    QObject::connect(mp->get_tree_widget(), SIGNAL(collapsed(QModelIndex)), mp, SLOT(resize_to_content(QModelIndex)));
}

// getter

const MetaDataPanel* InfoWidget::get_metadata_panel()
{
    return mp;
}

InfoWidget::~InfoWidget()
{
    delete ui;
}

