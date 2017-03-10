#include "file.h"
#include "tag.h"
#include <iostream>

Tag::Tag(){
    this->_count=0;
    this->_files= std::vector<File*>();
    this->_tagName = "default";
}

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

void Tag::incrementCount(int files){
    this->_count+=files;
}

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
