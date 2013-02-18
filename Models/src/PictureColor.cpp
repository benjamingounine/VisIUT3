#include <iostream>
#include "Models/headers/PictureColor.h"
#include "Models/headers/Picture.h"
#include "Models/headers/Traitement.h"
using namespace std;

PictureColor::PictureColor() : Picture(){
    this->m_picture = NULL;

    cerr << "Default Constructor " << this << endl;
}

PictureColor::PictureColor(unsigned int **_picture, const std::string & _name, unsigned int _nbLines, unsigned int _nbColumns, int _deph, unsigned int _format, bool _color) : Picture(_name, _nbLines, _nbColumns, _deph, _format, _color){
    cerr << "Argument Constructor " << this << endl;

    this->m_picture = _picture;
}

PictureColor::PictureColor(const PictureColor & _picture) : Picture(){
    cerr << "Copy Constructor " << this << endl;
    this->m_name =_picture.m_name;
    this->m_nbLines =_picture.m_nbLines;
    this->m_nbColumns = _picture.m_nbColumns;
    this->m_deph = _picture.m_deph;
    this->m_format = _picture.m_format;
    this->m_color = _picture.m_color;

    this->m_picture = new unsigned int *[this->m_nbLines];

    for(unsigned int i=0 ; i<this->m_nbLines ; i++){
        this->m_picture[i] = new unsigned int [this->m_nbColumns];
    }

    for(unsigned int i=0 ; i<this->m_nbLines ; i++){
        for(unsigned int j=0 ; j<this->m_nbColumns ; j++){
            this->m_picture[i][j] = _picture.m_picture[i][j];
        }
    }
}

PictureColor::~PictureColor(){
    cerr << "Destructor " << this << endl;

    if(this->m_picture != NULL){
        for(unsigned int i=0 ; i<this->m_nbLines ; i++){
                delete this->m_picture[i];
        }

        delete this->m_picture;
    }


}

PictureColor & PictureColor::operator =(const PictureColor & _picture){
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
        for(unsigned int i=0 ; i<this->m_nbLines ; i++)
                delete this->m_picture[i];

        delete this->m_picture;

        this->m_picture = new unsigned int *[this->m_nbLines];

        for(unsigned int i=0 ; i<this->m_nbLines ; i++){
            this->m_picture[i] = new unsigned int [this->m_nbColumns];
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

unsigned int ** PictureColor::getPictureColor()const{
    unsigned int ** copy = new unsigned int *[this->m_nbLines];

    for(unsigned int i=0 ; i<this->m_nbLines ; i++){
        copy[i] = new unsigned int [this->m_nbColumns];
    }

    for(unsigned int i=0 ; i<this->m_nbLines ; i++){
        for(unsigned int j=0 ; j<this->m_nbColumns ; j++){
            copy[i][j] = this->m_picture[i][j];
        }
    }

    return copy;
}

unsigned int PictureColor::getPixel(unsigned int _x,unsigned int _y)const{
        return this->m_picture[_x][_y];
}

PictureColor * PictureColor::setPictureColor(unsigned int **_picture){
   this->m_picture = _picture;

    return this;
}

void PictureColor::setPixel(unsigned int _x, unsigned int _y, int _value){
    this->m_picture[_x][_y] = _value;
}

void PictureColor::negative(){
    unsigned int ** new_picture = Traitement<unsigned int>::negative(this->m_picture, this->m_nbColumns, this->m_nbLines);
    this->freePicture((void **)this->m_picture);
    this->m_picture = new_picture;
}

void PictureColor::verticalMirror(){
    unsigned int ** new_picture = Traitement<unsigned int>::verticalMirror(this->m_picture, this->m_nbColumns, this->m_nbLines);
    this->freePicture((void**)this->m_picture);
    this->m_picture = new_picture;
}

void PictureColor::horizontalMirror(){
    unsigned int ** new_picture = Traitement<unsigned int>::horizontalMirror(this->m_picture, this->m_nbColumns, this->m_nbLines);
    this->freePicture((void**)this->m_picture);
    this->m_picture = new_picture;
}
