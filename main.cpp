#include "mainwindow.h"
#include <QApplication>
#include "tag.cpp"
#include "file.cpp"
#include <iostream>
#include "fenprincipale.h"
#include "sessionActuel.cpp"

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
    //w.show();


    FenPrincipale f;
    f.show();



    //------TESTING SECTION--------

    SessionActuel sessionActuel;

    Tag t = Tag();
    File file= File();
    File file2;
    vector<File*> Vf= vector<File*>();
    file.setFileName("test");
    Vf.push_back(&file);
    cout<< "The name is "<<t.getTagName()<< endl;
    cout<< " The number of file is "<<t.getFiles().size()<<endl;
    t.setTagName("lol");
    t.addFile(&file);
    cout<< " The number of file is "<<t.getFiles().size()<<endl;
    t.getFile("test",file2);
    cout<<"The name of the file is "<<file2.getFileName()<<endl;
    cout<<"The name that was to bre found is "<<file.getFileName()<<endl;

    file2.addTag(&t);

    sessionActuel.addTag("test");
    sessionActuel.addFile("testFile","/test");

    cout<<"Name du tag : "<<sessionActuel.getTags().at(0)->getTagName()<<endl;
    cout<<"Name du file : "<<sessionActuel.getFiles().at(0)->getFileName()<<endl;

    //---END TESTING SECTION---------

    return a.exec();
}
