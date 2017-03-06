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
    std::vector<File> _files;
    int _count;

public:
    Tag();
    //Getters
    std::string getTagName();
    std::vector<File>& getFiles();
    int getCount();


    //Setters
    void setTagName(std::string tagName);
    void setFiles(std::vector<File>& files);
    void setCount(int count);
    void incrementCount(int files);
    void decrementCount(int files);

    bool getFile(std::string fileName, File file);
};


#endif // TAG

