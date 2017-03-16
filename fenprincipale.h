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

#include "sessionActuel.h"

class FenPrincipale : public QMainWindow
{
     Q_OBJECT
private :
    SessionActuel* _session;

    //Widget général
    QWidget *zoneCentrale;

    //QStrinList
    QStringList listTag;

    //View
    QTableView* viewL;
    QTreeView* viewRH;
    QTableView* viewRB;

    //Model
    QDirModel *modele;
    QStandardItemModel *modeleTag;
    QStandardItemModel* modeleFileSelect;

    //PushButton
    QPushButton *modeTag;
    QPushButton *mostUse;
    QPushButton *ordreLexico;
    QPushButton *ajouter;
    QPushButton *associateFile;
    QPushButton *multiSelection;
    QPushButton *clearSelection; //Clear la liste de file séléctionnner

    //LineEdit
    QLineEdit* creeTag;
    QLineEdit* rechercheFile;

    //Layout
    QGridLayout *layout;
    QGridLayout *layoutLeft;
    QGridLayout *layoutRight;
    QGridLayout *layoutCentral; // Bloc avec Ajouter Tag(s)
    QGridLayout *layoutCentral2;// Bloc avec Mode multi Séléction

public slots:
     void addTag();
     void addFileToSelection(const QModelIndex &index);
     void lieTagFile(const QModelIndex &index);
     void clearSelectionSignal();
     void test();

public:
    FenPrincipale();

    SessionActuel* getSession();
    void setSession( SessionActuel *session);
};

#endif // FENPRINCIPALE_H
