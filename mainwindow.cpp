/// @file mainwindow.cpp
/// @author Louan DESHAYES
/// @version 1.1
/// @class mainwindow

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::url_change()
{
    weather.set_url(ui->url->toPlainText());
    search();
}

void MainWindow::message(double i)
{
    if (i <=0)
    {
        ui->message->setText("Attention, il fait très froid.");
    }
    else if (i > 0 && i <=10)
    {
        ui->message->setText("Attention, il fait froid.");
    }
    else if (i > 10 && i <=18)
    {
        ui->message->setText("Il fait frais.");
    }
    else if (i > 18 && i <=25)
    {
        ui->message->setText("Il fait bon.");
    }
    else if (i > 25 && i <=32)
    {
        ui->message->setText("Il fait chaud.");
    }
    else if (i > 32)
    {
        ui->message->setText("Attention, il fait très chaud.");
    }
}

void MainWindow::search()
{
    weather.get_infos();
    double temperature = weather.get_temp();
    double ressentie = weather.get_feels_like();
    QString temps = weather.get_weather();
    double humidite = weather.get_humidity();
    double vitesse_vent = weather.get_wind_speed();
    double direction_vent = weather.get_wind_direction();
    QString direction_vent_cardinale;
    if ((direction_vent >= 0 && direction_vent <= 45) || (direction_vent > 315 && direction_vent <= 360))
    {
        direction_vent_cardinale = "Nord";
    }
    else if (direction_vent > 45 && direction_vent <= 135)
    {
        direction_vent_cardinale = "Est";
    }
    else if (direction_vent > 136 && direction_vent <= 225)
    {
        direction_vent_cardinale = "Sud";
    }
    else if (direction_vent > 226 && direction_vent <= 315)
    {
        direction_vent_cardinale = "Ouest";
    }
    ui->temperature->display(temperature);
    message(temperature);
    ui->ressenti->setValue(ressentie);
    ui->temps->setPlainText(temps);
    ui->humidite->setValue(humidite);
    ui->vitesse_vent->setValue(vitesse_vent);
    ui->direction_vent->setPlainText(direction_vent_cardinale);
}

void MainWindow::new_ville()
{
    QString ville = ui->newVille->toPlainText();
    QString url = "https://api.openweathermap.org/data/2.5/weather?q=" + ville + "&appid=9d76eced21e3494fa9c87561eed2c0aa&units=metric&lang=fr";
    qDebug() << url;
    weather.set_url(url);
    search();
}

void MainWindow::CB_change()
{
    QString ville = ui->Ville_CB->currentText();
    QString url = "https://api.openweathermap.org/data/2.5/weather?q=" + ville + "&appid=9d76eced21e3494fa9c87561eed2c0aa&units=metric&lang=fr";
    qDebug() << url;
    weather.set_url(url);
    search();
}
