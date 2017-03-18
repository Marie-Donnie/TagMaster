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
    void addTag(std::vector<Tag*> *tags); // Rajoute plusieurs tags en même temps
    bool removeTag(std::string tagName); // Enlève un tag du fichier par son nom. Renvoie true le fichier avait ce tag
    bool egal(File* file); // Même path = même file

    std::string tagsToString(); // Renvoie une string avec tous les noms des tags du fichier

};

#endif // FILE

