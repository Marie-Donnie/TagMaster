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

//TODO = amélioré la compléxité
/*void SessionActuel::lieTagsFiles(std::vector<File *> files, std::vector<_Tp1> tags){

    for(int i=0;i<files.size();++i){
        for (int j=0;j<this->_files.size();++j){

                if((this->_files.at(j)->getFileName()==files.at(i)->getFileName())&&
                        (this->_files.at(j)->getFileAdress()==files.at(i)->getFileAdress())){


                }
        }
    }
}
*/
