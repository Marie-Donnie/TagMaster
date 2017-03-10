#include "file.h"
#include "tag.h"


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
