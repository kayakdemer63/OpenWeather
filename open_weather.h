/// @file open_weather.h
/// @author Louan DESHAYES
/// @version 1.1
/// @class open_weather

#ifndef OPEN_WEATHER_H
#define OPEN_WEATHER_H                  /// @def OPEN_WEATHER_H

#include <QNetworkReply>                /// @include <QNetworkReply
#include <QNetworkAccessManager>        /// @include <QNetworkAccessManager
#include <QNetworkRequest>              /// @include <QNetworkRequest
#include <QUrl>                         /// @include <QUrl
#include <QtGui>                        /// @include <QtGui
#include <QMessageBox>                  /// @include <QMessageBox
#include <QSslConfiguration>            /// @include <QSslConfiguration


class open_weather
{
public:
    open_weather();
    /** @public @fn open_weather()
     *  @brief Déclaration du Constructor.
     */

    void set_url(QString url);
    /** @public @fn void set_url(QString url)
     *  @brief Déclaration de la Méthode. Fonction permettant de définir l'url du site et la ville.
     *  @param[in] url L'url du site et la ville.
     */

    QJsonObject infos;
    /** @private @var QJsonObject infos
     *  @brief Déclaration de l'Attribut. Contient le fichier Json.
     */

    void get_infos();
    /** @public @fn void get_infos()
     *  @brief Déclaration de la Méthode. Fonction permettant de récupérer le fichier Json.
     *  @param[out] objetJson()
     */

    double get_temp();
    /** @public @fn double get_temp()
     *  @brief Déclaration de la Méthode. Fonction permettant de récupérer la température à partir du fichier Json.
     *  @param[out] jValue.toDouble()
     */

    double get_feels_like();
    /** @public @fn double get_feels_like()
     *  @brief Déclaration de la Méthode. Fonction permettant de récupérer la température ressentie à partir du fichier Json.
     *  @param[out] jValue.toDouble()
     */

    QString get_weather();
    /** @public @fn QString get_weather()
     *  @brief Déclaration de la Méthode. Fonction permettant de récupérer le temps qu'il fait à partir du fichier Json.
     *  @param[out] jValue.toString()
     */

    int get_humidity();
    /** @public @fn int get_humidity()
     *  @brief Déclaration de la Méthode. Fonction permettant de récupérer l'humidité à partir du fichier Json.
     *  @param[out] jValue.toInt()
     */

    double get_wind_speed();
    /** @public @fn double get_wind_speed()
     *  @brief Déclaration de la Méthode. Fonction permettant de récupérer la vitesse du vent à partir du fichier Json.
     *  @param[out] jValue.toDouble()
     */

    double get_wind_direction();
    /** @public @fn double get_wind_direction()
     *  @brief Déclaration de la Méthode. Fonction permettant de récupérer la direction du vent à partir du fichier Json.
     *  @param[out] jValue.toDouble()
     */

private:
    QUrl qurl;
    /** @private @var QUrl qurl
     *  @brief Déclaration de l'Attribut. Contient l'url du site et la ville.
     */

    QByteArray get(QUrl url);
    /** @private @fn QByteArray get(QUrl url)
     *  @brief Déclaration de la Méthode. Fonction permettant d'envoyer une requête à l'url du site et la ville.
     *  @param[in] url L'url du site et la ville
     */

    QNetworkAccessManager m;
    /** @private @fn QNetworkAccessManager m
     *  @brief Déclaration de l'Attibut.
     */

};

#endif // OPEN_WEATHER_H
