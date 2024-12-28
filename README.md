# network-demo
little demo to test out server/client connections with C

(this only works on windows)

#

### Before using...
Clone the repository and build the project:
```bash
git clone https://github.com/kryllyxofficial01/network-demo.git && cd network-demo
```
```bash
make
```

### Running the Server
Use the following command:
```
.\build\network.exe server
```

This will create a local server at `127.0.0.1:*` with a random port (displayed upon success of the second command)

### Creating a Client
In a seperate CMD Prompt window, change into the project directory and run the following:
```bash
.\build\network.exe client <port>
```
Replace `<port>` with what the server command outputted, and upon success the server window should show the data that was sent

#

### Example Output (Server)
```
C:\Programming\Tests\network-demo>.\build\network.exe server
Winsock initialized

Setting up server socket ... Success

Server hosted on port 50469

received data:
        --- hello from a client ---
```

### Example Output (Client)
```
C:\Programming\Tests\network-demo>.\build\network.exe client 50469
Winsock initialized

Connecting to server at '127.0.0.1:50469' ... Success

Data to be sent: hello from a client
Sending data to server ... Success
```