# Minitalk

Minitalk is a small data exchange program that allows communication between two processes using UNIX signals. The basic purpose is to send a string from the client to the server and for the server to display it.

## Installation

Clone the project files from GitHub:

    git clone https://github.com/menasy/Minitalk

Enter the project directory:

    cd Minitalk

Use the make command to compile the files:

    make

If you want to use bonus features, use the make bonus command:

    make bonus

## Usage

Open two terminal windows or split the terminal if you are using VSCode. In one terminal, run the ./server command:

    ./server

Write down the PID number of the server. In the other terminal run ./client with the PID number and the message you want to send:

    ./client PID_NO MESSAGE

If you use bonus features, use the ./server_bonus and ./client_bonus commands:

    ./server_bonus

    ./client_bonus PID_NO MESSAGE

Press control+c to terminate the server.
