#ifndef FILEINFO_H
#define FILEINFO_H
#include <QString>
#include <QMap>
#include "KPlayer.h"


class FileInfo
{
public:
    FileInfo(const QString &filePath = QString());
    FileInfo(const FileInfo &info);


    ~FileInfo();

    void operator=(const FileInfo &info);
    bool operator==(const FileInfo &info);
    bool operator!=(const FileInfo &info);

    qint64 length() const;

    const QString metaData(KPlayer::MetaData key) const;

    const QMap<KPlayer::MetaData,QString> metaData() const;

    bool isEmpty() const;

    const QString path() const;

    void setLength(qint64 length);

    void setMetaData(KPlayer::MetaData key,const QString &value);

    void setMetaData(KPlayer::MetaData key,int value);

    void setMetaData(const QMap<KPlayer::MetaData,QString> &metaData);

    void setPath(const QString &path);


private:
    QMap<KPlayer::MetaData,QString> m_metaData;
    qint64 m_length;
    QString m_path;
   // QList<QMap<int,int> > map;
};

#endif // FILEINFO_H
