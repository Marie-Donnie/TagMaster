#include "fenprincipale.h"

FenPrincipale::FenPrincipale()
{
    QWidget *zoneCentrale = new QWidget;

   // Les 2 liste du mode simple séléction
    QTableView* viewL = new QTableView();
    QTreeView* viewRH = new QTreeView();
    QTableView* viewRB = new QTableView();

    // Le model qui sert d'explorateur de fichier
    QDirModel *modele = new QDirModel;
        viewRH->setModel(modele);

     // Initialisation des bouton
    QPushButton *modeTag= new QPushButton("Mode Gestion des Tags");
    QPushButton *mostUse= new QPushButton("Les plus utilisés");
    QPushButton *ordreLexico= new QPushButton("Ordre Lexicographique");
    QPushButton *ajouter= new QPushButton("Ajouter Tag(s)");
    QPushButton *associateFile = new QPushButton("Fichiers associé au tag");
    QPushButton *multiSelection= new QPushButton("Mode Multi Séléction");

    modeTag->setToolTip("Mode pour géré vos Tags");
    mostUse->setToolTip("Trie les tag(s) des plus ou moins utilisés");
    ordreLexico->setToolTip("Trie les tags par ordre l'exicographique");
    ajouter->setToolTip("Ajoute Tag(s) séléctioné au fichier séléctioné");
    associateFile->setToolTip("Montre les fichiers associés au tag");
    multiSelection->setToolTip("Mode pour ajouter des Tags à plusieur fichier en même temps");


    //Initialisation des lineEdit
    QLineEdit* creeTag = new QLineEdit();
    QLineEdit* rechercheFile = new QLineEdit();

    creeTag->setPlaceholderText("Crée tag");
    rechercheFile->setPlaceholderText("Rechercher");

    creeTag->setToolTip("Appuyer sur entrer pour crée le tag");
    rechercheFile->setToolTip("Appuyer sur entrer pour valider");

    // Creation des layout du mode simple séléction
    QGridLayout *layout = new QGridLayout;
    QGridLayout *layoutLeft= new QGridLayout;
    QGridLayout *layoutRight= new QGridLayout;
    QGridLayout *layoutCentral = new QGridLayout; // Bloc avec Ajouter Tag(s)
    QGridLayout *layoutCentral2= new QGridLayout;// Bloc avec Mode multi Séléction



    // Remplissage du layout left
    layoutLeft->addWidget(viewL,0,0);

    // Remplissage du layout right
    layoutRight->addWidget(viewRH,0,0,1,1);
    layoutRight->addWidget(viewRB,1,0,2,1);


    // Remplissage du layout centrale
    layoutCentral->addWidget(mostUse,0,0);
    layoutCentral->addWidget(ordreLexico,1,0);
    layoutCentral->addWidget(ajouter,2,0);
    layoutCentral->addWidget(associateFile,3,0,2,1);

    // Remplissage du layout centrale 2
    layoutCentral2->addWidget(multiSelection,0,0);

    // Remplissage du layout principale
    layout->addWidget(creeTag,0,0);
    layout-> addWidget(modeTag,0,1);
    layout->addWidget(rechercheFile,0,2);
    layout->addLayout(layoutLeft,1,0,3,1);
    layout->addLayout(layoutCentral,1,1);
    layout->addLayout(layoutCentral2,3,1);
    layout->addLayout(layoutRight,1,2,3,1);



    //Définition du layout comme zone central
    zoneCentrale->setLayout(layout);

    //Zone central devient la zone central du widget
    setCentralWidget(zoneCentrale);
}
