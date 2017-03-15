#include "fenprincipale.h"

FenPrincipale::FenPrincipale()
{
    this->_session= new SessionActuel();
    zoneCentrale = new QWidget;

   // Les 2 liste du mode simple séléction
    viewL = new QTableView();
    viewRH = new QTreeView();
    viewRB = new QTableView();

    // Le model qui sert d'explorateur de fichier
    modele = new QDirModel;
        viewRH->setModel(modele);

     // Initialisation des bouton
    modeTag= new QPushButton("Mode Gestion des Tags");
    mostUse= new QPushButton("Les plus utilisés");
    ordreLexico= new QPushButton("Ordre Lexicographique");
    ajouter= new QPushButton("Ajouter Tag(s)");
    associateFile = new QPushButton("Fichiers associé au tag");
    multiSelection= new QPushButton("Mode Multi Séléction");



    modeTag->setToolTip("Mode pour géré vos Tags");
    mostUse->setToolTip("Trie les tag(s) des plus ou moins utilisés");
    ordreLexico->setToolTip("Trie les tags par ordre lexicographique");
    ajouter->setToolTip("Ajoute Tag(s) séléctioné au fichier séléctioné");
    associateFile->setToolTip("Montre les fichiers associés au tag");
    multiSelection->setToolTip("Mode pour ajouter des Tags à plusieur fichier en même temps");


    //Initialisation des lineEdit
    creeTag = new QLineEdit();
    rechercheFile = new QLineEdit();

    creeTag->setPlaceholderText("Crée tag");
    rechercheFile->setPlaceholderText("Rechercher");

    creeTag->setToolTip("Appuyer sur entrer pour crée le tag");
    rechercheFile->setToolTip("Appuyer sur entrer pour valider");

    //QObject::connect(creeTag,SIGNAL(QLineEdit::returnPressed()),qApp,SLOT(this->_session->addTag()));


    // Creation des layout du mode simple séléction
    layout = new QGridLayout;
    layoutLeft= new QGridLayout;
    layoutRight= new QGridLayout;
    layoutCentral = new QGridLayout; // Bloc avec Ajouter Tag(s)
    layoutCentral2= new QGridLayout;// Bloc avec Mode multi Séléction



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


// -----Getter and Setter---------

SessionActuel *FenPrincipale::getSession(){
    return this->_session;
}

void FenPrincipale::setSession(SessionActuel *session){
    this->_session=session;
}
