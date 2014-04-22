#include "playlistitem.h"

PlayListItem::PlayListItem():QMap<KPlayer::MetaData,QString>(),
    m_flag(FREE)
{
    m_info = 0;
    m_length = 0;
    m_selected = false;
    m_current = false;
}

PlayListItem::PlayListItem(const PlayListItem &item):
    QMap<KPlayer::MetaData,QString>(item),
    m_flag(item.m_flag)
{
    m_title = item.m_title;
    if(item.m_info){
        m_info = new FileInfo(*(item.m_info));
    }else{
        m_info = 0;
    }
    m_selected = item.m_selected;
    m_current = item.m_current;
    m_length = item.m_length;
}
PlayListItem::PlayListItem(FileInfo *info):
    QMap<KPlayer::MetaData,QString>(info->metaData()),
    m_flag(FREE)
{
    m_length = info->length();
    m_selected = false;
    m_current = false;
    m_info = info;
    insert(KPlayer::URL,m_info->path());
}
PlayListItem::~PlayListItem(){
    if(m_info)
        delete m_info;
}
void PlayListItem::setSelected(bool select)
{
    m_selected = select;
}
bool PlayListItem::isSelected()
{
    return m_selected;
}
void PlayListItem::setCurrent(bool yes)
{
    m_current = yes;
}
bool PlayListItem::isCurrent()
{
    return m_current;
}
FLAGS PlayListItem::flags() const
{
    return m_flag;
}
void PlayListItem::setFlags(FLAGS f)
{
    m_flag = f;
}
const PlayListItem::text()
{
    if(m_title.isEmpty())
        readMetaData();
    return m_title;
}
void PlayListItem::setText(const QString &title)
{
    m_title = title;
}
qint64 PlayListItem::length() const
{
    return m_length;
}
void PlayListItem::setLength(qint64 length)
{
    m_length = length;
}

const PlayListItem::url() const
{
    return value(KPlayer::URL);
}
void PlayListItem::updateMetaData(const QMap<KPlayer::MetaData, QString> &metaData)
{
    QMap<KPlayer::MetaData,QString>::operator =(metaData);
    readMetaData();
}
void PlayListItem::updateTags()
{

}
void PlayListItem::readMetaData()
{

}
