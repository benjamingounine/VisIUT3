#ifndef BACKNEXT_H
#define BACKNEXT_H

#include <string>
#include <vector>
#include <QDir>

class BackNext
{
    private:
        std::string m_pathName;
        int m_index;
        int m_currentIndex;
		static QDir ms_dir_cache;
    public:
        BackNext();
        BackNext(const char * _name);
        void addState(int _index = -1);
        void removeLastState();
        void removeState(int _index);
        void removeTemporyFile();
        std::string & getCurrentStatePathName();
        int getIndexCurrentStatePathName()const;
};

std::string to_string(int _nb);

#endif // BACKNEXT_H
