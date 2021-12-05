#include <iostream>
#include <string>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtMultimedia/QMediaPlayer>
using namespace std;

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        cerr << "You should pass an valid URL,\n"<<"e.g.: udp://127.0.0.1:5000"<<endl;
        exit(0);
    }

    const string src_url = argv[1];

    QApplication app(argc,argv);
    
    QMainWindow main_window;

    main_window.setFixedSize(1280,720);
        
    QVideoWidget video_widget;
    
    main_window.setCentralWidget(&video_widget);

    QMediaPlayer * media_player = new QMediaPlayer(&video_widget,QMediaPlayer::VideoSurface);
    media_player->setMedia(QUrl(src_url.data()));
    
    media_player->play();

    media_player->setVideoOutput(&video_widget);
    
    video_widget.show();

     main_window.show();

    return app.exec();
}
