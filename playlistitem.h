#ifndef PLAYLISTITEM_H
#define PLAYLISTITEM_H
#include <QMap>
#include "KPlayer.h"
#include "fileinfo.h"
class PlayListItem: public QMap<KPlayer::MetaData,QString>
{
public:
    PlayListItem();
};

#endif // PLAYLISTITEM_H
