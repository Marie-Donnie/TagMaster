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
     void addTag();
     void addFileToSelection(const QModelIndex &index);
     void lieTagFile(const QModelIndex &index);
     void clearSelectionSignal();
     void test();
     void menuFileSelectionRequested(const QPoint &pos);
     void setIndex(const QModelIndex &indexPos);
     void switchMode();// Change d'un mode à l'autre
     // Remplie fileCurrent2 avec les file du tag double clické et met à jours l'affichage
     void fileDuTag(const QModelIndex &index);
     void selectionTag(const QModelIndex &index);
     //void signalRenommer();



public:
    FenPrincipale();

    SessionActuel* getSession();
    void setSession( SessionActuel *session);
    void refreshFileSelect();
    void refreshModeleTag();
    void refreshModeleTag_1();
    void refreshFileSelect_1();

};

#endif // FENPRINCIPALE_H
