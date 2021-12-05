## Compiling
Is necessary to install the qt5 default libraries and also to install the packages libqt5multimedia5, libqt5multimedia5-plugins and libqt5multimediawidgets5.

    sudo apt install libqt5multimedia5 libqt5multimedia5-plugins libqt5multimediawidgets5


## Running

To run this example you should provide a valid source url.

To generate a demo stream you could use the ffmpeg.


    ffmpeg -i <YOUR_VIDEO_MP4_FILE> -f mpegts udp://<YOUR_HOST_ADDRESS>:<HOST_PORT>

after that your video should been playing and you can run this example.

    ./play udp://<YOUR_HOST_ADDRESS>:<HOST_PORT>



`If any compability problems appers, you should try to install the gstreamer and it base,good and ugly plugins`
