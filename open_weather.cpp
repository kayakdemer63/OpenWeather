/// @file open_weather.cpp
/// @author Louan DESHAYES
/// @version 1.1
/// @class open_weather

#include "open_weather.h"

open_weather::open_weather()
{
    qurl = "https://api.openweathermap.org/data/2.5/weather?q=clermont-ferrand&appid=9d76eced21e3494fa9c87561eed2c0aa&units=metric&lang=fr";
}

void open_weather::set_url(QString url)
{
    qurl = QUrl(url);
    qDebug() << qurl;
}

QByteArray open_weather::get(QUrl url)
{
    QNetworkRequest requete(url);

    QSslConfiguration config= QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_2);
    requete.setSslConfiguration(config);

    QNetworkReply *reply = m.get(requete);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray read = reply->readAll();
    reply->close();
    reply->deleteLater();
    return read;
}

void open_weather::get_infos()
{
    QUrl url = qurl;

    QJsonDocument docJSON = QJsonDocument::fromJson(get(url));

    qDebug() << docJSON;

    QJsonObject objetJSON = docJSON.object();
    qDebug() << objetJSON;
    this->infos = objetJSON;
}

double open_weather::get_temp()
{
    QJsonObject info = this->infos;
    QJsonObject jData = info.value("main").toObject();
    qDebug() << jData;
    QJsonValue jValue = jData.value("temp");
    qDebug() << jValue;
    return jValue.toDouble();
}

double open_weather::get_feels_like()
{
    QJsonObject info = this->infos;
    QJsonObject jData = info.value("main").toObject();
    qDebug() << jData;
    QJsonValue jValue = jData.value("feels_like");
    qDebug() << jValue;
    return jValue.toDouble();
}

QString open_weather::get_weather()
{
    QJsonObject info = this->infos;
    QJsonArray jData = info.value("weather").toArray();
    qDebug() << jData;

    //QJsonValue jValue = jData.value("description");
    //qDebug() << jValue;
    //return jValue.toString();
}

int open_weather::get_humidity()
{
    QJsonObject info = this->infos;
    QJsonObject jData = info.value("main").toObject();
    qDebug() << jData;
    QJsonValue jValue = jData.value("humidity");
    qDebug() << jValue;
    return jValue.toInt();
}

double open_weather::get_wind_speed()
{
    QJsonObject info = this->infos;
    QJsonObject jData = info.value("wind").toObject();
    qDebug() << jData;
    QJsonValue jValue = jData.value("speed");
    qDebug() << jValue;
    return jValue.toDouble();
}

double open_weather::get_wind_direction()
{
    QJsonObject info = this->infos;
    QJsonObject jData = info.value("wind").toObject();
    qDebug() << jData;
    QJsonValue jValue = jData.value("deg");
    qDebug() << jValue;
    return jValue.toDouble();
}
