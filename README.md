# Music Player with Doubly Linked List

This repository contains a C program that implements a basic music player using a doubly linked list data structure. The program provides a user-friendly command-line interface that enables users to manage a playlist of songs, leveraging fundamental concepts of data structures and programming.

## Features and Functionality

### 1. Adding Songs to the Playlist

Users can easily add songs to the playlist using the `add` command. The program utilizes dynamic memory allocation (`malloc`) to create a new node for each song. Users can choose to add a song to the end of the playlist or at the beginning. This feature showcases the concept of dynamic memory management.

### 2. Navigating Through the Playlist

The music player allows users to navigate through the playlist using the `next` and `prev` commands. The program keeps track of the current song being played and uses pointers to traverse the doubly linked list. This feature demonstrates the use of pointers and linked list traversal.

### 3. Removing Songs

Users can remove the currently playing song from the playlist using the `remove` command. The program adjusts the pointers of the adjacent nodes to remove the selected song. This illustrates the concept of linked list manipulation.

### 4. Displaying the Playlist

The `playlist` command displays the entire playlist of songs. Users can see the order of the songs, and the currently playing song is highlighted. This feature showcases the traversal of the entire linked list and displaying its contents.

### 5. Searching for Songs and Adding

The `search` command allows users to search for a song in the playlist. If the song is found, its position in the playlist is displayed. If the song is not found, the program prompts the user to add the song to the playlist. This demonstrates string comparison, conditional statements, and interactive user input.

### 6. Displaying the Currently Playing Song

Users can use the `display current song` command to see the details of the song currently being played. This showcases the retrieval and display of data stored in the linked list node.

### 7. Quitting the Music Player

The `quit` command gracefully exits the music player, displaying a thank-you message. This demonstrates the termination of the program loop.

## How to Use

1. Compile the C program using a C compiler such as GCC: `gcc music_player.c -o music_player`
2. Run the compiled executable: `./music_player`
3. Follow the on-screen instructions to interact with the music player.
4. Use the provided commands (`add`, `next`, `prev`, `remove`, `playlist`, `display current song`, `search`, `quit`) to manage your playlist.

## Contributing

Contributions to this project are highly appreciated. If you want to enhance the functionality, improve the user experience, or fix any issues, you can:

1. Fork the repository.
2. Create a new branch for your changes: `git checkout -b feature/new-feature`
3. Make your changes and commit them: `git commit -am 'Add new feature'`
4. Push your changes to your fork: `git push origin feature/new-feature`
5. Create a pull request, describing your changes in detail.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

Feel free to explore, use, and contribute to this music player project. Enjoy managing your playlist with ease using the doubly linked list-based music player!
