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

    viewRB->setContextMenuPolicy(Qt::CustomContextMenu);


    connect(viewL, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(lieTagFile(QModelIndex)));
    connect(viewRH, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(addFileToSelection(QModelIndex)));
    connect(viewRB, SIGNAL(pressed(const QModelIndex &)),this, SLOT(setIndex(const QModelIndex &)));
    connect(viewRB, SIGNAL(customContextMenuRequested(const QPoint&)),this, SLOT(menuFileSelectionRequested(QPoint)));

    // Le model qui sert d'explorateur de fichier
    modele = new QDirModel;
    modeleTag = new QStandardItemModel();
    modeleFileSelect = new QStandardItemModel();

    modeleTag->setHorizontalHeaderItem(0, new QStandardItem("Nom") );
    modeleTag->setHorizontalHeaderItem(1, new QStandardItem("Nombre fichier") );


    modeleFileSelect->setHorizontalHeaderItem(0, new QStandardItem("Fichier"));
    modeleFileSelect->setHorizontalHeaderItem(1, new QStandardItem("Path"));
    modeleFileSelect->setHorizontalHeaderItem(2,new QStandardItem("Tags"));



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


void FenPrincipale::lieTagFile(const QModelIndex &index){
    int col = index.column();
    int row = index.row();

    if (index.isValid()) {
        if((_session->getFilesCurrent().size()>0)&&(col==0)){

            QString cellText = index.data().toString();
            std::string string = cellText.toStdString();
            Tag* tag = _session->getTagByName(string);
            _session->addTagToCurrent(string);
            _session->lieTagFile();
            QStandardItem* itemCount= new QStandardItem(QString::number(tag->getCount()));
            modeleTag->setItem(row,col+1,itemCount);
            _session->lieTagFile();
            refreshFileSelect();
        }
    }
    std::cout<<" size "<<_session->getFilesCurrent().size()<<std::endl;

}

void FenPrincipale::addFileToSelection(const QModelIndex &index){
    if (index.isValid()) {
        QIcon qIcon=modele->fileIcon(index);
        QString qFileName= modele->fileName(index);
        QString qFilePath = modele->filePath(index);

        std::string fileName= qFileName.toStdString();
        std::string filePath = qFilePath.toStdString();

        if(_session->addFileToCurrent(fileName,filePath)){
            File* file =_session->getFileByPath(filePath);
            std::string tagsList = file->tagsToString();
            QString qTagsList = QString::fromStdString(tagsList);

            //QStandardItem* itemIcon = new QStandardItem(qIcon,qFileName);
            QStandardItem* itemIcon = new QStandardItem(qFileName);
            QStandardItem* itemPath = new QStandardItem(qFilePath);
            QStandardItem* itemTagList = new QStandardItem(qTagsList);
            QList<QStandardItem*> list = QList<QStandardItem*>();
            list.push_back(itemIcon);
            list.push_back(itemPath);
            list.push_back(itemTagList);

            modeleFileSelect->appendRow(list);
        }
    }
}

void FenPrincipale::clearSelectionSignal(){
    modeleFileSelect->clear();
    _session->clearFilesCurrent();

    modeleFileSelect->setHorizontalHeaderItem(0, new QStandardItem("Fichier"));
    modeleFileSelect->setHorizontalHeaderItem(1,new QStandardItem("Tags"));
}

void FenPrincipale::menuFileSelectionRequested(const QPoint &pos){

    QPoint globalPos = viewRB->mapToGlobal(pos);
    QMenu myMenu;
    myMenu.addAction("Retirer de la séléction");
    myMenu.addAction("Retirer un tag");
    QAction* selectedItem = myMenu.exec(globalPos);

    if(selectedItem){
        //Récupération du text de l'action choisie
        QString qActionString =selectedItem->text();
        std::string actionString = qActionString.toStdString();
        int row = _index.row();

        if (actionString=="Retirer de la séléction"){
            if(_index.isValid()){
                if(row<_session->getFilesCurrent().size()){// Evite sortie du vector
                    // La row corespond à la position dans le vector filesCurrent du fichier
                    std::string filePath = _session->getFilesCurrent().at(row)-> getFileAdress();
                    _session->removeFromFileCurrent(filePath);
                    refreshFileSelect();
                }
            }
        }
        if(actionString=="Retirer un tag"){
            if (_index.isValid()){
                if(row<_session->getFilesCurrent().size()){
                    std::string filePath = _session->getFilesCurrent().at(row)-> getFileAdress();
                    bool ok = false;
                    QString qTagName = QInputDialog::getText(this, "Supression Tag du fichier", "Rentrer le nom du tag à retirer du fichier",
                                                             QLineEdit::Normal, QString(), &ok);
                    if(ok && !qTagName.isEmpty()){
                        File* f = _session->getFileByPath(filePath);
                        f->removeTag(qTagName.toStdString());
                        refreshFileSelect();
                        refreshModeleTag();
                    }
                }
            }
        }
    }
}

void FenPrincipale::setIndex(const QModelIndex & indexPos){
    _index=indexPos;
}

void FenPrincipale::test(){
    this->rechercheFile->setText("sd");

}
// ----Fonction------

void FenPrincipale::refreshFileSelect(){

    modeleFileSelect->clear();
    modeleFileSelect->setHorizontalHeaderItem(0, new QStandardItem("Fichier"));
    modeleFileSelect->setHorizontalHeaderItem(1, new QStandardItem("Path"));
    modeleFileSelect->setHorizontalHeaderItem(2,new QStandardItem("Tags"));
    for ( int i=0;i<_session->getFilesCurrent().size();++i){
        std::string fileName = _session->getFilesCurrent().at(i)->getFileName();
        std::string filePath = _session->getFilesCurrent().at(i)->getFileAdress();
        std::string tags = _session->getFilesCurrent().at(i)->tagsToString();

        QStandardItem *itemFileName = new QStandardItem(QString::fromStdString(fileName));
        QStandardItem *itemFilePath = new QStandardItem(QString::fromStdString(filePath));
        QStandardItem *itemTags = new QStandardItem(QString::fromStdString(tags));

        modeleFileSelect->setItem(i,0,itemFileName);
        modeleFileSelect->setItem(i,1,itemFilePath);
        modeleFileSelect->setItem(i,2,itemTags);
    }
}

void FenPrincipale::refreshModeleTag(){
    modeleTag->clear();
    modeleTag->setHorizontalHeaderItem(0, new QStandardItem("Nom") );
    modeleTag->setHorizontalHeaderItem(1, new QStandardItem("Nombre fichier") );

    for (int i=0;i<_session->getTags().size();++i){

        std::string tagName = _session->getTags().at(i)->getTagName();

        QStandardItem* itemTagName = new QStandardItem(QString::fromStdString(tagName));
        QStandardItem* itemCount= new QStandardItem(QString::number(_session->getTags().at(i)->getCount()));

        modeleTag->setItem(i,0,itemTagName);
        modeleTag->setItem(i,1,itemCount);
    }
}
