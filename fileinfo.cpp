#include "fileinfo.h"

FileInfo::FileInfo(const QString &filePath)
{
    m_path = filePath;
    m_length = 0;
    m_metaData.insert(KPlayer::URL,filePath);
}

FileInfo::FileInfo(const FileInfo &info)
{
    *this = info;
}
FileInfo::~FileInfo(){}

void FileInfo::operator =(const FileInfo &info)
{
    setLength(info.length());
    setMetaData(info.metaData());
    setPath(info.path());
}
void FileInfo::operator ==(const FileInfo &info)
{
    return metaData() == info.metaData() &&
            path() == info.path() &&
            length() == info.length();
}

void FileInfo::operator !=(const FileInfo &info)
{
    return !operator==(info);
}

qint64 FileInfo::length() const
{
    return m_length;
}
const QString FileInfo::path() const
{
    return m_path;
}
const QString FileInfo::metaData(KPlayer::MetaData key) const
{
    return m_metaData[key];
}

const QMap<KPlayer::MetaData,QString> FileInfo::metaData() const
{
    return m_metaData;
}
void FileInfo::setMetaData(KPlayer::MetaData key, const QString &value)
{
    if(value.isEmpty() || value=="0")
        return;

    if((key == KPlayer::TRACK || key == KPlayer::DISCNUMBER) && value.contains("/"))
    {
        m_metaData.insert(key,value.section("/",0,0));
    }else{
        m_metaData.insert(key,value);
    }
}

void FileInfo::setMetaData(const QMap<KPlayer::MetaData, QString> &metaData)
{
    m_metaData = metaData;
    if(m_metaData.value(KPlayer::URL).isEmpty())
        m_metaData.insert(KPlayer::URL,m_path);

    foreach(QString value,m_metaData){
        if(value.isEmpty() || value == "0")
            metaData.remove(m_metaData.key(value));
    }
}
void FileInfo::setMetaData(KPlayer::MetaData key, int value)
{
    if(value !=0){
        m_metaData.insert(key,QString::number(value));
    }
}
void FileInfo::setPath(const QString &path)
{
    m_path = path;
    m_metaData.insert(KPlayer::URL,m_path);
}
bool FileInfo::isEmpty() const
{
    return m_metaData.isEmpty();
}
