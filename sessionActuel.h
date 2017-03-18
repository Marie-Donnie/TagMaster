#ifndef SESSIONACTUEL_H
#define SESSIONACTUEL_H

#include "file.h"
#include "tag.h"


/*! \class Tag
    \brief La classe pour la sessionActuel. Elle stock toute les donnée de session en cours
    et perment d'intéragire avec elles et garde leurs cohérences. Empêche la duplication des tags et fichiers.
*/
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

    /*! \fn std::vector<File*>& getFiles()
        \brief Accesseur de l'attribut _files de SessionActuel.
        \return  std::vector<File*>&  : les fichiers de la session
    */
    std::vector<File*>& getFiles();
    /*! \fn std::vector<Tag*> getTags()
        \brief Accesseur de l'attribut _tags de SessionActuel.
        \return  std::vector<Tag*> : les tags de la session
    */
    std::vector<Tag*> getTags();
    /*! \fn std::vector<File*>& getFilesCurrent()
        \brief Accesseur de l'attribut _filesCurrent de SessionActuel.
        \return  std::vector<File*>& : les filesCurrent de la session coté gestion de Fichier
    */
    std::vector<File*>& getFilesCurrent();
    /*! \fn std::vector<File*>& getFilesCurrent2()
        \brief Accesseur de l'attribut _filesCurrent2 de SessionActuel.
        \return  std::vector<File*>& : les filesCurrent de la session coté gestion de Tag
    */
    std::vector<File*>& getFilesCurrent2();
    /*! \fn std::vector<Tag*> getTagsCurrent()
        \brief Accesseur de l'attribut _tagsCurrent de SessionActuel.
        \return  std::vector<Tag*> : les tags Current de la session
    */
    std::vector<Tag*> getTagsCurrent();

    /*! \fn void setFiles(std::vector<File*>& files)
        \brief Règle les files de la session
        \param std::vector<File*>& files : la nouvelle liste de files de la session
    */
    void setFiles(std::vector<File*>& files);
    /*! \fn void setTags(std::vector<Tag*>& tags)
        \brief Règle les tags de la session
        \param std::vector<File*>& files : la nouvelle liste de tags de la session
    */
    void setTags(std::vector<Tag*>& tags);
    /*! \fn void setFilesCurrent(std::vector<File*>& files)
        \brief Règle les files Current de la session coté gestion de fichier
        \param std::vector<File*>& files : la nouvelle liste de file current de la session
    */
    void setFilesCurrent(std::vector<File*>& files);
    /*! \fn void setFilesCurrent2(std::vector<File*>& files)
        \brief Règle les files Current de la session coté gestion de tags
        \param std::vector<File*>& files : la nouvelle liste de file current2 de la session
    */
    void setFilesCurrent2(std::vector<File*>& files);
    /*! \fn void void setTagsCurrent(std::vector<Tag*>& tags)
        \brief Règle les tags current de la session
        \param std::vector<File*>& files : la nouvelle liste de tags current de la session
    */
    void setTagsCurrent(std::vector<Tag*>& tags);
//------------Fonction------------
    /*! \fn bool addTag(std::string tagName)
        \brief Rajoute un tag à la session via son nom si il n'existe pas déjà
        \param std::string tagName: le nom du tag à rajouter
        \return bool : Return false si le tag existe déjà. Return true sinon
    */
    bool addTag(std::string tagName);
    /*! \fn bool addFile(std::string fileName, std::string fileAdress)
        \brief Rajoute un file à la session via son path et name si il n'existe pas déjà
        \param std::string fileName: le nom du fichier à rajouter
        \param std::string fileAdress : le path du fichier à rajouter
        \return bool : Return false si le fichier existe déjà. Return true sinon
    */
    bool addFile(std::string fileName, std::string fileAdress);
    /*! \fn bool addFileToCurrent(std::string fileName,std::string filePath)
        \brief Rajoute un fichier aux fichiers courants coté gestion de fichier via son path et name si il n'existe pas déjà
        \param std::string fileName: le nom du fichier à rajouter
        \param std::string fileAdress : le path du fichier à rajouter
        \return bool : Return false si le fichier existe déjà dans les current. Return true sinon.
    */
    bool addFileToCurrent(std::string fileName,std::string filePath);
    /*! \fn bool addFileToCurrent2(std::string fileName,std::string filePath)
        \brief Rajoute un fichier aux fichiers courants coté gestion de tags via son path et name si il n'existe pas déjà
        \param std::string fileName: le nom du fichier à rajouter
        \param std::string fileAdress : le path du fichier à rajouter
        \return bool : Return false si le fichier existe déjà dans les current. Return true sinon.
    */
    bool addFileToCurrent2(std::string fileName,std::string filePath);
    /*! \fn void addFileToCurrent2(File* f)
        \brief Rajoute un fichier aux fichiers courants coté gestion de fichier
        \param File* f : fichier à rajouter
    */
    void addFileToCurrent2(File* f);
    /*! \fn void addTagToCurrent(std::string tagName)
        \brief Rajoute un tag courant via son nom, suppose que le tag est déjà dans la liste
        \param std::string tagName : nom du tag
    */
    void addTagToCurrent(std::string tagName);
    /*! \fn void addTagToCurrent(Tag* tag)
        \brief Rajoute un tag dans tag current
        \param Tag* tag: le tag à rajouter
    */
    void addTagToCurrent(Tag* tag);
    /*! \fn void removeTag(std::string tagName)
        \brief Enlève un tag de la liste de tags via son nom
        \param std::string tagName : le nom du tag à enlever
    */
    void removeTag(std::string tagName);
    /*! \fn void clearTagsCurrent()
        \brief Clear tag courant
    */
    void clearTagsCurrent();
    /*! \fn void clearFilesCurrent()
        \brief Clear fichier courant
    */
    void clearFilesCurrent();
    /*! \fn void clearFilesCurrent2()
        \brief Clear fichier courant 2
    */
    void clearFilesCurrent2();
    /*! \fn Tag* getTagByName(std::string tagName)
        \brief Renvoie un tag par son nom
        \param std::string tagName : le nom du tag à get
        \return Tag * : le tag avec ce nom
    */
    Tag* getTagByName(std::string tagName);
    /*! \fn File* getFileByPath(std::string filePath)
        \brief Renvoie un file par son path
        \param std::string filePath : le path du file à get
        \return File * : le file avec ce path
    */
    File* getFileByPath(std::string filePath);
    /*! \fn bool removeFromFileCurrent(std::string filePath)
        \brief Retire un fichier des fichiers courants et renvoie true si ça réussit
        \param std::string filePath : le path du file à remove
        \return bool : true si le fichier était dans les current. False sinon
    */
    bool removeFromFileCurrent(std::string filePath);
    /*! \fn bool removeFromFileCurrent2(std::string filePath)
        \brief Retire un fichier des fichiers courants2 et renvoie true si ça réussit
        \param std::string filePath : le path du file à remove
        \return bool : true si le fichier était dans les current2. False sinon
    */
    bool removeFromFileCurrent2(std::string filePath);
    /*! \fn void fusionTag(std::vector<Tag*> listTag, std::string newName)
        \brief Fusionne les tags du vector dans un nouveau tag et le rajoute à la liste de tag
        \param std::vector<Tag*> listTag: les tags à fusionner
        \param std::string newName : le nom du tag résultant de la fusion
        \warning clear les tags current
    */
    void fusionTag(std::vector<Tag*> listTag, std::string newName);
    /*! \fn void supprimerTag(std::vector<Tag*> listTag)
        \brief Supprime les tags ce trouvant dans le vector.
        \param std::vector<Tag*> listTag : les tags à suprimmer
        \warning clear les tags current
    */
    void supprimerTag(std::vector<Tag*> listTag);
    /*! \fn bool existeTag(std::string tagName)
        \brief Dit si le tag existe déjà
        \param std::string tagName : le nom du tag d'on on vérifie l'existance
        \warning clear les tags current
    */
    bool existeTag(std::string tagName);
    /*! \fn bool existeTag(std::string tagName)
        \brief Rajoute les tagsCurrent aux filesCurrent et et vice versa. Les fichier on maitenant ces tag et
        les tags ces fichiers liant les 2 entres eux.
        \warning clear les tags current
    */
    void lieTagFile();



};

#endif // SESSIONACTUEL_H
