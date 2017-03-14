#include "tag.h"
#include "file.h"



//-----------Constructor------------

File::File(){
    this->_fileName="default";
    this->_fileAdress="/default";
    this->_tags = std::vector<Tag*>();
}

//-----------Getter And Setter------------

std::string File::getFileName(){
    return this->_fileName;
}

std::string File::getFileAdress(){
    return this->_fileAdress;
}

std::vector<Tag*> File::getTags(){
    return this->_tags;
}

void File::setFileName(std::string fileName){
    this->_fileName=fileName;
}

void File::setFileAdress(std::string fileAdress){
    this->_fileAdress=fileAdress;
}

void File::setTags(std::vector<Tag *> &tags){
    this->_tags=tags;
}


//-----------Fonctions------------

//Rajoute un tag au fichier
bool File::addTag(Tag *tag){
    int i=0;
    bool pasTrouver = true;
    while ((i<this->_tags.size())&&(pasTrouver)){
        if(this->_tags.at(i)->getTagName()==tag->getTagName()){
            // Tags ont le même nom = même tag
            pasTrouver=false;
        }else{
            ++i;
        }
    }
    if(pasTrouver)this->_tags.push_back(tag);
    return pasTrouver;
}

//Rajoute plusieur tag au fichier
void File::addTag(std::vector<Tag *> *tags){
    for (int i=0;i<tags->size();++i){
        this->addTag(tags->at(i));
    }
}
