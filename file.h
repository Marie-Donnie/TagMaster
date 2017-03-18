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

