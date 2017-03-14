#ifndef TAG
#define TAG

//forward declared dependencies
class File;

//included dependencies
#include <string>
#include <vector>
#include <iostream>

class Tag {
private:
    std::string _tagName;
    std::vector<File*> _files;
    int _count;

public:
    Tag();
    Tag(std::string tagName);
    //Getters
    std::string getTagName();
    std::vector<File*>& getFiles();
    int getCount();

    //Setters
    void setTagName(std::string tagName);
    void setFiles(std::vector<File*>& files);
    void setCount(int count);
    void incrementCount(int files);
    void decrementCount(int files);

    bool getFile(std::string fileName, File  & file);
    bool addFile(File *file);
    void addFile(std::vector<File*> *files);//Rajout plusieur fichier en même temps
};


#endif // TAG

