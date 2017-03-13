#ifndef SESSIONACTUEL_H
#define SESSIONACTUEL_H

#include "file.h"
#include "tag.h"

class SessionActuel
{
private :
    std::vector<Tag*> _tags;
    std::vector<File*> _files;

    std::vector<Tag*> _tagsCurrent;// Tags actuellement séléctionner
    std::vector<File*> _filesCurrent;//File actuellement séléctionner

public:
    SessionActuel();

    std::vector<File*>& getFiles();
    std::vector<Tag*> getTags();
    std::vector<File*>& getFilesCurrent();
    std::vector<Tag*> getTagsCurrent();


    void setFiles(std::vector<File*>& files);
    void setTags(std::vector<Tag*>& tags);
    void setFilesCurrent(std::vector<File*>& files);
    void setTagsCurrent(std::vector<Tag*>& tags);


    bool addTag(std::string tagName); // Return false si le tag existe déjà
    bool addFile(std::string fileName, std::string fileAdress);// Return false si le file existe déjà



};

#endif // SESSIONACTUEL_H
