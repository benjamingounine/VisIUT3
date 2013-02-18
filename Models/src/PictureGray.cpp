#include <iostream>
#include "Models/headers/PictureGray.h"
#include "Models/headers/Traitement.h"
using namespace std;

PictureGray::PictureGray() : Picture(){
    this->m_picture = NULL;
}

PictureGray::PictureGray(unsigned char **_picture, const std::string &_name, unsigned int _nbLines, unsigned int _nbColumns, int _deph, int _format, bool _color) : Picture(_name, _nbLines, _nbColumns, _deph, _format, _color){
    this->m_picture = _picture;
}

PictureGray::PictureGray(const PictureGray &_picture) : Picture(){
    this->m_name =_picture.m_name;
    this->m_nbLines =_picture.m_nbLines;
    this->m_nbColumns = _picture.m_nbColumns;
    this->m_deph = _picture.m_deph;
    this->m_format = _picture.m_format;
    this->m_color = _picture.m_color;

    this->m_picture = new unsigned char *[this->m_nbLines];

    for(unsigned int i=0 ; i<this->m_nbLines ; i++){
        this->m_picture[i] = new unsigned char [this->m_nbColumns];
    }

    for(unsigned int i=0 ; i<this->m_nbLines ; i++){
        for(unsigned int j=0 ; j<this->m_nbColumns ; j++){
            this->m_picture[i][j] = _picture.m_picture[i][j];
        }
    }
}

PictureGray::~PictureGray(){
    if(this->m_picture != NULL){
        for(unsigned int i=0 ; i<this->m_nbLines ; i++){
                delete this->m_picture[i];
        }
        delete this->m_picture;
    }
}

PictureGray & PictureGray::operator =(const PictureGray & _picture){
    if(this->m_name != _picture.m_name){
        this->m_name = _picture.m_name;
    }
    if(this->m_nbLines != _picture.m_nbLines){
        this->m_nbLines = _picture.m_nbLines;
    }
    if(this->m_nbColumns != _picture.m_nbColumns){
        this->m_nbColumns = _picture.m_nbColumns;
    }
    if(this->m_deph != _picture.m_deph){
        this->m_deph = _picture.m_deph;
    }
    if(this->m_format != _picture.m_format){
        this->m_format = _picture.m_format;
    }
    if(this->m_color != _picture.m_color){
        this->m_color = _picture.m_color;
    }

    if(_picture.m_picture != NULL){
        for(unsigned int i=0 ; i<this->m_nbLines ; i++){
                delete this->m_picture[i];
        }
        delete this->m_picture;

        this->m_picture = new unsigned char *[this->m_nbLines];

        for(unsigned int i=0 ; i<this->m_nbLines ; i++){
            this->m_picture[i] = new unsigned char [this->m_nbColumns];
        }

        for(unsigned int i=0 ; i<this->m_nbLines ; i++){
            for(unsigned int j=0 ; j<this->m_nbColumns ; j++){
                this->m_picture[i][j] = _picture.m_picture[i][j];
            }
        }
    }
    else{
        this->m_picture = NULL;
    }

    return (*this);

}

unsigned char ** PictureGray::getPictureGray()const{
    unsigned char ** copy = new unsigned char *[this->m_nbLines];

    for(unsigned int i=0 ; i<this->m_nbLines ; i++){
        copy[i] = new unsigned char [this->m_nbColumns];
    }

    for(unsigned int i=0 ; i<this->m_nbLines ; i++){
        for(unsigned int j=0 ; j<m_nbColumns ; j++){
            copy[i][j] = this->m_picture[i][j];
        }
    }

    return copy;
}

int PictureGray:: getPixel(unsigned int _x,unsigned int _y)const{
        return this->m_picture[_x][_y];
}

PictureGray * PictureGray::setPictureGray(unsigned char ** _picture){
    this->m_picture = _picture;

    return this;
}

PictureGray * PictureGray::setPixel(unsigned int _x, unsigned int _y, int _value){
    this->m_picture[_x][_y] = _value;

    return this;
}

void PictureGray::negative(){
    unsigned char ** new_picture = Traitement<unsigned char>::negative(this->m_picture, this->m_nbColumns, this->m_nbLines);
    this->freePicture((void**)this->m_picture);
    this->m_picture = new_picture;
}

void PictureGray::verticalMirror(){
    unsigned char ** new_picture = Traitement<unsigned char>::verticalMirror(this->m_picture, this->m_nbColumns, this->m_nbLines);
    this-fFreePicture((void**)this->m_picture);
    this->m_picture = new_picture;
}

void PictureGray::horizontalMirror(){
    unsigned char ** new_picture = Traitement<unsigned char>::horizontalMirror(this->m_picture, this->m_nbColumns, this->m_nbLines);
    this->freePicture((void**)this->m_picture);
    this->m_picture = new_picture;
}
