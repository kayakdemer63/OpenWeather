/// @file mainwindow.h
/// @author Louan DESHAYES
/// @version 1.1
/// @class mainwindow

#ifndef MAINWINDOW_H
#define MAINWINDOW_H                        /// @def MAINWINDOW_H

#include <QMainWindow>                      /// @include <QMainWindow
#include <QNetworkReply>                    /// @include <QNetworkReply
#include <QNetworkAccessManager>            /// @include <QNetworkAccessManager
#include <QNetworkRequest>                  /// @include <QNetworkRequest
#include <QUrl>                             /// @include <QUrl
#include <QtGui>                            /// @include <QtGui
#include <QMessageBox>                      /// @include <QMessageBox
#include "open_weather.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }          /// @namespace Ui
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    /** @public @fn MainWindow(QWidget *parent = nullptr)
     *  @brief Déclaration du Constructor.
     *  @param[in] parent
     */

    ~MainWindow();
    /** @public @fn ~MainWindow()
     *  @brief Déclaration du Destructor.
     */

    open_weather weather;
    /** @private @var open_weather weather
     *  @brief Déclaration de l'objet weather de type open_weather.
     */

    void message(double i);
    /** @private @fn message(int i)
     *  @brief Déclaration de la Méthode. Fonction qui écrit un message en fonction de la température.
     *  @param[in] i Indice de température.
     */

private:
    Ui::MainWindow *ui;
    /** @private @var Ui::MainWindow *ui
     *  @brief Déclaration de la fenêtre avec les widgets.
     */

private slots:
    void url_change();
    /** @private @fn url_change()
     *  @brief Récupération du nouvel url lorsqu'il change.
     */

    void search();
    /** @private @fn search()
     *  @brief Charge le fichier Json actuel.
     */

    void new_ville();
    /** @private @fn new_ville()
     *  @brief Change l'url pour celui de la ville saisie.
     */

    void CB_change();
    /** @private @fn CB_change()
     *  @brief Change l'url pour celui de la ville sélectionnée.
     */

};
#endif // MAINWINDOW_H
