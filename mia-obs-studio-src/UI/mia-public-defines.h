#pragma once

#include <qstring.h>

// zjg add 1 米亚课程专用
struct MiaObsServerConf
{
	struct General
	{
		QString name;
	}g;

    struct Stream
    {
        bool    valid;
        QString key;
        QString url;
        QString roomID;
        QString title;
    }s;
	struct Output
	{
		QString Mode;
		struct Audio
		{
			int64_t TrackIndex;
			QString RecType;
			int64_t RecTracks;
			bool	FFOutputToFile;
			QString Bitrate;
			QString Keyframe;
			QString CPU;
			QString Profile;
			QString Tune;
		}a;
		struct Video
		{
			QString OutputCX;
			QString OutputCY;
			QString FPSType;
			QString FPSInt;
			QString ScaleType;
		}v;
	}o;
};

