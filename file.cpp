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
void File::addTag(Tag *tag){
    this->_tags.push_back(tag);
}
