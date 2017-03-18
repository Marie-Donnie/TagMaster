#ifndef FILE
#define FILE

//forward declared dependencies
class Tag;

//included dependencies
#include <string>
#include <vector>
#include <iostream>


/*! \class File
    \brief La classe pour traiter les fichiers

    Contient le nom du fichier, son adresse sur la machine (chemin absolu), et une liste de tags associés
*/
class File{
private:
    std::string _fileName;
    std::string _fileAdress;
    std::vector<Tag*> _tags;

public:

    File();
    File(std::string name, std::string adress);
    /*! \fn string getFileName()
        \brief Renvoie le nom du fichier
        \return Le nom du fichier
    */
    std::string getFileName();
    /*! \fn string getFileAdress()
        \brief Renvoie l'adresse du fichier
        \return L'adresse du fichier
    */
    std::string getFileAdress();
    /*! \fn vector<Tag*> getTags()
        \brief Renvoie les tags associés au fichier
        \return Les tags associés au fichier
    */
    std::vector<Tag*> getTags();


    /*! \fn void setFileName(std::string fileName)
        \brief Règle le nom du fichier.
        \param std::string fileName : le nouveau nom du fichier
    */
    void setFileName(std::string fileName);
    /*! \fn void setFileAdress(std::string fileAdress)
        \brief Règle le path du fichier.
        \param std::string fileAdress : le nouveau path du fichier
    */
    void setFileAdress(std::string fileAdress);
    /*! \fn void setTags(std::vector<Tag*>& tags)
        \brief Règle les tags du fichiers
        \param std::vector<Tag*>& tags : les nouveau tags du fichier
    */
    void setTags(std::vector<Tag*>& tags);
    //-----Fonction-------------

    /*! \fn bool addTag(Tag* tag)
        \brief ajoute un tag au fichier si il ne fait pas déjà partie des tags du fichier
        \param Tag* tag : le tag à rajouter
        \return bool : Return true si le fichier n'avait pas ce tag. False sinon.
    */
    bool addTag(Tag* tag);
    /*! \fn void addTag(std::vector<Tag*> *tags)
        \brief ajoute un ou des tags au fichier. Rajoute ceux que le fichier n'avait pas.
        \param std::vector<Tag*> *tags : les tag à rajouter
    */
    void addTag(std::vector<Tag*> *tags);
    /*! \fn bool removeTag(std::string tagName)
        \brief Enlève un tag du fichier via le nom du tag
        \param std::string tagName : le nom du tag à enlever
        \return bool : Return false si le fichier n'avait pas ce tag. True sinon.
    */
    bool removeTag(std::string tagName);
    /*! \fn bool egal(File* file)
        \brief Test l'égalité sur 2 file. Même path(adress) = même fichier
        \param File* file : l'un des files à tester
        \return bool : Return true si même path. False sinon.
    */
    bool egal(File* file);

    /*! \fn std::string tagsToString()
        \brief Renvoie une string avec tous les noms des tags du fichier avec une virgule entre eux
        \return std::string : la string structurer des nom des tags
    */
    std::string tagsToString(); // Renvoie une string avec tous les noms des tags du fichier

};

#endif // FILE

