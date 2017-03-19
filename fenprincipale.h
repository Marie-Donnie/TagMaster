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
    QPushButton *clearSelection; //Clear la liste de fichiers séléctionnnés

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
    QGridLayout *layoutCentral2;// Bloc avec Mode multi Sélection

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
         \brief Lie un tag à un fichier et vice-versa.
         \param index l'index Qt du tag à rajouter
     */
     void lieTagFile(const QModelIndex &index);
     /*! \fn void clearSelectionSignal()
         \brief Quand un signal est reçu, retire la sélection des fichiers et raffraîchit l'affichage.
     */
     void clearSelectionSignal();
     /*! \fn void menuFileSelectionRequested(const QPoint &pos)
         \brief Procède à l'ouverture du menu contextuel.
         \param pos la position QPoint du curseur
     */
     void menuFileSelectionRequested(const QPoint &pos);
     /*! \fn void setIndex(const QModelIndex &indexPos)
         \brief Règle l'index à l'index donné.
         \param index l'index QModel
     */
     void setIndex(const QModelIndex &indexPos);
     /*! \fn void switchMode()
         \brief Permet de passer d'un mode à l'autre.
         Permet de passer du mode gestion de fichiers au mode gestion de tags.
     */
     void switchMode();// Change d'un mode à l'autre
     // Remplie fileCurrent2 avec les file du tag double clické et met à jours l'affichage
     /*! \fn void fileDuTag(const QModelIndex &index)
         \brief Affiche les fichiers liés au tag à l'index donné.
         \param index l'index QtModel du tag cliquer
     */
     void fileDuTag(const QModelIndex &index);
     /*! \fn void selectionTag(const QModelIndex &index)
         \brief Rajoute un tag aux tags actuellement sélectionnés.
         \param index l'index QtModel du tag cliqué

        Permet de rajouter plusieurs tags avec ctrl+clic.
     */
     void selectionTag(const QModelIndex &index);
     /*! \fn void slotRenommer()
         \brief S'occupe du renommage d'un tag une fois le signal reçu.
         \warning Ne fonctionne que si plusieurs tags sont sélectionnés.
     */
     void slotRenommer();
     /*! \fn void slotFusionner()
         \brief S'occupe de la fusion de plusieurs tags.
         \warning Ne fonctionne que si plusieurs tags sont sélectionnés et retire les tags de la sélection de tags.
     */
     void slotFusionner();
     /*! \fn void slotSupprimer()
         \brief S'occupe de la supression de plusieurs tags.
         \warning Ne fonctionne que si un ou plusieurs tags sont sélectionnés et retire les tags de la sélection de tags.
     */
     void slotSupprimer();
     /*! \fn void slotFichierDesTags()
         \brief Affiche les fichiers ayant tous les tags se trouvant actuellement dans tag current.
         \warning Ne marche que si un ou plusieurs tags sont sélectionnés et retire les tags de la sélection de tags.
     */
     void slotFichierDesTags();
     /*! \fn void slotTrieCount()
         \brief Trie les tags par le nombre de fichier auxquels ils sont attribués.
     */
     void slotTrieCount();
     /*! \fn void slotTrieLexico()
         \brief Trie les tags par ordre alphabétique.
         \warning L'ordre alphabétique est ici surtout l'ordre ascii des caractères.
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
        \brief Raffraichit la sélection des fichiers du mode gestion de fichier.
    */
    void refreshFileSelect();
    /*! \fn void refreshModeleTag()
        \brief Raffraichit la liste de tags du mode gestion de fichiers.
    */
    void refreshModeleTag();
    /*! \fn void refreshModeleTag_1()
        \brief Raffraichit la liste de tags du mode gestion de tags.
    */
    void refreshModeleTag_1();
    /*! \fn void refreshFileSelect_1()
        \brief Raffraichit la liste des fichiers du mode tags.
    */
    void refreshFileSelect_1();

};

#endif // FENPRINCIPALE_H
