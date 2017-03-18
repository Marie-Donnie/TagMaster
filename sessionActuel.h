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
    std::vector<File*> _filesCurrent2;//File actuellement séléctionner 2

public:
    SessionActuel();

    std::vector<File*>& getFiles();
    std::vector<Tag*> getTags();
    std::vector<File*>& getFilesCurrent();
    std::vector<File*>& getFilesCurrent2();
    std::vector<Tag*> getTagsCurrent();


    void setFiles(std::vector<File*>& files);
    void setTags(std::vector<Tag*>& tags);
    void setFilesCurrent(std::vector<File*>& files);
    void setFilesCurrent2(std::vector<File*>& files);
    void setTagsCurrent(std::vector<Tag*>& tags);

    // Return false si le tag existe déjà
    bool addTag(std::string tagName);
    // Return false si le file existe déjà
    bool addFile(std::string fileName, std::string fileAdress);
    // Rajoute un file aux current files
    bool addFileToCurrent(std::string fileName,std::string filePath);
    // Rajoute un file aux current files 2
    bool addFileToCurrent2(std::string fileName,std::string filePath);
    //Rajoute un au tag current, suppose que le tag est déjà dans la liste
    void addTagToCurrent(std::string tagName);
    //Enlève un tag de la liste de tag
    void removeTag(std::string tagName);
    //Clear tag current
    void clearTagsCurrent();
    //Clear file current
    void clearFilesCurrent();
    //Clear file current 2
    void clearFilesCurrent2();
    //Get  tag by its name
    Tag* getTagByName(std::string tagName);
    //Get file by its path
    File* getFileByPath(std::string filePath);
    //Remove un file des file current et return true si ça réussi
    bool removeFromFileCurrent(std::string filePath);
    //Remove un file des file current et return true si ça réussi
    bool removeFromFileCurrent2(std::string filePath);
    // Rajoute les tagsCurrent aux filesCurrent
    void lieTagFile();



};

#endif // SESSIONACTUEL_H
