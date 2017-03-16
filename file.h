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
    File(std::string name, std::string adress);

    std::string getFileName();
    std::string getFileAdress();
    std::vector<Tag*> getTags();

    void setFileName(std::string fileName);
    void setFileAdress(std::string fileAdress);
    void setTags(std::vector<Tag*>& tags);

    bool addTag(Tag* tag);
    void addTag(std::vector<Tag*> *tags);// Rajout plusieur tag en même temps
    bool egal(File* file); // Même path = même file

    std::string tagsToString();// Renvoi une string avec tout les noms des tags du fichier

};

#endif // FILE

