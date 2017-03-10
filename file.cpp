#include "tag.h"
#include "file.h"

File::File(){
    this->_fileName="default";
    this->_fileAdress="/default";
    this->_tags = std::vector<Tag*>();
}
