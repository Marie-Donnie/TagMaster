#include "fenprincipale.h"

FenPrincipale::FenPrincipale()
{
    this->_session= new SessionActuel();
    zoneCentrale = new QWidget;

   // Les 2 liste du mode simple séléction
    viewL = new QTableView();
    viewRH = new QTreeView();
    viewRB = new QTableView();

    viewL->setEditTriggers(QAbstractItemView::NoEditTriggers);
    viewRH->setEditTriggers(QAbstractItemView::NoEditTriggers);
    viewRB->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(viewL, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(lieTagFile(QModelIndex)));
    connect(viewRH, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(addFileToSelection(QModelIndex)));

    // Le model qui sert d'explorateur de fichier
    modele = new QDirModel;
    modeleTag = new QStandardItemModel();
    modeleFileSelect = new QStandardItemModel();

    modeleTag->setHorizontalHeaderItem(0, new QStandardItem("Nom") );
    modeleTag->setHorizontalHeaderItem(1, new QStandardItem("Nombre fichier") );


    modeleFileSelect->setHorizontalHeaderItem(0, new QStandardItem("Fichier"));
    modeleFileSelect->setHorizontalHeaderItem(1,new QStandardItem("Tags"));

    viewRH->setModel(modele);
    viewRB->setModel(modeleFileSelect);
    viewL->setModel(modeleTag);

     // Initialisation des bouton
    modeTag= new QPushButton("Mode Gestion des Tags");
    mostUse= new QPushButton("Les plus utilisés");
    ordreLexico= new QPushButton("Ordre Lexicographique");
    associateFile = new QPushButton("Fichiers associé au tag");
    multiSelection= new QPushButton("Mode Multi Séléction");
    clearSelection = new QPushButton("Clear Séléction ->");

    QObject::connect(modeTag,SIGNAL(clicked()),this,SLOT(test()));
    QObject::connect(clearSelection,SIGNAL(clicked()),this,SLOT(clearSelectionSignal()));



    modeTag->setToolTip("Mode pour géré vos Tags");
    mostUse->setToolTip("Trie les tag(s) des plus ou moins utilisés");
    ordreLexico->setToolTip("Trie les tags par ordre lexicographique");
    associateFile->setToolTip("Montre les fichiers associés au tag");
    multiSelection->setToolTip("Mode pour ajouter des Tags à plusieur fichier en même temps");
    clearSelection->setToolTip("Clear la fenêtre des files actuellement séléctionnés");


    //Initialisation des lineEdit
    creeTag = new QLineEdit();
    rechercheFile = new QLineEdit();

    creeTag->setPlaceholderText("Crée tag");
    rechercheFile->setPlaceholderText("Rechercher");

    creeTag->setToolTip("Appuyer sur entrer pour crée le tag");
    rechercheFile->setToolTip("Appuyer sur entrer pour valider");

    QObject::connect(creeTag,SIGNAL(returnPressed()),this,SLOT(addTag()));


    // Creation des layout du mode simple séléction
    layout = new QGridLayout;
    layoutLeft= new QGridLayout;
    layoutRight= new QGridLayout;
    layoutCentral = new QGridLayout; // Bloc avec Millieu Haut
    layoutCentral2= new QGridLayout;// Bloc avec Mode multi Séléction



    // Remplissage du layout left
    layoutLeft->addWidget(viewL,0,0);

    // Remplissage du layout right
    layoutRight->addWidget(viewRH,0,0,1,1);
    layoutRight->addWidget(viewRB,1,0,2,1);


    // Remplissage du layout centrale
    layoutCentral->addWidget(mostUse,0,0);
    layoutCentral->addWidget(ordreLexico,1,0);
    layoutCentral->addWidget(associateFile,3,0,2,1);

    // Remplissage du layout centrale 2
    layoutCentral2->addWidget(clearSelection,0,0);
    layoutCentral2->addWidget(multiSelection,1,0);


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

//------Slots fonctions------

void FenPrincipale::addTag(){

    std::string tagName = creeTag->text().toStdString();
    if(this->_session->addTag(tagName)){
        Tag* tag = this->_session->getTagByName(tagName);
        QStandardItem* itemName= new QStandardItem(QString::fromStdString(tag->getTagName()));
        QStandardItem* itemCount= new QStandardItem(QString::number(tag->getCount()));
        QList<QStandardItem*> list = QList<QStandardItem*>();
        list.push_back(itemName);
        list.push_back(itemCount);
        modeleTag->appendRow(list);

    }
    creeTag->clear();
}

//TODO : Pas Fini
void FenPrincipale::lieTagFile(const QModelIndex &index){
    int col = index.column();
    int row = index.row();

    if (index.isValid()) {
        if(_session->getFilesCurrent().size()>0){

            QString cellText = index.data().toString();
            std::string string = cellText.toStdString();
            Tag* tag = _session->getTagByName(string);
            tag->incrementCount(1);
            QStandardItem* itemCount= new QStandardItem(QString::number(tag->getCount()));
            modeleTag->setItem(row,col+1,itemCount);
        }
    }

}

void FenPrincipale::addFileToSelection(const QModelIndex &index){
    if (index.isValid()) {
        QIcon qIcon=modele->fileIcon(index);
        QString qFileName= modele->fileName(index);
        QString qFilePath = modele->filePath(index);

        std::string fileName= qFileName.toStdString();
        std::string filePath = qFilePath.toStdString();

        _session->addFileToCurrent(fileName,filePath);
        std::cout<<"nb Séléctionné "<<_session->getFilesCurrent().size()<<std::endl;

        File* file =_session->getFileByPath(filePath);

        std::string tagsList = file->tagsToString();
        QString qTagsList = QString::fromStdString(tagsList);

        QStandardItem* itemIcon = new QStandardItem(qIcon,qFileName);
        QStandardItem* itemFileName = new QStandardItem(qFileName);
        QStandardItem* itemTagList = new QStandardItem(qTagsList);
        QList<QStandardItem*> list = QList<QStandardItem*>();
        list.push_back(itemIcon);
        list.push_back(itemTagList);

        modeleFileSelect->appendRow(list);
    }
}

void FenPrincipale::clearSelectionSignal(){
    modeleFileSelect->clear();
    _session->clearFilesCurrent();

    modeleFileSelect->setHorizontalHeaderItem(0, new QStandardItem("Fichier"));
    modeleFileSelect->setHorizontalHeaderItem(1,new QStandardItem("Tags"));
}

void FenPrincipale::test(){
    this->rechercheFile->setText("sd");

}
