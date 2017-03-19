#ifndef TAG
#define TAG

//forward declared dependencies
class File;

//included dependencies
#include <string>
#include <vector>
#include <iostream>
/*! \class Tag
    \brief La classe pour les tags
*/
class Tag {
private:
    std::string _tagName;
    std::vector<File*> _files;
    int _count;

public:
    /*! \fn Tag()
        \brief Constructeur par défaut.
        \return Tag : le tag créé
    */
    Tag();
    /*! \fn Tag(std::string tagName)
        \brief Un second constructeur qui crée un tag avec le nom passé en paramètre.
        \return Tag : le tag créé
    */
    Tag(std::string tagName);
    //Getters
    /*! \fn std::string getTagName()
        \brief Accesseur de l'attribut _TagName de Tag.
        \return std::string : le nom de tag
    */
    std::string getTagName();
    /*! \fn std::vector<File*>& getFiles()
        \brief Accesseur de l'attribut _files de Tag.
        \return  std::vector<File*>& : le pointeur vers la liste de fichier du tag
        L'attribut _files contient tous les fichiers auxquels est associé le tag.
    */
    std::vector<File*>& getFiles();
    /*! \fn int getCount()
        \brief Accesseur de l'attribut _count de Tag.
        \return int : le nombre de fichiers ayant ce tag
    */
    int getCount();

    //Setters
    /*! \fn void setTagName(std::string tagName)
        \brief Règle le nom du Tag.
        \param std::string tagName : le nouveau nom du tag
    */
    void setTagName(std::string tagName);
    /*! \fn void setFiles(std::vector<File*>& files)
        \brief Règle la liste de fichiers du tag.
        \param std::vector<File*>& files : la nouvelle liste de fichiers
    */
    void setFiles(std::vector<File*>& files);
    /*! \fn void setCount(int count)
        \brief Règle l'attribut _count du Tag
        \param int count : le nouveau compte du tag
    */
    void setCount(int count);
    /*! \fn void incrementCount(int files)
        \brief Incrémente l'attribut _count du Tag.
        \param int files : la valeur par laquelle on incrémente
    */
    void incrementCount(int files);
    /*! \fn void decrementCount(int files)
        \brief Décrémente l'attribut _count du Tag.
        \param int files : la valeur que l'on soustrait
    */
    void decrementCount(int files);

    /*! \fn bool getFile(std::string filePath, File  & file)
        \brief Recupère le fichier de liste de fichiers du tag via son chemin.
        \param std::string filePath : le path du fichier
        \param  File  & file : on met le fichier trouvé dedans
        \return bool : return true si le fichier est trouvé ; false sinon.
    */
    bool getFile(std::string filePath, File  & file);
    /*! \fn bool addFile(File *file)
        \brief Rajoute un fichier dans la liste de fichier du tag
        \param File *file : le fichier rajouter
        \return bool : return true si le fichier n'était pas encore dans la liste du tag. Return false sinon.
    */
    bool addFile(File *file);
    /*! \fn void addFile(std::vector<File*> *files)
        \brief Rajoute plusieurs fichiers en même temps dans la liste de fichier du tag
        \param std::vector<File*> *files : la liste de fichier rajouter
    */
    void addFile(std::vector<File*> *files);
    /*! \fn bool removeFile(std::string filePath)
        \brief Enlève un fichier du tag via son path
        \param std::string filePath : le path du fichier à enlever
        \return bool : Return true si le fichier était dans la liste de fichiers du tag. Return false sinon.
    */
    bool removeFile(std::string filePath);
    /*! \fn Tag* fusion(std::vector<Tag*> listTag, std::string newName)
        \brief Fusionne plusieurs tags ensemble dans un nouveau tag.
        \param std::vector<Tag*> listTag : les des fichiers à fusionner
        \param  std::string newName : le nom du nouveau tag résultant de la fusion
        \return Tag* : le tag résultant de la fusion
    */
    Tag* fusion(std::vector<Tag*> listTag, std::string newName);
    /*! \fn bool egal(Tag *tag)
        \brief Teste l'égalité de tags selon le principe même nom = même tag.
        \param Tag *tag : l'un des 2 tag à comparer
        \return bool : Return true si les deux tags ont le même nom. False Sinon.
    */
    bool egal(Tag *tag); // Même nom = même tag
    /*! \fn bool countCompare(Tag *t1, Tag *t2)
        \brief Comparateur par nombre de fichiers associés pour la fonction sort() sur les tags.
        \return bool : Return true si le premier tags a plus de fichier que le second. False sinon.
    */
    bool countCompare(Tag *t1, Tag *t2);
    /*! \fn  bool nameCompare(Tag *t1, Tag *t2)
        \brief Comparateur par ordre alphabétique (ASCII) pour fonction sort() sur les tags.
        \return bool : Return true si le premier tags est avant dans l'ordre ASCII. False sinon.
    */
    bool nameCompare(Tag *t1, Tag *t2);

};



#endif // TAG

