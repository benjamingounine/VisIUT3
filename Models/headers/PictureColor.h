#ifndef PICTURECOLOR_H
#define PICTURECOLOR_H
#include <string>
#include "Models/headers/Picture.h"

/*
 * @author INFS3D_Prj03 (Faglin Florian & Tissier Raphael & Benjamin Gounine)
 * @date 10/03/2012
 */

class PictureColor : public Picture{
    private :
        unsigned int ** m_picture;

    public :
        PictureColor();
        PictureColor(unsigned int ** _picture, const std::string & _name, unsigned int _nbLines, unsigned int _nbColumns, int _deph, unsigned int _format, bool _color);
        PictureColor(const PictureColor & _picture);
        virtual ~PictureColor();
        PictureColor & operator =(const PictureColor & _picture);
        unsigned int ** getPictureColor()const;
        unsigned int getPixel(unsigned int _x,unsigned int _y) const;
        PictureColor * setPictureColor(unsigned int ** _picture);
        virtual PictureColor * setPixel(unsigned int _x, unsigned int _y, int _value);
        virtual void negative();
        virtual void verticalMirror();
        virtual void horizontalMirror();
};

#endif // PICTURECOLOR_H
