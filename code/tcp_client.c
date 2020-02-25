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
}
