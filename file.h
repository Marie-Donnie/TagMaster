#ifndef FILE
#define FILE

//forward declared dependencies
class Tag;

//included dependencies
#include <string>
#include <vector>
#include <iostream>



class File{
private:
    std::string _fileName;
    std::string _fileAdress;
    std::vector<Tag*> _tags;

public:

    File();

    std::string getFileName();
    std::string getFileAdress();
    std::vector<Tag*> getTags();

    void setFileName(std::string fileName);
    void setFileAdress(std::string fileAdress);
    void setTags(std::vector<Tag*>& tags);

    void addTag(Tag* tag);

};

#endif // FILE

