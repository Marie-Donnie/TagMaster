#include "tag.h"
#include "file.h"



//-----------Constructor------------

File::File(){
    this->_fileName="default";
    this->_fileAdress="/default";
    this->_tags = std::vector<Tag*>();
}

File::File(std::string name, std::string adress){
    this->_fileName=name;
    this->_fileAdress=adress;
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
        if(this->_tags.at(i)->egal(tag)){
            // Tags ont le même nom = même tag
            pasTrouver=false;
        }else{
            ++i;
        }
    }
    if(pasTrouver)this->_tags.push_back(tag);
    return pasTrouver;
}

//Rajoute plusieurs tags au fichier
void File::addTag(std::vector<Tag *> *tags){
    for (int i=0;i<tags->size();++i){
        this->addTag(tags->at(i));
    }
}

//
bool File::egal(File *file){
    return this->_fileAdress==file->getFileAdress();
}

// Enlève un tag du fichier par son nom. Renvoie true si le fichier avait ce tag
bool File::removeTag(std::string tagName){
    bool trouver = false;
    int i=0;

    while ((i<this->_tags.size())&&(!trouver)){
        if(this->_tags.at(i)->getTagName()==tagName){
            trouver=true;
            Tag* tag =this->_tags.at(i);
            this->_tags.erase(this->_tags.begin()+i);
            tag->removeFile(this->_fileAdress);
        }else{
            ++i;
        }
    }
    return trouver;
}

// Renvoie une string avec tous les noms des tags du fichier
std::string File::tagsToString(){
    std::string listTags="";

    for (int i=0;i<this->_tags.size();++i){
        listTags+=this->_tags.at(i)->getTagName()+", ";
    }
    return listTags;
}
