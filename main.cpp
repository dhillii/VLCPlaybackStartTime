
#include <vlc/vlc.h>
#include <thread>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
    libvlc_instance_t *my_instance;
    my_instance = libvlc_new(0, NULL);
    if(my_instance == NULL){
        printf("There was an error initializing VLC\n");
        exit(1);
    }
    else {
        printf("VLC initialized successfully\n");
    }

    libvlc_media_t *my_media_file;
    my_media_file = libvlc_media_new_path(my_instance, "/home/dhillii/Desktop/DriporDrown.mp3");

    // Create player
    libvlc_media_player_t *my_player;
    my_player = libvlc_media_player_new_from_media(my_media_file);

    libvlc_media_player_set_media(my_player, my_media_file);
    libvlc_media_player_play(my_player);
    libvlc_media_player_set_time(my_player, 30000);

    sleep(15);

    libvlc_media_release(my_media_file);
    libvlc_media_player_release(my_player);
    libvlc_release(my_instance);
    return 0;
}
