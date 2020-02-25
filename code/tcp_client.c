#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {

  // create socket integer holds socket descriptor
  int networkSocket;
  networkSocket = socket(AF_INET, SOCK_STREAM, 0);

  // end point created
  // specify an address for the socket
  struct sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET; // family set
  // specify port
  serverAddress.sin_port = htons(9002);
  serverAddress.sin_addr.s_addr = INADDR_ANY;

  int connectionStatus =
    connect(networkSocket,
        (struct sockaddr *) &serverAddress, sizeof(serverAddress));

  // check for error in connection
  if (connectionStatus == -1) {
    printf("something went wrong in connection\n", );
  }

  // receive data from server
  char serverResponse[256];
  recv(networkSocket, &serverResponse, sizeof(serverResponse), 0); // data will be assigned to serverResponse

}
