#include "Models/headers/BackNext.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <QDir>
#include <QFile>
#include <QDebug>
using namespace std;

BackNext::BackNext(){
	//On initialise tous les attributs par défaut
    this->m_index = 0;
    this->m_currentIndex = 0;
    this->m_pathName = "";
}

BackNext::BackNext(const char * _name){
    this->m_index = 0;
    this->m_currentIndex = 0;
	//On récupère le nom du fichier et on la met dans un string
	string name = string(_name);
	//On récupère l'extension de l'image
    string extension = name.substr(name.rfind("."), name.size()-1);
	//On récupère le nom de l'image sans l'extension
    name = name.substr(0,name.rfind("."));
	//Si le répertoire temporaire n'existe pas
    if(!this->ms_dir_cache.exists()){
        qDebug() << "Fichier existe ? : " << !this->ms_dir_cache.exists();
		//On crée le repertoire temporaire
        qDebug() << this->ms_dir_cache.mkpath(this->ms_dir_cache.path());
        qDebug() << this->ms_dir_cache.mkdir("tmp");
	}
	//On génere le chemin de l'image temporaire
    this->m_pathName = this->ms_dir_cache.path().toStdString()+"/tmp/"+name+to_string(this->m_index)+extension;
}

QDir BackNext::ms_dir_cache = QDir(".visiut3/");

void BackNext::addState(int _index){
    if(_index == -1){
        this->m_index++;
    }
    else{
        this->m_index = _index;
    }
    this->m_currentIndex = this->m_index;
    string extension = this->m_pathName.substr(this->m_pathName.rfind("."), this->m_pathName.size()-1);
    this->m_pathName = this->m_pathName.substr(0, this->m_pathName.rfind("."));
    if(this->m_index <= 9){
        this->m_pathName = this->m_pathName.substr(0, this->m_pathName.size()-1)+to_string(this->m_index)+extension;
    }
    else{
        this->m_pathName = this->m_pathName.substr(0, this->m_pathName.size()-2)+to_string(this->m_index)+extension;
    }
}

void BackNext::removeLastState(){
    this->m_currentIndex--;
    this->removeState(this->m_index-1);
}

//---------------------------On part du principe qu'on enlevera pas plus de 1000 traitements (À améliorer dans l'avenir)------------------------------------------------//
void BackNext::removeState(int _index){
    this->m_index = _index;
    string extension = this->m_pathName.substr(this->m_pathName.rfind("."), this->m_pathName.size()-1);
    this->m_pathName = this->m_pathName.substr(0, this->m_pathName.rfind("."));
    if(this->m_index < 9)
        this->m_pathName = this->m_pathName.substr(0, this->m_pathName.size()-1)+to_string(this->m_index)+extension;
    else if(this->m_index >= 9 && this->m_index < 100)
        this->m_pathName = this->m_pathName.substr(0, this->m_pathName.size()-2)+to_string(this->m_index)+extension;

    cerr << "Remove "+this->getCurrentStatePathName() << endl;

}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void BackNext::removeTemporyFile(){

    while(this->m_index > 0){
        QFile::remove(this->getCurrentStatePathName().data());
        qDebug() << QString(this->getCurrentStatePathName().data());
        this->removeLastState();
	}

    if(this->ms_dir_cache.exists()){
        this->ms_dir_cache.rmdir("tmp");
        this->ms_dir_cache.rmpath(this->ms_dir_cache.path());
	}
}

string & BackNext::getCurrentStatePathName(){
    return this->m_pathName;
}

int BackNext::getIndexCurrentStatePathName()const{
    return this->m_currentIndex;
}

string to_string(int _nb){
    stringstream ss;
    ss << _nb;
    return ss.str();
}

