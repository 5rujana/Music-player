#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char song[100];
    struct node* next;
    struct node* prev;
};

// insert at end
// function for  adding a song
void add_song_to_playlist(struct node** head, struct node** tail, char song_name[], int current_song) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    strcpy(newnode->song, song_name);

    if (*head == NULL && *tail == NULL) {
        *head = *tail = newnode;
        newnode->next = newnode->prev = newnode;
    }
    else if (current_song <= 1) { // Insert at the beginning
        newnode->prev = *tail;
        (*tail)->next = newnode;
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
    }
    else {
        struct node* temp = *head;
        int count = 0;
        while (count < current_song - 1 && temp->next != *head) {
            temp = temp->next;
            count++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;

        if (temp == *tail) {
            *tail = newnode;
        }
    }
}

// function for  playing  previous song
void next(struct node** head, struct node** tail, int* current_song) {
    if (*head == NULL && *tail == NULL) {
        printf("No songs are present in the music player. Please download your favorite songs and listen offline.\n");
    }
    else {
        struct node* temp = *head;
        int pos = 0;
        while (pos < (*current_song) - 1) {
            temp = temp->next;
            pos++;
        }
        printf("Playing %s for you\n", temp->next->song);
        (*current_song)++;
    }
}

// function for  playing  next song
void prev(struct node** head, struct node** tail, int* current_song) {
    if (*head == NULL && *tail == NULL) {
        printf("No songs are present in the music player. Please download your favorite songs and listen offline.\n");
    }
    else {
        struct node* temp = *head;
        int pos = 0;
        while (pos < (*current_song) - 1) {
            temp = temp->next;
            pos++;
        }
        (*current_song)--;
        printf("Playing %s for you\n", temp->prev->song);
    }
}

//function for removing song
void remove_song_from_playlist(struct node** head, struct node** tail, int current_song) {
    if (*head == NULL && *tail == NULL) {
        printf("No songs are present in the music player, please download your favorite songs and listen offline.\n");
    }
    else if (*head == *tail) {
        struct node* temp = *head;
        *head = *tail = NULL;
        free(temp);
    }
    else {
        struct node* temp = *head;
        int pos = 0;
        while (pos < current_song-1) {
            temp = temp->next;
            pos++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp == *head) {
            *head = temp->next;
        }
        if (temp == *tail) {
            *tail = temp->prev;
        }
        free(temp);
    }
}

void display(struct node** head) {
    printf("Displaying your playlist\n");
    struct node* temp = *head;
    int count = 0;
    do {
        count++;
        printf("\n%d   %s\n", count, temp->song);
        temp = temp->next;
    } while (temp != *head);
}


//function for displaying currently playing song
void display_playing_song(struct node** head, struct node** tail, int current_song) {
    struct node* temp;
    temp = *head;
    if (*head == NULL && *tail == NULL) {
        printf("No songs are present in the music player, please download your favorite songs and listen offline.\n");
    }
    else {
        int pos = 0;
        while (pos < current_song - 1) {
            temp = temp->next;
            pos++;
        }
        printf("Playing %s for you\n", temp->song);
    }
}


//function for searching song
void searching_song(struct node** head, struct node** tail, char song_name1[], int current_song) {
    struct node* temp = *head;
    int count = 0;
    int flag = 0;
    do {
        count++;
        if (strcmp(temp->song, song_name1) == 0) {
            printf("%d  %s\n", count, song_name1);
            flag = 1;
        }
        temp = temp->next;

    } while (temp != *head);

    if (flag == 0) {
        char command[100];
        printf("Sorry! This song is not present in your playlist. Would you like to add this song to your playlist? ");
        fgets(command, sizeof(command), stdin);

        if (strcmp(command, "yes\n") == 0 || strcmp(command, "YES\n") == 0 || strcmp(command, "Yes\n") == 0) {
            song_name1[strcspn(song_name1, "\n")] = '\0'; // Remove newline character
            add_song_to_playlist(head, tail, song_name1, current_song);
            printf("%s is added to your playlist.\n", song_name1);
        }
    }
}

int main() {
    struct node* head = NULL;
    struct node* tail = NULL;
    char command[100];
    char song_name[100];
    int current_song = 0;

    printf("User manual:\nFacilities available:\n");
    printf("a) Add a song\nb) Remove current song\nc) Display current song\nd) Display playlist\ne) Search a song and add if not present\nf)next song\n g)previous song\nh) Quit\n\n");

    printf("Hi, welcome to the song player. What would you like to do?\n");

    while (1) {
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0'; // Remove newline character

        if (strcmp(command , "add")==0||strcmp(command,"ADD")==0||strcmp(command,"Add")==0||strcmp(command,"add song")==0||strcmp(command,"add the song")==0||strcmp(command,"ADD SONG")==0||strcmp(command,"ADD THE SONG")==0) {
            printf("Enter the song name to add: ");
            fgets(song_name, sizeof(song_name), stdin);
            song_name[strcspn(song_name, "\n")] = '\0'; // Remove newline character
            current_song++;
            add_song_to_playlist(&head, &tail, song_name, current_song);
            printf("%s is added to your playlist.\n", song_name);
        }
        else if (strcmp(command,"next")==0||strcmp(command,"Next")==0||strcmp(command,"NEXT")==0||strcmp(command,"next song")==0||strcmp(command,"NEXT SONG")==0||strcmp(command,"Next song")==0||strcmp(command,"play next song")==0||strcmp(command,"PLAY NEXT SONG")==0||strcmp(command,"Play next song")==0) {
            next(&head, &tail, &current_song);
        }
        else if (strcmp(command,"prev")==0||strcmp(command,"Prev")==0||strcmp(command,"PREV")==0||strcmp(command,"PREVIOUS")==0||strcmp(command,"Previous")==0||strcmp(command,"previous")==0||strcmp(command,"previous song")==0||strcmp(command,"PREVIOUS SONG")==0||strcmp(command,"Previous song")==0||strcmp(command,"play previous song")==0||strcmp(command,"PLAY PREVIOUS SONG")==0||strcmp(command,"Play previous song")==0) {
            prev(&head, &tail, &current_song);
        }
        else if (strcmp(command,"remove")==0||strcmp(command,"REMOVE")==0||strcmp(command,"REMOVE SONG")==0||strcmp(command,"remove song")==0||strcmp(command,"remove the song")==0||strcmp(command,"Remove the song")==0||strcmp(command,"REMOVE THE SONG")==0||strcmp(command,"Remove song")==0||strcmp(command,"Remove")==0) {
            printf("are you sure you want to remove this song from your playlist?\n");
                char desicion[100];
                 scanf("%s",desicion);
                if (strcmp(desicion,"yes")==0||strcmp(desicion,"YES")==0||strcmp(desicion,"Yes")==0)
                {
                    remove_song_from_playlist(&head,&tail,current_song); 
                    printf("Removed song from playlist\n ");
                }
        }
        else if (strcmp(command,"display the playlist")==0||strcmp(command,"playlist")==0||strcmp(command,"Display the playlist")==0||strcmp(command,"DISPLAY THE PLAYLIST")==0||strcmp(command,"Playlist")==0||strcmp(command,"PLAYLIST")==0||strcmp(command,"Display playlist")==0||strcmp(command,"DISPLAY PLAYLIST")==0||strcmp(command,"display playlist")==0) {
            display(&head);
        }
        else if (strcmp(command,"DISPLAY CURRENT SONG")==0||strcmp(command,"Display current song")==0||strcmp(command,"display current song")==0||strcmp(command,"display the song playing ")==0||strcmp(command,"DISPLAY THE SONG PLAYING")==0||strcmp(command,"Display the song playing")==0||strcmp(command,"display song")==0||strcmp(command,"Display song")==0||strcmp(command,"DISPLAY SONG")==0||strcmp(command,"DISPLAY THE SONG")==0||strcmp(command,"display the song")==0||strcmp(command,"Display the song")==0) {
            display_playing_song(&head, &tail, current_song);
        }
        else if (strcmp(command,"Search")==0||strcmp(command,"SEARCH")==0||strcmp(command,"search")==0||strcmp(command,"Search song")==0||strcmp(command,"search song")==0||strcmp(command,"SEARCH SONG")==0||strcmp(command,"Search the song")==0||strcmp(command,"SEARCH THE SONG")==0||strcmp(command,"search the song")==0||strcmp(command,"search song from play list")==0||strcmp(command,"Search song from playlist")==0||strcmp(command,"SEARCH SONG FROM PLAYLIST")==0) {
            printf("Enter the song name to search: ");
            fgets(song_name, sizeof(song_name), stdin);
            song_name[strcspn(song_name, "\n")] = '\0'; // Remove newline character
            searching_song(&head, &tail, song_name, current_song);
        }
        else if (strcmp(command,"quit")==0||strcmp(command,"QUIT")==0||strcmp(command,"Quit")==0) {
            printf("Thank you for using the song player. Have a nice day!\n");
            break;
        }
        else {
            printf("Sorry, I didn't understand that command. Please try again.\n");
        }
    }

    return 0;
}
