#ifndef PICTURE_H
#define PICTURE_H

#include <typeinfo>
#include <iostream>
#include <string>

/*
 * @author INFS3D_Prj03 (Faglin Florian & Tissier Raphael & Benjamin Gounine)
 * @date 31/12/2011
 */


class Picture{
    protected :
        std::string m_name;
        unsigned int m_nbLines;
        unsigned int m_nbColumns;
        int m_deph;
        int m_format;
        bool m_color;

    public:
        Picture();
        Picture(const std::string & _name, unsigned int _nbLines, unsigned int _nbColumns, int _deph, int _format, bool _color);
        virtual ~Picture();
        std::string getName()const;
        unsigned int getNbLines()const;
        unsigned int getNbColumns()const;
        int getDeph()const;
        int getFormat()const;
        bool getColor()const;
        Picture * setName(const std::string & _name);
        Picture * setNbLines(unsigned int _nbLines);
        Picture * setColumns(unsigned int _nbColumns);
        Picture * setDeph(int _deph);
        Picture * setFormat(int _format);
        Picture * setColor(bool _color);
        virtual void setPixel(unsigned int _x, unsigned int _y, int _value) = 0;
        bool isGray () const;
        virtual void negative() = 0;
        virtual void verticalMirror() = 0;
        virtual void horizontalMirror() = 0;

	protected:
        void freePicture(void** _picture);

};

#endif // PICTURE_H
