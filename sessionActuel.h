#ifndef SESSIONACTUEL_H
#define SESSIONACTUEL_H

#include "file.h"
#include "tag.h"

class SessionActuel
{
private :
    std::vector<Tag*> _tags;
    std::vector<File*> _files;

    std::vector<Tag*> _tagsCurrent;// Tags actuellement sélectionné
    std::vector<File*> _filesCurrent;//Fichier actuellement sélectionné
    std::vector<File*> _filesCurrent2;//Fichier actuellement sélectionné 2

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
    // Return false si le fichier existe déjà
    bool addFile(std::string fileName, std::string fileAdress);
    // Rajoute un fichier aux fichiers courants
    bool addFileToCurrent(std::string fileName,std::string filePath);
    // Rajoute un fichier aux fichiers courants 2
    bool addFileToCurrent2(std::string fileName,std::string filePath);
    // Rajoute un fichier aux fichiers courants 2
    void addFileToCurrent2(File* f);
    //Rajoute un tag courant via son nom, suppose que le tag est déjà dans la liste
    void addTagToCurrent(std::string tagName);
    //Rajoute un tag dans tag current
    void addTagToCurrent(Tag* tag);
    //Enlève un tag de la liste de tags
    void removeTag(std::string tagName);
    //Clear tag courant
    void clearTagsCurrent();
    //Clear fichier courant
    void clearFilesCurrent();
    //Clear fichier courant 2
    void clearFilesCurrent2();
    //Renvoie un tag par son nom
    Tag* getTagByName(std::string tagName);
    //Renvoie un fichier selon son chemin
    File* getFileByPath(std::string filePath);
    //Retire un fichier des fichiers courants et renvoie true si ça réussit
    bool removeFromFileCurrent(std::string filePath);
    //Retire un fichier des fichiers courants et renvoie true si ça réussit
    bool removeFromFileCurrent2(std::string filePath);
    //Fusion de Tag
    void fusionTag(std::vector<Tag*> listTag, std::string newName);
    //Supprimer un ou plusieurs des Tag
    void supprimerTag(std::vector<Tag*> listTag);
    // Rajoute les tagsCurrent aux filesCurrent
    void lieTagFile();



};

#endif // SESSIONACTUEL_H
