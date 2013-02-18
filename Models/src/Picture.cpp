#include "Models/headers/Picture.h"
#include <string>
using namespace std;

Picture::Picture(){
    this->m_name = "";
    this->m_nbLines = 0;
    this->m_nbColumns = 0;
    this->m_deph = 0;
    this->m_format = 0;
    this->m_color = false;
}

Picture::Picture(const string & _name, unsigned int _nbLines, unsigned int _nbColumns, int _deph, int _format, bool _color){
    this->m_name = _name;
    this->m_nbLines = _nbLines;
    this->m_nbColumns = _nbColumns;
    this->m_deph = _deph;
    this->m_format = _format;
    this->m_color = _color;
}

Picture::~Picture(){

}

string Picture::getName()const{
    return this->m_name;
}

unsigned int Picture::getNbLines()const{
    return this->m_nbLines;
}

unsigned int Picture::getNbColumns()const{
    return this->m_nbColumns;
}

int Picture::getDeph()const{
    return this->m_deph;
}

int Picture::getFormat()const{
    return this->m_format;
}

bool Picture::getColor()const{
    return this->m_color;
}

Picture * Picture::setName(const string &_name){
    this->m_name = _name;

    return this;
}

Picture * Picture::setNbLines(unsigned int _nbLines){
    this->m_nbLines = _nbLines;

    return this;
}

Picture * Picture::setColumns(unsigned int _nbColumns){
    this->m_nbColumns = _nbColumns;

    return this;
}

Picture * Picture::setDeph(int _deph) {
    this->m_deph = _deph;

    return this;
}

Picture * Picture::setFormat(int _format){
    this->m_format = _format;

    return this;
}

Picture * Picture::setColor(bool _color){
    this->m_color = _color;

    return this;
}


bool Picture::isGray()const{
    return this->m_color;
}

void Picture::freePicture(void **_picture){
    for(unsigned int i=0 ; i<this->m_nbLines ; i++)
		delete _picture[i];
	delete _picture;
}
