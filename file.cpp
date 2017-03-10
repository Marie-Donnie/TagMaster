#include "tag.h"
#include "file.h"

File::File(){
    this->_fileName="default";
    this->_fileAdress="/default";
    this->_tags = std::vector<Tag*>();
}

std::string File::getFileName(){
    return this->_fileName;
}

void File::setFileName(std::string fileName){
    this->_fileName=fileName;
}
