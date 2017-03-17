#include "sessionActuel.h"

//-----------Constructor------------

SessionActuel::SessionActuel()
{
    this->_files= std::vector<File*>();
    this->_tags = std::vector<Tag*>();
    this->_filesCurrent= std::vector<File*>();
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

void SessionActuel::setTagsCurrent(std::vector<Tag *> &tags){
    this->_tagsCurrent=tags;
}

//-----------Fonctions------------

// Rajoute un file  à la liste
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

//Rajoute un file à la liste
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


// Rajoute un file aux current files
bool SessionActuel::addFileToCurrent(std::string fileName, std::string filePath){
    File * file= new File(fileName,filePath);
    bool pasTrouver=true;
    bool pasDansCurrent=true;
    int i=0;

    while((i<this->_files.size())&&(pasTrouver)){
        if(file->egal(this->_files.at(i))){
            pasTrouver=false;
            //Le file existe déjà dans notre liste on le prend et on le rajoute au current
            //Si il n'est pas encore dedans
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
        //Le file n'était pas encore dans notre liste de file :
        //on rajoute celui qu'on vient de  crée au current
        this->_filesCurrent.push_back(file);
        this->_files.push_back(file);
    }
    return pasDansCurrent;
}

//Rajoute un au tag current, suppose que le tag est déjà dans la liste
void SessionActuel::addTagToCurrent(std::string tagName){
    int i=0;
    bool trouver=false;

    //i-> normalement on dépasse pas du vector mais par sécurié on vérifie
    while((i<this->_tags.size())&&(!trouver)){
        if(this->_tags.at(i)->getTagName()==tagName){
            this->_tagsCurrent.push_back(this->_tags.at(i));
            trouver=true;
        }else{
            ++i;
        }
    }
}

//Enlève un tag de la liste de tag
void SessionActuel::removeTag(std::string tagName){
    this->_tagsCurrent.clear();//Par sécurité pour éviter d'avoir un tag supprimé encore dans les currents
    for(int i=0;i<this->_tags.size();++i){
        if(this->_tags.at(i)->getTagName()==tagName){
            this->_tags.erase(this->_tags.begin()+i);
        }
    }
}

//Clear tag current
void SessionActuel::clearTagsCurrent(){
    this->_tagsCurrent.clear();
}

//Clear file current
void SessionActuel::clearFilesCurrent(){
    this->_filesCurrent.clear();
}

//Get  tag by his name
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

//Remove un file des file current et return true si ça réussi
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

// Rajoute les tagsCurrent aux filesCurrent
void SessionActuel::lieTagFile(){
    for(int i=0;i<this->_filesCurrent.size();++i){
        this->_filesCurrent.at(i)->addTag(&this->_tagsCurrent);
    }

    for(int i=0;i<this->_tagsCurrent.size();++i){
        this->_tagsCurrent.at(i)->addFile(&this->_filesCurrent);
    }

    //On libère tag current après l'opération
    this->_tagsCurrent.clear();
}
