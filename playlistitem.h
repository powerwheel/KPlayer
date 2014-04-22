#ifndef PLAYLISTITEM_H
#define PLAYLISTITEM_H
#include <QMap>
#include "KPlayer.h"
#include "fileinfo.h"
class PlayListItem: public QMap<KPlayer::MetaData,QString>
{
public:
    PlayListItem();

    PlayListItem(const PlayListItem &item);

    PlayListItem(FileInfo *info);
    ~PlayListItem();
};

#endif // PLAYLISTITEM_H
