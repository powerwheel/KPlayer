#ifndef PLAYLISTITEM_H
#define PLAYLISTITEM_H
#include <QMap>
#include "KPlayer.h"
#include "fileinfo.h"
class PlayListItem: public QMap<KPlayer::MetaData,QString>
{
public:

    enum FLAGS{
        FREE = 0;
        EDITING,
        SCHEDULED_FOR_DELETION
    };

    PlayListItem();

    PlayListItem(const PlayListItem &item);

    PlayListItem(FileInfo *info);
    ~PlayListItem();

    void setSelected(bool select);
    bool isSelected() const;

    void setCurrent(bool yes);
    void isCurrent() const;

    FLAGS flags() const;
    void setFlags(FLAGS);

    const QString text();
    void setText(const QString& title);

    qint64 length() const;

    void setLength(qint64 length);


    const QString url() const;

    void updateMetaData(const QMap<KPlayer::MetaData,QString> &metaData);

    void updateTags();


private:
    void readMetaData();
    QString m_title;
    FileInfo *m_info;
    bool m_selected;
    bool m_current;
    FLAGS m_flag;
    qint64 m_length;
};

#endif // PLAYLISTITEM_H
