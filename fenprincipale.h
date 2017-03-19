#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H
#include<QObject>
#include <QWidget>
#include <QApplication>
#include <QLayout>
#include <QTreeView>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QDirModel>
#include <QTableView>
#include <QLineEdit>
#include <QStackedWidget>
#include <QStackedLayout>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QAction>
#include <QMenu>
#include <QMouseEvent>
#include <QContextMenuEvent>
#include <QMessageBox>
#include <QInputDialog>

#include "sessionActuel.h"

/*! \class FenPrincipale
    \brief La classe pour la fenêtre principale

    Hérite de QMainWindow. Les attributs avec _1 concernent la fenêtre de gestion de tags (1 étant l'index du widget dans le stacked layout)
*/

class FenPrincipale : public QMainWindow
{
     Q_OBJECT
private :
    SessionActuel* _session;
    QModelIndex _index;// Garde en mémoire où on clique dans les tables pour certaines opérations


    //Widget général
    QWidget *zoneCentrale;
    QWidget *zoneCentraleFileMode;
    QWidget *zoneCentraleTagMode_1;

    //QStrinList
    //QStringList listTag;

    //View
    QTableView* viewL;
    QTreeView* viewRH;
    QTableView* viewRB;

    QTableView *viewL_1;
    QTableView *viewR_1;

    //Model
    QDirModel *modele;
    QStandardItemModel *modeleTag;
    QStandardItemModel* modeleFileSelect;

    QStandardItemModel * modeleTag_1;
    QStandardItemModel *modeleFileSelect_1;

    //PushButton
    QPushButton *modeTag;
    QPushButton *mostUse;
    QPushButton *ordreLexico;
    QPushButton *ajouter;
    QPushButton *associateFile;
    QPushButton *multiSelection;
    QPushButton *clearSelection; //Clear la liste de file séléctionnner

    QPushButton* modeGestionFichier_1;
    QPushButton* renommer_1;
    QPushButton* fusionner_1;
    QPushButton* supprimer_1;
    QPushButton* fichierAssocie_1;
    QPushButton* mostUse_1;
    QPushButton* ordreLexico_1;

    //LineEdit
    QLineEdit* creeTag;
    QLineEdit* rechercheFile;

    QLineEdit* creeTag_1;

    //Layout
    QStackedLayout *mainLayout;

    QGridLayout *layout;
    QGridLayout *layoutLeft;
    QGridLayout *layoutRight;
    QGridLayout *layoutCentral; // Bloc avec Ajouter Tag(s)
    QGridLayout *layoutCentral2;// Bloc avec Mode multi Séléction

    QGridLayout *layout_1;
    QGridLayout *layoutLeft_1;
    QGridLayout *layoutRight_1;
    QGridLayout *layoutCentral_1;



public slots:
    /*! \fn void addTag()
        \brief Ajoute un tag à la fenêtre FenPrincipale.
    */
     void addTag();

     /*! \fn void addFileToSelection(const QModelIndex &index)
    \brief Ajoute à la liste des fichiers sélectionnés le fichier à l'index index.
    \param index l'index Qt du file à rajouter
    */
     void addFileToSelection(const QModelIndex &index);
     /*! \fn void lieTagFile(const QModeIndex &index)
         \brief Rajoute et
         \param index l'index Qt du tag à rajouter
     */
     void lieTagFile(const QModelIndex &index);
     /*! \fn void clearSelectionSignal()
         \brief Quand signal reçu clear les files current et refresh l'affichage
     */
     void clearSelectionSignal();
     /*! \fn void menuFileSelectionRequested(const QPoint &pos)
         \brief prossède à l'ouverture du menue contextuel
         \param pos la position QPoint du curseur
     */
     void menuFileSelectionRequested(const QPoint &pos);
     /*! \fn void setIndex(const QModelIndex &indexPos)
         \brief Règle l'index à l'index donné
         \param index l'index QModel
     */
     void setIndex(const QModelIndex &indexPos);
     /*! \fn void switchMode()
         \brief Permet de passer d'un mode à l'autre
     */
     void switchMode();// Change d'un mode à l'autre
     // Remplie fileCurrent2 avec les file du tag double clické et met à jours l'affichage
     /*! \fn void fileDuTag(const QModelIndex &index)
         \brief Affiche les fichiers liés au tag à l'index donné
         \param index l'index QtModel du tag cliquer
     */
     void fileDuTag(const QModelIndex &index);
     /*! \fn void selectionTag(const QModelIndex &index)
         \brief Rajoute un tag aux tag actuellement séléctionner.
         Permet dans rajouter plusieur avec ctr+click
         \param index l'index QtModel du tag cliquer
     */
     void selectionTag(const QModelIndex &index);
     /*! \fn void slotRenommer()
         \brief S'occuppe du renommage d'un tag une fois le signal reçu
         \warning ne marche qui si 1 tag est séléctionner
     */
     void slotRenommer();
     /*! \fn void slotFusionner()
         \brief S'occuppe de la fusion de plusieur tag
         \warning ne marche qui si plus d'un tag est séléctionner et clear tag current
     */
     void slotFusionner();
     /*! \fn void slotSupprimer()
         \brief S'occuppe de la supression de plusieur tag
         \warning ne marche qui si 1 ou plusieur tag sont séléctionner et clear tag current
     */
     void slotSupprimer();
     /*! \fn void slotFichierDesTags()
         \brief Affiche les fichiers ayant tout les tags ce trouvant actuellement dans tag current
         \warning ne marche qui si 1 ou plusieur tag sont séléctionner et clear tag current
     */
     void slotFichierDesTags();
     /*! \fn void slotTrieCount()
         \brief Trie les tag par le nombre de fichier
     */
     void slotTrieCount();
     /*! \fn void slotTrieLexico()
         \brief Trie les tag par ordre alphabétique
     */
     void slotTrieLexico();



public:
    FenPrincipale();

    /*! \fn SessionActuel* getSession()
        \brief Accesseur de l'attribut session de FenPrincipale.
        \return La session actuelle de FenPrincipale
    */
    SessionActuel* getSession();
    /*! \fn void setSession(SessionActuel *session)
        \brief Règle la session de FenPrincipale.
        \param session le pointeur vers la session qu'on veut donner à FenPrincipale
    */
    void setSession( SessionActuel *session);
    /*! \fn void refreshFileSelect()
        \brief Raffraichit la sélection des fichiers du mode gestion de fichier
    */
    void refreshFileSelect();
    /*! \fn void refreshModeleTag()
        \brief refresh la liste de tag du mode gestion de fichier
    */
    void refreshModeleTag();
    /*! \fn void refreshModeleTag_1()
        \brief refresh la liste de tag du mode gestion de Tag
    */
    void refreshModeleTag_1();
    /*! \fn void refreshFileSelect_1()
        \brief refresh la liste des fichier du mode tag
    */
    void refreshFileSelect_1();

};

#endif // FENPRINCIPALE_H
