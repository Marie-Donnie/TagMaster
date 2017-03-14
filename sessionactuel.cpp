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


bool SessionActuel::addTag(std::string tagName){
    bool pasTrouver=true;
    int i=0;

    while((i<this->_tags.size())&&(!pasTrouver)){
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


bool SessionActuel::addFile(std::string fileName, std::string fileAdress){
    bool pasTrouver=true;
    int i=0;

    while((i<this->_files.size())&&(!pasTrouver)){
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

// Rajoute les tagsCurrent aux filesCurrent
void SessionActuel::lieTagFile(){
    for(int i=0;i<this->_filesCurrent.size();++i){
        this->_filesCurrent.at(i)->addTag(&this->_tagsCurrent);
    }

    for(int i=0;i<this->_tagsCurrent.size();++i){
        this->_tagsCurrent.at(i)->addFile(&this->_filesCurrent);
    }

    //On libère file et tag current après l'opération
    this->_filesCurrent.clear();
    this->_tagsCurrent.clear();
}
