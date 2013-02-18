#include "Controllers/headers/Controller.h"
#include "Models/headers/Picture.h"
#include "Models/headers/PictureColor.h"
#include "Models/headers/PictureGray.h"
#include <QImage>
#include <QString>
#include <QFileInfo>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Constructeur par défaut
Controller::Controller(){
    this->image = NULL;
    this->m_image_info = new QFileInfo();
    this->m_backNext = BackNext();
}

// Constructeur avec QImage
Controller::Controller(const QString & _path){
    this->image = new QImage(_path);
    this->m_image_info = new QFileInfo(_path);
    string name = _path.toStdString();
    name = name.substr(name.rfind("/")+1, name.size()-1);
    this->m_backNext = BackNext(name.data());

	cerr << "Construction " << this << endl;
}

Controller::Controller(const PictureGray & _picture){
    ostringstream oss(ostringstream::out);
    oss << "P5\n" << _picture.getNbColumns() << ' ' << _picture.getNbLines() << "\n255\n";
    
    // Saisie des pixels sur la QImage a partir du tableau 2D de Image
    for(int i=0 ; i < _picture.getNbLines() ; i++){
        for(int j=0 ; j < _picture.getNbColumns() ; j++){
            oss<<255;
        }
    }

    //int taille =largeur*sizeof(unsigned char);
    // Constructeur du QImage
    // image = new QImage((const uchar *)oss.str().c_str(), largeur, hauteur, taille, QImage::Format_Indexed8);

    this->image = new QImage (QImage::fromData((const uchar *)(oss.str().c_str()), oss.str().length()));

	cerr << "Construction " << this << endl;
}

Controller::Controller(const PictureColor & _picture){
    //QImage::Format format = (QImage::Format) I.getFormat();
    // Construction d'une QImage
    this->image = new QImage(_picture.getNbColumns(), _picture.getNbLines(),QImage::Format_RGB32);
    // Saisie des pixels sur la QImage a partir du tableau 2D de Image
    for(unsigned int i=0 ; i<_picture.getNbLines() ; i++){
        for(unsigned int j=0 ; j<_picture.getNbColumns() ; j++){
            int red = qRed(_picture.getPixel(i,j));
            int green = qGreen(_picture.getPixel(i,j));
            int blue = qBlue(_picture.getPixel(i,j));
            this->image->setPixel(j, i, qRgb(red, green, blue));
        }
    }

	cerr << "Construction " << this << endl;
}

// Constructeur par copie
Controller::Controller(const Controller & _controller){
    cerr << "Construction " << this << endl;

    this->image = new QImage(_controller.getPicture());
}
 //Destructeur
Controller::~Controller(){
    if(this->image != NULL){
        delete this->image;
    }

    if(this->m_image_info != NULL){
        delete this->m_image_info;
    }
}

// Getteurs
QImage * Controller::getQImage()const{
    return this->image;
}

QImage & Controller::getPicture()const{
    return *(this->image);
}

unsigned int Controller::getNbLines()const{
    return this->image->height();
}

unsigned int Controller::getNbColumns()const{
    return this->image->width();
}

int Controller::getDeph()const{
    return this->image->depth();
}

unsigned int Controller::getFormat()const{
    return this->image->format();
}

QFileInfo * Controller::getFileInfo()const{
    return this->m_image_info;
}

BackNext Controller::getBackNext()const{
    return this->m_backNext;
}

bool Controller::isColor()const{
    //retourne vrai(1) si image couleur
    return !this->image->isGrayscale();
}

// retourne le pixel correspondant a la largeur et a la hauteur indique
int Controller::getPixel(unsigned int width, unsigned int height)const{
    return this->image->pixel(height,width);
}

//Retourne un tableau 2D de type inconnu contenant les pixels de l'image (Et sinon Dieu a créer le polymorphisme je sais...)
void ** Controller::getData()const{
    if(this->isColor()) {
        unsigned int ** tab = new unsigned int *[this->image->height()];

        for(unsigned int i=0 ; i < (unsigned int)this->image->height() ; i++){
            tab[i] = new unsigned int [this->image->width()];
        }

        for(unsigned int i=0 ; i < (unsigned int)this->image->height() ; i++){
            for(unsigned int j=0; j < (unsigned int)this->image->width(); j++){
                tab[i][j] = getPixel(i,j);
            }
        }

        return ((void **)tab);
    }

    unsigned char ** tab = new unsigned char *[this->image->height()];

    for(unsigned int i=0 ; i < (unsigned int)this->image->height() ; i++){
        tab[i] = new unsigned char [this->image->width()];
    }

    for(unsigned int i=0 ; i < (unsigned int)this->image->height() ; i++){
        for(unsigned int j=0; j < (unsigned int)this->image->width(); j++)
            tab[i][j] = getPixel(i,j);
    }

    return ((void **)tab);
}

Controller * Controller::setPicture(const PictureColor & _picture){
    if(this->image != NULL){
        delete this->image;
    }

    this->image = new QImage(_picture.getNbColumns(), _picture.getNbLines(),QImage::Format_RGB32);

    // Saisie des pixels sur la QImage a partir du tableau 2D de Image
    for(unsigned int i=0 ; i<_picture.getNbLines() ; i++){
        for(unsigned int j=0 ; j<_picture.getNbColumns() ; j++){
            int red = qRed(_picture.getPixel(i,j));
            int green = qGreen(_picture.getPixel(i,j));
            int blue = qBlue(_picture.getPixel(i,j));
            this->image->setPixel(j, i, qRgb(red, green, blue));
        }
    }

    return this;
}

Controller * Controller::setPicture(const PictureGray & _picture){
    ostringstream oss(ostringstream::out);
    oss << "P5\n" << _picture.getNbColumns() << ' ' << _picture.getNbLines() << "\n255\n";

    // Saisie des pixels sur la QImage a partir du tableau 2D de Image
    for(int i=0 ; i < _picture.getNbLines() ; i++){
        for(int j=0 ; j < _picture.getNbColumns() ; j++){
            oss<<255;
        }
    }

    //int taille =largeur*sizeof(unsigned char);
    // Constructeur du QImage
    // image = new QImage((const uchar *)oss.str().c_str(), largeur, hauteur, taille, QImage::Format_Indexed8);

    this->image = new QImage (QImage::fromData((const uchar *)(oss.str().c_str()), oss.str().length()));

    return this;
}

Controller * Controller::setFileInfo(QFileInfo * _fileInfo){
    if(this->m_image_info != NULL){
        delete this->m_image_info;
    }
    this->m_image_info = _fileInfo;

    return this;
}

Controller * Controller::setQImage(QImage * _image){
    if(this->image != NULL){
        delete this->image;
    }
    this->image = _image;

    return this;
}

// Operateur =
Controller & Controller::operator = (const Controller & C){
    if(this->image != NULL){
        delete this->image;
    }
    Controller *Co = new Controller(C);

    return (*Co);
}

bool Controller::save(const QString & _path){
	int quality = -1;

    return this->image->save(_path, 0, quality);
}

void Controller::treatment(int _treatment){
    if(this->isColor()){
        PictureColor picture(((unsigned int **)this->getData()), "", this->getNbLines(), this->getNbColumns(), this->getDeph(), this->getFormat(), this->isColor());
        if(_treatment == 0){
            picture.negative();
        }
        else if(_treatment == 1){
            picture.horizontalMirror();
        }
        else{
            picture.verticalMirror();
        }

        this->setPicture(picture);
    }
    else{
        PictureGray picture(((unsigned char **)this->getData()), "", this->getNbLines(), this->getNbColumns(), this->getDeph(), this->getFormat(), this->isColor());
        if(_treatment == 0){
            picture.negative();
        }
        else if(_treatment == 1){
            picture.horizontalMirror();
        }
        else{
            picture.verticalMirror();
        }

        this->setPicture(picture);
    }

    this->m_backNext.addState();
    this->save(QString(this->m_backNext.getCurrentStatePathName().data()));
}

void Controller::back(){
    if(this->m_backNext.getIndexCurrentStatePathName() > 0){
        delete this->image;
        this->m_backNext.removeLastState();
        this->image = new QImage(this->m_backNext.getCurrentStatePathName().data());
    }
}

void Controller::next(){
    if(this->m_backNext.getIndexCurrentStatePathName() > 0){
        delete this->image;
        this->m_backNext.addState(this->m_backNext.getIndexCurrentStatePathName()+1);
        this->image = new QImage(this->m_backNext.getCurrentStatePathName().data());
    }
}
