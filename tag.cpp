#include "file.h"
#include "tag.h"
#include <iostream>


//-----------Constructor------------
Tag::Tag(){
    this->_count=0;
    this->_files= std::vector<File*>();
    this->_tagName = "default";
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


//Return met dans "file" le ficher d'on on a saisie le nom
//Return false si le fichier n'est pas trouver et true sinon
bool Tag::getFile(std::string fileName, File &file){
    bool found=false;
    int i=0;
    this->_files.at(i);
    while ((i < this->_files.size())&&(!found) ){
      if (this->_files.at(i)->getFileName()==fileName){
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
void Tag::addFile(File *file){
    int i=0;
    bool pasTrouver = true;
    while ((i<this->_files.size())&&(pasTrouver)){
        if((this->_files.at(i)->getFileName()==file->getFileName())&&
                (this->_files.at(i)->getFileAdress()==file->getFileAdress())){
            // File même nom + même path = même file
            pasTrouver=false;
        }else{
            ++i;
        }
    }
    if(pasTrouver){
        this->_files.push_back(file);
    }
}
