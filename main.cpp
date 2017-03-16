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
    /*
    SessionActuel sessionActuel;

    Tag t = Tag();
    Tag t2;
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
    file2.setFileName("sdfsd");
    file2.setFileAdress("/test/"+file2.getFileName());

    vector<File*> Vf2 = vector<File*>();
    Vf2.push_back(&file);
    Vf2.push_back(&file2);

    t2.addFile(&Vf2);

    cout<<"Nb de file dans t2 attendut est 2 on a : "<<t2.getFiles().size()<<endl;

    file2.addTag(&t);

    sessionActuel.addTag("test");
    sessionActuel.addFile("testFile","/test");
    sessionActuel.addFileToCurrent("testFile","/test");
    sessionActuel.addFileToCurrent("test2File","/test2");
    sessionActuel.addTagToCurrent("test");


    cout<<"Name du tag : "<<sessionActuel.getTags().at(0)->getTagName()<<endl;
    cout<<"Name du file : "<<sessionActuel.getFiles().at(0)->getFileName()<<endl;
    cout<<"Nb file Current attendut 2 trouver :"<<sessionActuel.getFilesCurrent().size()<<endl;
    cout<<"Nb tag Current attendut  trouver :"<<sessionActuel.getTagsCurrent().size()<<endl;
    sessionActuel.clearFilesCurrent();
    cout<<"Et maintenent on veut un 0 : "<<sessionActuel.getFilesCurrent().size()<<endl;

    */
    //---END TESTING SECTION---------

    return a.exec();
}
