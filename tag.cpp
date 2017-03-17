#include "file.h"
#include "tag.h"
#include <iostream>


//-----------Constructor------------
Tag::Tag(){
    this->_count=0;
    this->_files= std::vector<File*>();
    this->_tagName = "default";
}

Tag::Tag(std::string tagName){
    this->_count=0;
    this->_files= std::vector<File*>();
    this->_tagName = tagName;
}

//-----------Getter And Setter------------

std::string Tag::getTagName(){
    return this->_tagName;
}


int Tag::getCount(){
    return this->_count;
}

std::vector<File*>& Tag::getFiles(){
    return this->_files;
}

void Tag::setCount(int count){
    this->_count=count;
}

void Tag::setTagName(std::string tagName){
    this->_tagName=tagName;
}

void Tag::setFiles(std::vector<File *> &files){
    this->_files=files;
}

//-----------Fonction------------

//Incrémente le compteur du nombre de de fichier du tag
void Tag::incrementCount(int files){
    this->_count+=files;
}

//Décrémente le compteur du nombre de de fichier du tag

void Tag::decrementCount(int files){
    this->_count-=files;
}

//Return met dans "file" le ficher d'on on a saisie le nom
//Return false si le fichier n'est pas trouver et true sinon
bool Tag::getFile(std::string filePath, File &file){
    bool found=false;
    int i=0;
    this->_files.at(i);
    while ((i < this->_files.size())&&(!found) ){
      if (this->_files.at(i)->getFileAdress()==filePath){
          file=*(this->_files.at(i));
          found=true;
        }else{
            ++i;
        }
    ++i;
    }
    return found;

}

//Rajoute un fichier au tag seulement le fichier n'a pas déjà ce tag
bool Tag::addFile(File *file){
    int i=0;
    bool pasTrouver = true;
    while ((i<this->_files.size())&&(pasTrouver)){
        if(this->_files.at(i)->egal(file)){
            // File même nom + même path = même file
            pasTrouver=false;
        }else{
            ++i;
        }
    }
    if(pasTrouver){
        this->_files.push_back(file);
        this->_count+=1;
    }
    return pasTrouver;
}

//Rajoute plusieur file au tag
void Tag::addFile(std::vector<File *> *files){
    for (int i=0;i<files->size();++i){
        this->addFile(files->at(i));
    }
}

//Enlève un file du tag. Renvoit true si le file était dans la liste de file du tag.
bool Tag::removeFile(std::string filePath){
    bool trouver = false;
    int i=0;

    while ((i<this->_files.size())&&(!trouver)) {
        if(this->_files.at(i)->getFileAdress()==filePath){
            trouver=true;
            this->_files.erase(_files.begin()+i);
            this->decrementCount(1);
        }else{
            ++i;
        }
    }
    return trouver;
}

//
bool Tag::egal(Tag *tag){
    return this->_tagName==tag->getTagName();
}
