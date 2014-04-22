#ifndef KPLAYER_H
#define KPLAYER_H


class KPlayer{
    //播放器状态
    enum State{
        Playing  = 0,
        Paused,
        Stopped,
        Buffering,
        NormalError,
        FatalError
    };
    /**
     * @brief 媒体文件信息 enum
     */
    enum MetaData{
        TITLE = 0, /*!< Title */
        ARTIST,    /*!< Artist  */
        ALBUM,     /*!< Album */
        COMMENT,   /*!< Comment */
        GENRE,     /*!< Genre */
        COMPOSER,  /*!< Composer */
        YEAR,      /*!< Year */
        TRACK,     /*!< Track number */
        DISCNUMBER,/*!< Disc number */
        URL        /*!< Stream url or local file path */
    };
};

#endif // KPLAYER_H
