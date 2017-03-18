#include "sessionActuel.h"

//-----------Constructor------------

SessionActuel::SessionActuel()
{
    this->_files= std::vector<File*>();
    this->_tags = std::vector<Tag*>();
    this->_filesCurrent= std::vector<File*>();
    this->_filesCurrent2= std::vector<File*>();
    this->_tagsCurrent = std::vector<Tag*>();

}

//-----------Getter And Setter------------
std::vector<File*>& SessionActuel::getFiles(){
    return this->_files;
}

std::vector<Tag*> SessionActuel::getTags(){
    return this->_tags;
}

std::vector<File*>& SessionActuel::getFilesCurrent(){
    return this->_filesCurrent;
}

std::vector<File*>& SessionActuel::getFilesCurrent2(){
    return this->_filesCurrent2;
}

std::vector<Tag*> SessionActuel::getTagsCurrent(){
    return this->_tagsCurrent;
}

void SessionActuel::setFiles(std::vector<File *> &files){
    this->_files=files;
}

void SessionActuel::setTags(std::vector<Tag *> &tags){
    this->_tags=tags;
}

void SessionActuel::setFilesCurrent(std::vector<File *> &files){
    this->_filesCurrent=files;
}

void SessionActuel::setFilesCurrent2(std::vector<File *> &files){
    this->_filesCurrent2=files;
}

void SessionActuel::setTagsCurrent(std::vector<Tag *> &tags){
    this->_tagsCurrent=tags;
}

//-----------Fonctions------------

// Rajoute un fichier à la liste
bool SessionActuel::addTag(std::string tagName){
    bool pasTrouver=true;
    int i=0;
    while((i<this->_tags.size())&&(pasTrouver)){
        if(this->_tags.at(i)->getTagName()==tagName){
            pasTrouver=false;

        }else{
            ++i;
        }
    }

    if(pasTrouver){
        Tag* tag = new Tag();
        tag->setTagName(tagName);
        this->_tags.push_back(tag);
    }
    return pasTrouver;
}

//Rajoute un fichier à la liste
bool SessionActuel::addFile(std::string fileName, std::string fileAdress){
    bool pasTrouver=true;
    int i=0;

    while((i<this->_files.size())&&(pasTrouver)){
        if((this->_files.at(i)->getFileName()==fileName)&&
                (this->_files.at(i)->getFileAdress()==fileAdress)){
            pasTrouver=false;
        }else{
            ++i;
        }
    }

    if(pasTrouver){
        File* file= new File();
        file->setFileName(fileName);
        file->setFileAdress(fileAdress);
        this->_files.push_back(file);
    }

    return pasTrouver;
}


// Rajoute un fichier aux fichiers courants
bool SessionActuel::addFileToCurrent(std::string fileName, std::string filePath){
    File * file= new File(fileName,filePath);
    bool pasTrouver=true;
    bool pasDansCurrent=true;
    int i=0;

    while((i<this->_files.size())&&(pasTrouver)){
        if(file->egal(this->_files.at(i))){
            pasTrouver=false;
            //Le fichier existe déjà dans notre liste ; on le prend et on le rajoute aux courants
            //s'il n'est pas encore dedans
            for (int n=0;n<this->_filesCurrent.size();++n){
                if(file->egal(this->_filesCurrent.at(n))){
                    pasDansCurrent=false;
                }
            }
            if(pasDansCurrent){
                this->_filesCurrent.push_back(this->_files.at(i));
            }

        }else{
            ++i;
        }
    }
    if(pasTrouver){
        //Le fichier n'était pas encore dans notre liste de fichiers :
        //on rajoute celui qu'on vient de  crée aux fichiers courants
        this->_filesCurrent.push_back(file);
        this->_files.push_back(file);
    }
    return pasDansCurrent;
}

// Rajoute un fichier aux fichiers courants 2
bool SessionActuel::addFileToCurrent2(std::string fileName, std::string filePath){
    File * file= new File(fileName,filePath);
    bool pasTrouver=true;
    bool pasDansCurrent=true;
    int i=0;

    while((i<this->_files.size())&&(pasTrouver)){
        if(file->egal(this->_files.at(i))){
            pasTrouver=false;
            //Le fichier existe déjà dans notre liste on le prend et on le rajoute aux courants
            //s'il n'est pas encore dedans
            for (int n=0;n<this->_filesCurrent2.size();++n){
                if(file->egal(this->_filesCurrent2.at(n))){
                    pasDansCurrent=false;
                }
            }
            if(pasDansCurrent){
                this->_filesCurrent2.push_back(this->_files.at(i));
            }

        }else{
            ++i;
        }
    }
    if(pasTrouver){
        //Le fichier n'était pas encore dans notre liste de fichiers :
        //on rajoute celui qu'on vient de  crée aux courants
        this->_filesCurrent2.push_back(file);
        this->_files.push_back(file);
    }
    return pasDansCurrent;
}

// Rajoute un fichier aux fichiers courants 2
void SessionActuel::addFileToCurrent2(File *f){
    this->_filesCurrent2.push_back(f);
}

//Rajoute un au tag courant, supposant que le tag est déjà dans la liste
void SessionActuel::addTagToCurrent(std::string tagName){
    int i=0;
    bool trouver=false;

    //i-> normalement on ne dépasse pas du vector mais par sécurité on vérifie
    while((i<this->_tags.size())&&(!trouver)){
        if(this->_tags.at(i)->getTagName()==tagName){
            this->_tagsCurrent.push_back(this->_tags.at(i));
            trouver=true;
        }else{
            ++i;
        }
    }
}
//Rajoute un au tag courant, supposant que le tag est déjà dans la liste
void SessionActuel::addTagToCurrent(Tag *tag){
    this->_tagsCurrent.push_back(tag);
}

//Enlève un tag de la liste de tags
void SessionActuel::removeTag(std::string tagName){
    this->_tagsCurrent.clear(); //Par sécurité pour éviter d'avoir un tag supprimé encore dans les courants
    for(int i=0;i<this->_tags.size();++i){
        if(this->_tags.at(i)->getTagName()==tagName){
            this->_tags.erase(this->_tags.begin()+i);
        }
    }
}

//Clear tags courants
void SessionActuel::clearTagsCurrent(){
    this->_tagsCurrent.clear();
}

//Clear fichiers courants
void SessionActuel::clearFilesCurrent(){
    this->_filesCurrent.clear();
}

//Clear fichiers courants 2
void SessionActuel::clearFilesCurrent2(){
    this->_filesCurrent2.clear();
}
//Renvoie un tag par son nom
Tag* SessionActuel::getTagByName(std::string tagName){
    bool trouver=false;
    int i=0;
    Tag* t = new Tag(tagName);
    while((i<this->_tags.size())&&(!trouver)){
        if(this->_tags.at(i)->egal(t)){
            t=this->_tags.at(i);
            trouver=true;

        }else{
            ++i;
        }
    }
    return t;
}

// Get un file by it's path
File* SessionActuel::getFileByPath(std::string filePath){
    bool trouver=false;
    int i=0;

    File *f = new File("temporaire",filePath);
    while((i<this->_files.size())&&(!trouver)){
        if(this->_files.at(i)->egal(f)){
            f=this->_files.at(i);
            trouver=true;
        }else{
            ++i;
        }
    }
    return f;
}

//Retire un fichier des fichiers courants et renvoie true si ça réussit
bool SessionActuel::removeFromFileCurrent(std::string filePath){
    bool trouver = false;
    int i=0;
    File *f = new File("temporaire",filePath);


    while((i<this->_filesCurrent.size())&&(!trouver)){
        if(this->_filesCurrent.at(i)->egal(f)){
            trouver=true;
            this->_filesCurrent.erase(this->_filesCurrent.begin()+i);
        }else{
            ++i;
        }
    }
    return trouver;
}

//Remove un fichier des fichiers courants 2 et renvoie true si ça réussit
bool SessionActuel::removeFromFileCurrent2(std::string filePath){
    bool trouver = false;
    int i=0;
    File *f = new File("temporaire",filePath);


    while((i<this->_filesCurrent2.size())&&(!trouver)){
        if(this->_filesCurrent2.at(i)->egal(f)){
            trouver=true;
            this->_filesCurrent2.erase(this->_filesCurrent2.begin()+i);
        }else{
            ++i;
        }
    }
    return trouver;
}

//Fusion Tag
void SessionActuel::fusionTag(std::vector<Tag *> listTag, std::string newName){
    Tag * newTag = new Tag();
    newTag = newTag->fusion(listTag,newName);

    bool ok=false;
    int n=0;
    for (int i=0;i<listTag.size();++i){
        ok=false;
        n=0;
        while ( (n<this->_tags.size())&&(!ok)){
            if(this->_tags.at(n)->egal(listTag.at(i))){
                ok=true;
                this->_tags.erase(_tags.begin()+n);
            }else{
                ++n;
            }
        }
    }
    this->_tags.push_back(newTag);
    this->clearTagsCurrent();// Pour ne pas garder les tags supprimer dans la liste current
}

// Rajoute les tagsCurrent aux filesCurrent
void SessionActuel::lieTagFile(){
    for(int i=0;i<this->_filesCurrent.size();++i){
        this->_filesCurrent.at(i)->addTag(&this->_tagsCurrent);
    }

    for(int i=0;i<this->_tagsCurrent.size();++i){
        this->_tagsCurrent.at(i)->addFile(&this->_filesCurrent);
    }

    //On libère les tags courant après l'opération
    this->_tagsCurrent.clear();
}
