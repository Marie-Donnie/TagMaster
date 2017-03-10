#include "mainwindow.h"
#include <QApplication>
#include "tag.cpp"
#include "file.cpp"
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();




    //------TESTING SECTION--------

    Tag t = Tag();
    File file= File();
    vector<File*> Vf= vector<File*>();
    Vf.push_back(&file);
    cout<< "The name is "<<t.getTagName()<< endl;
    cout<< " The number of file is "<<t.getFiles().size()<<endl;
    t.setTagName("lol");
    t.setFiles(Vf);
    cout<< " The number of file is "<<t.getFiles().size()<<endl;

    //---END TESTING SECTION---------

    return a.exec();
}
