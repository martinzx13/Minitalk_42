# Minitalk

Minitalk is a simple client-server communication program using UNIX signals. The project consists of a server and a client that can send and receive messages using `SIGUSR1` and `SIGUSR2` signals.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Bonus](#bonus)
- [Files](#files)
- [License](#license)

## Installation

To compile the project, run the following command in the root directory:

```sh
make
```

This will generate the following executables:

* `client`
* `server`
* `src_bonus/client_bonus`
* `src_bonus/server_bonus`

## Usage

### Server

To start the server, run:

```

./server
```


The server will print its PID, which you will need to provide to the client.

### Client

To send a message to the server, run:

```
./client <server_pid> <message>
```


Replace `<server_pid>` with the PID of the server and `<message>` with the message you want to send.

## Bonus

The bonus part of the project includes additional features such as:

* Enhanced signal handling.
* Additional error checking and handling.

To use the bonus features, run the following commands:

### Bonus Server

```
./src_bonus/server_bonus
```


### Bonus Client

./src_bonus/client_bonus <server_pid> `<message>`


## Files

* `Makefile`: Contains the build instructions for the project.
* `lib/minitalk.h`: Header file with function prototypes and macros.
* `src/client.c`: Source code for the client.
* `src/server.c`: Source code for the server.
* `src_bonus/client_bonus.c`: Source code for the bonus client.
* `src_bonus/server_bonus.c`: Source code for the bonus server.
* `utils/libft.c`: Utility functions used by both client and server.

## License

This project is licensed under the MIT License.
